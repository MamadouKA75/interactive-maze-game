
#include "voiture.h"

/**
 * @brief Constructeur de la classe Voiture.
 * @param vitesseInitiale La vitesse initiale de la voiture.
 * @param angleInitial L'angle initial de la direction dans laquelle la voiture se déplace.
 */
Voiture::Voiture(float vitesseInitiale, float angleInitial)
    : vitesse(vitesseInitiale), angle(angleInitial)
{
   
}

/**
 * @brief Accélère la voiture.
 * @param increment L'incrément de la vitesse.
 */
void Voiture::accelerer(float increment)
{
    vitesse += increment;
}

/**
 * @brief Freine la voiture.
 * @param decrement Le décrément de la vitesse.
 */
void Voiture::freiner(float decrement)
{
    vitesse -= decrement;
    if(vitesse < 0) {
        vitesse = 0;
    }
}

/**
 * @brief Tourne la voiture.
 * @param nouvelAngle Le nouvel angle de la direction dans laquelle la voiture doit se déplacer.
 */
void Voiture::tourner(float nouvelAngle)
{
    angle = nouvelAngle;
   
}

/**
 * @brief Renvoie la vitesse actuelle de la voiture.
 * @return La vitesse actuelle de la voiture.
 */
float Voiture::getVitesse() const
{
    return vitesse;
}

/**
 * @brief Modifie la vitesse actuelle de la voiture.
 * @param nouvelleVitesse La nouvelle vitesse de la voiture.
 */
void Voiture::setVitesse(float nouvelleVitesse)
{
    vitesse = nouvelleVitesse;
}

/**
 * @brief Renvoie l'angle de la direction dans laquelle la voiture se déplace.
 * @return L'angle de la direction dans laquelle la voiture se déplace.
 */
float Voiture::getAngle() const
{
    return angle;
}

/**
 * @brief Modifie l'angle de la direction dans laquelle la voiture se déplace.
 * @param nouvelAngle Le nouvel angle de la direction dans laquelle la voiture doit se déplacer.
 */
void Voiture::setAngle(float nouvelAngle)
{
    angle = nouvelAngle;
}
