#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "JeuDeLaVie.h"

class InterfaceGraphique {
private:
    sf::RenderWindow window;
    JeuDeLaVie& jeu;
    const int cellSize = 20;

public:
    InterfaceGraphique(JeuDeLaVie& jeu);
    bool isWindowOpen() const;
    void afficherGrille(const Grille& grille);
    void traiterEvenements();
};

#endif // INTERFACEGRAPHIQUE_H

