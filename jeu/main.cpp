#include "JeuDeLaVie.h"
#include <iostream>

int main() {
    // Ask the user for the mode they want to run
    std::cout << "welcome to my game now  Choisir le mode:\n";
    std::cout << "1 - Mode console \n";
    std::cout << "2 - Mode graphique\n";
    int choixMode;
    std::cin >> choixMode;

    if (choixMode == 1) {
        // Mode Console
        std::string fichierEntree = "input.txt";
        std::string fichierSortie = "resultat.txt";
        int nombreIterations = 100; // Nombre d'itérations à effectuer

        // Créer un objet JeuDeLaVie en mode console
        JeuDeLaVie jeu(fichierEntree, nombreIterations);
        jeu.executer(fichierSortie);  // Exécuter la simulation et sauvegarder les résultats
    }
    else if (choixMode == 2) {
        // Mode Graphique
        JeuDeLaVie jeu(40, 40, 0.5f);  // Taille de la grille et temps d'itération
        jeu.demarrerSimulation();      // Démarrer la simulation graphique
    }
    else {
        std::cout << "Choix invalide! Le programme va se terminer.\n";
    }

    return 0;
}
