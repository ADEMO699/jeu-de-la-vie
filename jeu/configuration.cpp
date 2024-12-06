#include "Configuration.h"

Configuration::Configuration(int largeur, int hauteur, float tempsIter,
    const std::string& fichierCharge,
    const std::string& fichierSauve)
    : largeurGrille(largeur), hauteurGrille(hauteur), tempsIteration(tempsIter),
    fichierChargement(fichierCharge), fichierSauvegarde(fichierSauve) {
}

int Configuration::getLargeurGrille() const {
    return largeurGrille;
}

int Configuration::getHauteurGrille() const {
    return hauteurGrille;
}

float Configuration::getTempsIteration() const {
    return tempsIteration;
}

std::string Configuration::getFichierChargement() const {
    return fichierChargement;
}

std::string Configuration::getFichierSauvegarde() const {
    return fichierSauvegarde;
}

void Configuration::setLargeurGrille(int largeur) {
    largeurGrille = largeur;
}

void Configuration::setHauteurGrille(int hauteur) {
    hauteurGrille = hauteur;
}

void Configuration::setTempsIteration(float temps) {
    tempsIteration = temps;
}

void Configuration::setFichierChargement(const std::string& fichier) {
    fichierChargement = fichier;
}

void Configuration::setFichierSauvegarde(const std::string& fichier) {
    fichierSauvegarde = fichier;
}

