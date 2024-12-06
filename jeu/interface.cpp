#include "Interface.h"

InterfaceGraphique::InterfaceGraphique(JeuDeLaVie& jeu) : jeu(jeu), window(sf::VideoMode(800, 600), "Jeu de la Vie") {
    window.setFramerateLimit(30);
}

bool InterfaceGraphique::isWindowOpen() const {
    return window.isOpen();
}

void InterfaceGraphique::afficherGrille(const Grille& grille) {
    window.clear(sf::Color::Black);

    int largeur = grille.getLargeur();
    int hauteur = grille.getHauteur();

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(x * cellSize, y * cellSize);

            if (grille.estVivante(x, y)) {
                cell.setFillColor(sf::Color::Green);
            }
            else {
                cell.setFillColor(sf::Color::Black);
            }

            window.draw(cell);
        }
    }

    window.display();
}

void InterfaceGraphique::traiterEvenements() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

