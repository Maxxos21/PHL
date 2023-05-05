#include "player.h"
#include <iostream>

SDL_Texture* loadPlayerImage(SDL_Renderer* renderer)
{
    // Load the knight png image
    SDL_Surface* surface = IMG_Load("assets/Knight.png");
    if (surface == NULL) 
    {
        std::cout << "Could not load player image: " << IMG_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Create an SDL_Texture from the SDL_Surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) 
    {
        std::cout << "Could not create texture from surface: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        exit(EXIT_FAILURE);
    }

    // Free the SDL_Surface since it is no longer needed
    SDL_FreeSurface(surface);

    return texture;
}

void renderPlayer(SDL_Renderer* renderer, SDL_Texture* playerTexture, int x, int y, int width, int height)
{
    // Define the area of the sprite sheet to render
    SDL_Rect srcRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 100;
    srcRect.h = 200;

    // Define the destination rectangle where the sprite sheet will be rendered
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;

    // Render the sprite sheet
    SDL_RenderCopy(renderer, playerTexture, &srcRect, &destRect);
}