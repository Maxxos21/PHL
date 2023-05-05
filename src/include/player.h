#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* loadPlayerImage(SDL_Renderer* renderer);
void renderPlayer(SDL_Renderer* renderer, SDL_Texture* playerTexture, int x, int y, int width, int height);

#endif /* PLAYER_H */