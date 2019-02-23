//
//  Game.cpp
//  Template
//
//  Created by Jeremy on 11/21/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"
#include "Ship.hpp"

Game::Game():mWindow(nullptr), mRenderer(nullptr), mIsRunning(true) {
    
}

bool Game::Init() {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    mWindow = SDL_CreateWindow("Window", 100, 100, 1280, 800, 0);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
    IMG_Init(IMG_INIT_PNG);
    mShip = new Ship(this);
    return true;
}

void Game::Update() {
    while (mIsRunning) {
        Events();
        SDL_SetRenderDrawColor(mRenderer, 75, 0, 130, 255);
        SDL_RenderClear(mRenderer);
        mShip->Draw(mRenderer);
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
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        mIsRunning = false;
    }
    mShip->GetKeyboardState(state);
}

void Game::Quit() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
    IMG_Quit();
}

SDL_Texture* Game::GetTexture(const std::string& FILENAME) {
    SDL_Surface* tempSurface = IMG_Load(FILENAME.c_str());
    SDL_Texture* permTexture = SDL_CreateTextureFromSurface(mRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return permTexture;
}

