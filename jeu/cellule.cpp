#include "Cellule.h"

// Constructor for a single cell (Cellule)
Cellule::Cellule(bool etat) : vivante(etat) {}

// Method to check if the cell is alive
bool Cellule::estVivante() const {
    return vivante;
}

// Method to set the state of the cell
void Cellule::setVivante(bool etat) {
    vivante = etat;
}

// Constructor for creating a grid of cells
Cellule::Cellule(int largeur, int hauteur, bool etat) {
    grille.resize(hauteur, std::vector<Cellule>(largeur, Cellule(etat)));
}

// Method to get the grid's width
int Cellule::getLargeur() const {
    return grille.empty() ? 0 : grille[0].size();
}

// Method to get the grid's height
int Cellule::getHauteur() const {
    return grille.size();
}

// Method to set a specific cell's state in the grid
void Cellule::setCellule(int x, int y, bool etat) {
    if (y >= 0 && y < getHauteur() && x >= 0 && x < getLargeur()) {
        grille[y][x].setVivante(etat);
    }
}

// Method to get a specific cell's state from the grid
bool Cellule::getCellule(int x, int y) const {
    if (y >= 0 && y < getHauteur() && x >= 0 && x < getLargeur()) {
        return grille[y][x].estVivante();
    }
    return false; // Default value for out-of-bound indices
}
