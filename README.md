[readme.txt.txt](https://github.com/user-attachments/files/18049113/readme.txt.txt)Jeu de la Vie en Programmation Orientée Objet (POO)
Description
Le Jeu de la Vie est un automate cellulaire inventé par le mathématicien John Conway. Il s'agit d'un jeu sans joueur, où une population de cellules vit sur une grille à deux dimensions, suivant des règles simples mais produisant des comportements complexes.

Dans ce projet, nous avons implémenté le Jeu de la Vie en utilisant la Programmation Orientée Objet (POO) en C++. Chaque cellule de la grille est un objet, et la grille elle-même est composée d'objets représentant des cellules vivantes ou mortes.

Règles du jeu :
Sous-population : Une cellule vivante avec moins de deux voisines vivantes meurt.
Survie : Une cellule vivante avec deux ou trois voisines vivantes survit.
Surpopulation : Une cellule vivante avec plus de trois voisines vivantes meurt.
Reproduction : Une cellule morte avec exactement trois voisines vivantes devient une cellule vivante.

Fonctionnalités
Simulation d'une grille dynamique : À chaque itération, les cellules de la grille évoluent selon les règles définies.
Conception en POO : Le projet est structuré avec des classes représentant les cellules et la grille, facilitant l'extension et la maintenance.
Affichage : L'évolution des générations peut être affichée dans le terminal ou à l'aide d'une bibliothèque graphique (optionnelle, selon la configuration).
Configuration initiale : L'utilisateur peut définir l'état initial des cellules sur la grille.
Démarrage/arrêt de la simulation : L'utilisateur peut démarrer ou arrêter la simulation à tout moment.

Installation
Prérequis
Système d'exploitation : MacOS, Linux, ou Windows
Compilateur : G++ ou Clang
Bibliothèque graphique (facultatif) : SFML (si utilisé pour l'affichage graphique)

Étapes d'installation
Clonez le projet depuis GitHub :```bash
git clone https://github.com/ADEMO699/Livrable.git
