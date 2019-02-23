//
//  Game.hpp
//  Chapter2 - Exercise 2.1
//
//  Created by Jeremy on 11/1/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//


#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


// "/Users/Jeremy/Desktop/C++/SDL/Chapter2/Chapter2\ -\ Exercise\ 2.1/Chapter2\ -\ Exercise\ 2.1/Assets/platformer-extendedtiles-0"

class Game {
public:
    Game();
    bool Init();
    void gameLoop();
    void shutDown();
    Uint32 ticksCount = 0;
private:
    void renderGame();
    void updateGame();
    void handleEvents();

    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};
