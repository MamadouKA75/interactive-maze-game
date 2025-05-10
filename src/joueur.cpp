
#include<iostream>

using namespace std;

#include "Voiture.h"





Voiture::Voiture(){

marque = "RaMaLa";

vitesse = 0.0;

}



Voiture::Voiture(const string& Marque , float Vitesse){

this -> marque = Marque; // marque a droite reprensente la variable de la fonction

this -> vitesse = Vitesse;

}



Voiture ::~Voiture(){

}



string Voiture::getMarque(){

return marque;

}



float Voiture::getVitesse(){

return vitesse;

}





void Voiture::afficher(){

cout << "Marque : " << marque << endl;

cout << "Vitesse : " << vitesse << endl;

}





void Voiture::setVitesse(float Vitesse){

vitesse = Vitesse;

}

void Voiture::testVoiture() {

// Test du constructeur par défaut

Voiture voiture1;

assert(voiture1.getMarque() == "RaMaLa");

assert(voiture1.getVitesse() == 0.0);



// Test du constructeur avec paramètres

Voiture voiture2("Ford", 80.0);

assert(voiture2.getMarque() == "Ford");

assert(voiture2.getVitesse() == 80.0);



// Test du setter et du getter pour la vitesse

voiture1.setVitesse(50.0);

assert(voiture1.getVitesse() == 50.0);



// Test du getter pour la marque

assert(voiture2.getMarque() == "Ford");

}
