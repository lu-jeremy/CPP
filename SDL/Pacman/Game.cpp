#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;

using namespace std;

Game::Game() {
    
}
Game::~Game() {
    
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        
        IMG_Init(IMG_INIT_PNG);
        
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        }
        
        isRunning = true;
    }
    player = new GameObject("/Users/Jeremy/Desktop/C++/SDL/SDL_Test/SDL_Test/pacman.png", renderer, 0, 0);
}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::update() {
    player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}
