#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Grille.h"

class JeuDeLaVie {
private:
    Grille grille;
    sf::RenderWindow window;
    sf::Clock clock;
    float iterationTime;
    bool simulationLancee;
    int iterationsMax;

public:
    // Constructor for interactive simulation with SFML
    JeuDeLaVie(int largeur, int hauteur, float iterationTime);

    // Constructor for running a simulation from a file
    JeuDeLaVie(const std::string& cheminFichier, int iterations);

    // Method to handle mouse clicks
    void gererClicSouris(const sf::Vector2i& position);

    // Method to start the simulation with SFML window
    void demarrerSimulation();

    // Method to execute simulation with file-based output
    void executer(const std::string& fichierSortie);

    // Method to display the grid in SFML window
    void afficherGrille();
};

#endif // JEUDELAVIE_H
