//
//  Game.cpp
//  SDLGL_CrossOver
//
//  Created by Jeremy on 12/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"
#include "Renderer.hpp"

Game::Game():mWindow(nullptr), mRenderer(nullptr), mIsRunning(true) {
    
}

bool Game::Init() {
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    // Use the core OpenGL profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    // Specify version 3.3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    // Request a color buffer with 8-bits per RGBA channel
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    // Enable double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // Force OpenGL to use hardware acceleration
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    mWindow = SDL_CreateWindow("Window", 100, 100, 1024, 768, SDL_WINDOW_OPENGL);
    mContext = SDL_GL_CreateContext(mWindow);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        SDL_Log("Failed to initialize GLEW.");
        return false;
    }
    // On some platforms, GLEW will emit a benign error code,
    // so clear it
    glGetError();
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
    SDL_GL_DeleteContext(mContext);
}
