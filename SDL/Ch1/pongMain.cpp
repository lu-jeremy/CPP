//
//  main.cpp
//  SDL_Development
//
//  Created by Jeremy on 10/19/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


using namespace std;

class Game {
public:
    void Init();
    void gameLoop();
    void Quit();
    bool runningSuccess() {return isRunning;}
    const int thickness = 15;
    Uint32 ticksCount = 0;
    const float paddleH = 100.0f;
    int paddleDir = 0;
    struct ballPos {
        float x = 1024.0f/2.0f;
        float y = 600.0f/2.0f;
    } ball_pos;
    struct ballVel {
        float x = -200.0f;
        float y = 235.0f;
    } ball_vel;
    struct paddlePos {
        float x = 10.0f;
        float y = 600.0f/2.0f;
    } paddle_pos;
private:
    void handleEvents();
    void Update();
    void Render();
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};


void Game::Init() {
    int sdlInit = SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Window", 100, 100, 1024, 600, 0);
    if (sdlInit != 0) {
        isRunning = false;
    }
    if (!window) {
        isRunning = false;
    }
    isRunning = true;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Game::gameLoop() {
    while (isRunning) {
        handleEvents();
        Update();
        Render();
    }
    
}

void Game::Quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::handleEvents() {
    // if event.type is sdlquit, then program is not running
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
        }
    }
    
    //what keys are pressed
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_DELETE]) {
        isRunning = false;
    }
    if (state[SDL_SCANCODE_UP]) {
        paddleDir = -1;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        paddleDir = 1;
    }
}

void Game::Render() {
    SDL_Rect paddle {
        //cast float into int because SDL_Rect cannot take floats
        static_cast<int>(paddle_pos.x),
        static_cast<int>(paddle_pos.y),
        thickness,
        100
    };
    SDL_Rect ball {
        static_cast<int>(ball_pos.x - thickness/2),
        static_cast<int>(ball_pos.y - thickness/2),
        thickness,
        thickness
    };
                                //   R G   B     A
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &paddle);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &ball);
    SDL_RenderPresent(renderer);
}

void Game::Update() {
    int diff = abs(ball_pos.y - paddle_pos.y);
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16));
    
    float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
    if (paddleDir != 0) {
        paddle_pos.y += paddleDir * 300.0f * deltaTime;
        if (paddle_pos.y < thickness) {
            paddle_pos.y = 15;
        }
        else if (paddle_pos.y > (600.0f - thickness - 100)) {
            paddle_pos.y = 600.0f - thickness - 100;
        }
    }
    ball_pos.x += ball_vel.x * deltaTime;
    ball_pos.y += ball_vel.y * deltaTime;
    if (ball_pos.y <= thickness && ball_vel.y < 0.0f) {
        ball_vel.y *= -1;
    }
    if (ball_pos.y >= (600 - thickness) && ball_vel.y > 0.0f) {
        ball_vel.y *= -1;
    }
    if (ball_pos.x >= (1024 - thickness) && ball_vel.x > 0.0f) {
        ball_vel.x *= -1.0f;
    }
    if (ball_pos.x <= 0 && ball_vel.x < 0.0f) {
        Quit();
    }
    if (diff <= paddleH / 2.0f && ball_pos.x <= 25.0f && ball_pos.x >= 20.0f && ball_vel.x < 0.0f)
    {
        ball_vel.x *= -1.0f;
    }
}

int main(int argc, char** argv) {
    Game game;
    game.Init();
    if (game.runningSuccess()) {
        game.gameLoop();
    }
    game.Quit();
    return 0;
}
