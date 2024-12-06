#include "JeuDeLaVie.h"
#include <iostream>
#include <thread>
#include <chrono>

// Constructor for interactive simulation with SFML
JeuDeLaVie::JeuDeLaVie(int largeur, int hauteur, float iterationTime)
    : grille(largeur, hauteur), iterationTime(iterationTime), simulationLancee(false) {
    window.create(sf::VideoMode(largeur * 20, hauteur * 20), "Jeu de la Vie");
}

// Constructor for running a simulation from a file
JeuDeLaVie::JeuDeLaVie(const std::string& cheminFichier, int iterations)
    : grille(0, 0), iterationsMax(iterations) {
    grille.chargerDepuisFichier(cheminFichier);
}

// Method to handle mouse clicks and toggle cell states
void JeuDeLaVie::gererClicSouris(const sf::Vector2i& position) {
    if (simulationLancee) return;

    int cellWidth = 20;
    int cellHeight = 20;
    int x = position.x / cellWidth;
    int y = position.y / cellHeight;

    bool nouvelEtat = !grille.estVivante(x, y);
    grille.setEtat(x, y, nouvelEtat);
}

// Method to start the simulation with SFML window
void JeuDeLaVie::demarrerSimulation() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                gererClicSouris(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                simulationLancee = true;
            }
        }

        if (simulationLancee && clock.getElapsedTime().asSeconds() >= iterationTime) {
            grille.calculerProchaineGeneration();
            clock.restart();
        }

        window.clear();
        afficherGrille();
        window.display();
    }
}

// Method to execute the simulation with file-based output
void JeuDeLaVie::executer(const std::string& fichierSortie) {
    std::cout << "État initial :\n";
    grille.afficher();

    for (int it = 0; it < iterationsMax; ++it) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\n--- Itération " << it + 1 << " ---\n";
        grille.miseAJour();
        grille.afficher();
    }

    std::cout << "\nSimulation terminée après " << iterationsMax << " itérations.\n";
    grille.sauvegarderDansFichier(fichierSortie);
}

// Method to display the grid in SFML window
void JeuDeLaVie::afficherGrille() {
    int cellWidth = 20;
    int cellHeight = 20;

    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            sf::RectangleShape cell(sf::Vector2f(cellWidth, cellHeight));
            cell.setPosition(x * cellWidth, y * cellHeight);
            cell.setFillColor(grille.estVivante(x, y) ? sf::Color::Green : sf::Color::White);
            window.draw(cell);
        }
    }
}
