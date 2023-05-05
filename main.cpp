#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"
#include "spike.h"

// Window dimensions
const int SCREEN_WIDTH = 1260;
const int SCREEN_HEIGHT = 840;

// Global variables
SDL_Window* globalWindow = NULL;
SDL_Renderer* globalRenderer = NULL;
bool globalFullScreen = false;

// Player variables
int playerX = 0;
int playerY = 0;
int playerSpeed = 1;

void initializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void createWindow()
{
    globalWindow = SDL_CreateWindow("PHL Collective \"game\"", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    
    if (globalWindow == NULL)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    
    globalRenderer = SDL_CreateRenderer(globalWindow, -1, SDL_RENDERER_ACCELERATED);

    if (globalRenderer == NULL)
    {
        std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(globalWindow);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

void updatePlayer(int& playerX, int& playerY, int playerSpeed)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

    //! TODO - Get delta time to make movement framerate independent

    if (keyboardState[SDL_SCANCODE_W] && playerY > 0)
    {
        playerY -= playerSpeed;
    }
    if (keyboardState[SDL_SCANCODE_S] && playerY < SCREEN_HEIGHT - 200)
    {
        playerY += playerSpeed;
    }
    if (keyboardState[SDL_SCANCODE_A] && playerX > 0)
    {
        playerX -= playerSpeed;
    }
    if (keyboardState[SDL_SCANCODE_D] && playerX < SCREEN_WIDTH - 100)
    {
        playerX += playerSpeed;
    }

    //TODO: Check for collision with spikes

    //TODO: Check if player is on the right side of the screen

}

void drawRectangles(SDL_Renderer* renderer)
{
    //* Draw the start rectangles *//
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

    SDL_Rect leftRect;
    leftRect.x = 0;
    leftRect.y = 0;
    leftRect.w = SCREEN_WIDTH / 8;
    leftRect.h = SCREEN_HEIGHT;

    SDL_RenderFillRect(renderer, &leftRect);

    //* Draw the end rectangles *//
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);

    SDL_Rect rightRect;
    rightRect.x = SCREEN_WIDTH - SCREEN_WIDTH / 8;
    rightRect.y = 0;
    rightRect.w = SCREEN_WIDTH / 8;
    rightRect.h = SCREEN_HEIGHT;

    SDL_RenderFillRect(renderer, &rightRect);
}

void runMainLoop()
{
    SDL_Event event;
    bool quit = false;

    // Load textures
    SDL_Texture* playerTexture = loadPlayerImage(globalRenderer);
    SDL_Texture* spikeTexture = loadSpikeImage(globalRenderer);

    while (!quit)
    {
        // Handle events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
        }

        // Clear the screen + set background color
        SDL_SetRenderDrawColor(globalRenderer, 0, 0, 0, 255);
        SDL_RenderClear(globalRenderer);

        // Draw start/end rectangles
        drawRectangles(globalRenderer);

        // Update and render the player
        updatePlayer(playerX, playerY, playerSpeed);
        renderPlayer(globalRenderer, playerTexture, playerX, playerY, 100, 200);

        //TODO - refactor into a function
        for (int i = 0; i < 10; i++)
        {
            if (i != 5 && i != 6) 
            {
                renderSpike(globalRenderer, spikeTexture, SCREEN_WIDTH/2, i * 100, 100, 100);
            }
        }

        for (int i = 0; i < 10; i++)
        {
            if (i != 2 && i != 3)
            {
                renderSpike(globalRenderer, spikeTexture, SCREEN_WIDTH/4, i * 100, 100, 100);
            }
        }
        //TODO - refactor into a function

        // Show rendered content on screen
        SDL_RenderPresent(globalRenderer);
    }

    // Clean up resources
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(spikeTexture);

}

int main(int argc, char* args[])
{
    initializeSDL();
    createWindow();
    runMainLoop();
    SDL_DestroyRenderer(globalRenderer);
    SDL_DestroyWindow(globalWindow);
    SDL_Quit();
    return EXIT_SUCCESS;
}
