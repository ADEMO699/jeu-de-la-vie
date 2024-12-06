#include "Grille.h"

// Constructor for a single cell
Grille::Grille(bool etat) : vivante(etat) {}

// Method to check if the cell is alive
bool Grille::estVivante() const {
    return vivante;
}

// Method to set the state of the cell
void Grille::setVivante(bool etat) {
    vivante = etat;
}

// Constructor for creating a grid of cells
Grille::Grille(int l, int h) : largeur(l), hauteur(h) {
    grille.resize(hauteur, std::vector<Grille>(largeur));
}

// Method to get the grid's width
int Grille::getLargeur() const {
    return largeur;
}

// Method to get the grid's height
int Grille::getHauteur() const {
    return hauteur;
}

// Method to set a specific cell's state in the grid
void Grille::setEtat(int x, int y, bool etat) {
    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        grille[y][x].setVivante(etat);
    }
}

// Method to get a specific cell's state from the grid
bool Grille::estVivante(int x, int y) const {
    int toricX = (x + largeur) % largeur;
    int toricY = (y + hauteur) % hauteur;
    return grille[toricY][toricX].estVivante();
}

// Method to calculate the next generation of cells
void Grille::calculerProchaineGeneration() {
    std::vector<std::vector<Grille>> nouvelleGrille(hauteur, std::vector<Grille>(largeur));

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int voisinsVivants = 0;

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dy == 0 && dx == 0) continue;
                    if (estVivante(x + dx, y + dy)) {
                        voisinsVivants++;
                    }
                }
            }

            bool celluleVivante = estVivante(x, y);
            if (celluleVivante && (voisinsVivants == 2 || voisinsVivants == 3)) {
                nouvelleGrille[y][x].setVivante(true);
            }
            else if (!celluleVivante && voisinsVivants == 3) {
                nouvelleGrille[y][x].setVivante(true);
            }
            else {
                nouvelleGrille[y][x].setVivante(false);
            }
        }
    }
    grille = std::move(nouvelleGrille);
}

// Method to load the grid from a file
void Grille::chargerDepuisFichier(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        exit(1);
    }

    fichier >> hauteur >> largeur;
    grille.resize(hauteur, std::vector<Grille>(largeur));

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int etat;
            fichier >> etat;
            grille[i][j].setVivante(etat == 1);
        }
    }

    fichier.close();
}

// Method to save the grid to a file
void Grille::sauvegarderDansFichier(const std::string& cheminFichier) const {
    std::ofstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << " pour écrire." << std::endl;
        exit(1);
    }

    fichier << hauteur << " " << largeur << "\n";
    for (const auto& ligne : grille) {
        for (const auto& cellule : ligne) {
            fichier << (cellule.estVivante() ? 1 : 0) << " ";
        }
        fichier << "\n";
    }

    fichier.close();
}

// Method to display the grid
void Grille::afficher() const {
    for (const auto& ligne : grille) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule.estVivante() ? "1 " : "0 ");
        }
        std::cout << "\n";
    }
}

// Helper function to count the number of living neighbors of a cell
int Grille::compterVoisinsVivants(int x, int y) const {
    int voisinsVivants = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < hauteur && ny >= 0 && ny < largeur) {
                voisinsVivants += grille[nx][ny].estVivante();
            }
        }
    }

    return voisinsVivants;
}

// Method to update the grid (for example, to the next generation)
void Grille::miseAJour() {
    std::vector<std::vector<Grille>> nouvelleGrille = grille;

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j);

            if (grille[i][j].estVivante()) {
                if (voisinsVivants < 2 || voisinsVivants > 3) {
                    nouvelleGrille[i][j].setVivante(false);
                }
            }
            else {
                if (voisinsVivants == 3) {
                    nouvelleGrille[i][j].setVivante(true);
                }
            }
        }
    }

    grille = nouvelleGrille;
}
