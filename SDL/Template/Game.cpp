//
//  Game.cpp
//  Template
//
//  Created by Jeremy on 11/21/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"

Game::Game():mWindow(nullptr), mRenderer(nullptr), mIsRunning(true) {
    
}

bool Game::Init() {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    mWindow = SDL_CreateWindow("Window", 100, 100, 1024, 768, 0);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
    return true;
}

void Game::Update() {
    while (mIsRunning) {
        Events();
        SDL_SetRenderDrawColor(mRenderer, 0, 255, 255, 255);
        SDL_RenderClear(mRenderer);
        SDL_RenderPresent(mRenderer);
    }
}

void Game::Events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }
}
void Game::Quit() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
    IMG_Quit();
}
