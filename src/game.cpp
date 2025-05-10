 
#include <iostream>
#include <SDL2/SDL.h>
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

Game::Game() {
    window_ = nullptr;
    renderer_ = nullptr;
    is_running_ = false;
}

void Game::Initialize() {
    // Initialiser SDL
    SDL_Init(SDL_INIT_VIDEO);
    window_ = SDL_CreateWindow("Jeu de Course", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

    // Initialiser les objets du jeu
    voiture_.Init(renderer_);
    joueur_.Init();
    piste_.Init(renderer_);

    is_running_ = true;
}

void Game::ProcessEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            is_running_ = false;
        }

        // Gérer les événements du joueur
        joueur_.HandleEvent(event);
    }
}

void Game::Update() {
    // Mettre à jour les objets du jeu
    voiture_.Update();
    joueur_.Update();
}

void Game::Render() {
    // Effacer le rendu précédent
    SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer_);

    // Rendre les objets du jeu
    piste_.Render(renderer_);
    voiture_.Render(renderer_);
    joueur_.Render(renderer_);

    // Mettre à jour l'affichage
    SDL_RenderPresent(renderer_);
}

void Game::Quit() {
    // Libérer les ressources SDL
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void Game::Run() {
    Initialize();

    while (is_running_) {
        ProcessEvents();
        Update();
        Render();
    }

    Quit();
}

int main(int argc, char* args[]) {
    Game game;
    game.Run();

    return 0;
}
