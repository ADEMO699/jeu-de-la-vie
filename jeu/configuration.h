#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>

class Configuration {
private:
    int largeurGrille;
    int hauteurGrille;
    float tempsIteration;
    std::string fichierChargement;
    std::string fichierSauvegarde;

public:
    Configuration(int largeur = 20, int hauteur = 20, float tempsIter = 0.5f,
        const std::string& fichierCharge = "",
        const std::string& fichierSauve = "");

    int getLargeurGrille() const;
    int getHauteurGrille() const;
    float getTempsIteration() const;
    std::string getFichierChargement() const;
    std::string getFichierSauvegarde() const;

    void setLargeurGrille(int largeur);
    void setHauteurGrille(int hauteur);
    void setTempsIteration(float temps);
    void setFichierChargement(const std::string& fichier);
    void setFichierSauvegarde(const std::string& fichier);
};

#endif // CONFIGURATION_H


