#ifndef SPIKE_H
#define SPIKE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* loadSpikeImage(SDL_Renderer* renderer);
void renderSpike(SDL_Renderer* renderer, SDL_Texture* spikeTexture, int x, int y, int width, int height);

#endif /* SPIKE_H */