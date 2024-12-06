#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Grille {
private:
    bool vivante;  // State of the cell
    std::vector<std::vector<Grille>> grille;  // Grid of cells
    int largeur;  // Width of the grid
    int hauteur;  // Height of the grid

public:
    // Constructor for a single cell
    Grille(bool etat = false);

    // Methods for a single cell
    bool estVivante() const;
    void setVivante(bool etat);

    // Constructor for creating a grid of cells
    Grille(int l, int h);

    // Methods for the grid
    int getLargeur() const;
    int getHauteur() const;
    void setEtat(int x, int y, bool etat);
    bool estVivante(int x, int y) const;
    void calculerProchaineGeneration();

    // Methods for file operations
    void chargerDepuisFichier(const std::string& cheminFichier);
    void sauvegarderDansFichier(const std::string& cheminFichier) const;
    void afficher() const;

    // Helper function for counting living neighbors
    int compterVoisinsVivants(int x, int y) const;
    void miseAJour();
};

#endif // GRILLE_H
