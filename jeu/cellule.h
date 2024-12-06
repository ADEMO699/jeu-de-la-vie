#ifndef CELLULE_H
#define CELLULE_H

#include <vector>

class Cellule {
private:
    bool vivante;  // State of the cell
    std::vector<std::vector<Cellule>> grille;  // Grid of cells

public:
    // Constructor for a single cell (Cellule)
    Cellule(bool etat = false);

    // Methods for a single cell
    bool estVivante() const;
    void setVivante(bool etat);

    // Constructor for creating a grid of cells
    Cellule(int largeur, int hauteur, bool etat = false);

    // Methods for the grid
    int getLargeur() const;
    int getHauteur() const;
    void setCellule(int x, int y, bool etat);
    bool getCellule(int x, int y) const;
};

#endif // CELLULE_H
