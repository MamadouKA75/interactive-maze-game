#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "voiture.h"
#include "joueur.h"
#include "piste.h"

class Game {
public:
    Game(); // Constructeur
    void Run(); // Fonction principale pour exécuter le jeu

private:
    SDL_Window* window_; // Fenêtre SDL
    SDL_Renderer* renderer_; // Rendu SDL
    Voiture voiture_; // Instance de la classe Voiture
    Joueur joueur_; // Instance de la classe Joueur
    Piste piste_; // Instance de la classe Piste
    bool is_running_; // Indicateur si le jeu est en cours d'exécution

    void Initialize(); // Initialiser le jeu
    void ProcessEvents(); // Traiter les événements
    void Update(); // Mettre à jour le jeu
    void Render(); // Rendre le jeu
    void Quit(); // Quitter le jeu
};

#endif // GAME_H
