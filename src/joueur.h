#include<iostream>

using namespace std;

#ifndef VOITURE_H

#define VOITURE_H



class Voiture{

private:

string marque;/**@param marque est un parametre de type string*/

float vitesse;/**@param Vitesse est un parametre de type float */



public:

/**Constructeur par defaut*/

Voiture();



/**constructeur avec des parametre*/

Voiture(const string& marque , float vitesse);



/**le destructeur de la classe */

~Voiture();



/**Accesseur*/



/**Accesseur : Permet de recupere la marque de la voiture */

string getMarque();



/**Accesseur:Permet de recupere la vitesse de la voiture */

float getVitesse();



/**Mutateur*/



/**Mutateur : permet de modifier le vitesse de la voiture*/

void setVitesse(float vitesse);



void testVoiture();



void afficher();



};
