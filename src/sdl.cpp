#include <SDL2/SDL.h>
#include "Piste.h"
#include "voiture.h"
// Fonction principale
int main(int argc, char* argv[]) {
    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Ma fenêtre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    // Création du renderer pour afficher les images
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Chargement de l'image de la sprite
    SDL_Surface* spriteSurface = SDL_LoadBMP("sprite.bmp");
    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);

    // Position de la sprite à l'écran
    SDL_Rect spriteRect;
    spriteRect.x = 0;
    spriteRect.y = 0;
    spriteRect.w = 32; // Largeur de la sprite
    spriteRect.h = 32; // Hauteur de la sprite

    // Boucle principale du jeu
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
                
            }
            if (event.type == SDL_KEYDOWN) {
                // Gestion du déplacement de la sprite avec les touches fléchées
                if (event.key.keysym.sym == SDLK_UP) {
                    spriteRect.y -= 5; // Déplacement vers le haut
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    spriteRect.y += 5; // Déplacement vers le bas
                }
                if (event.key.keysym.sym == SDLK_LEFT) {
                    spriteRect.x -= 15; // Déplacement vers la gauche
                }
                if (event.key.keysym.sym == SDLK_RIGHT) {
                    spriteRect.x += 5; // Déplacement vers la droite
                }
        

            }

        }
         
        // Effacement de l'écran
        SDL_RenderClear(renderer);

        // Mise à jour de la position de la sprite
         spriteRect.x += 1; // Déplacement horizontal de la sprite

        // Affichage de la sprite
        SDL_RenderCopy(renderer, spriteTexture, NULL, &spriteRect);

        // Affichage du rendu à l'écran
        SDL_RenderPresent(renderer);

        // Délai pour contrôler la vitesse de déplacement de la sprite
        SDL_Delay(16); // 60 images par seconde (1000ms / 60 = 16.6667ms)
    }

    // Libération des ressources
    SDL_DestroyTexture(spriteTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
