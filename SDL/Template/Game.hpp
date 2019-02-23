//
//  Game.hpp
//  Template
//
//  Created by Jeremy on 11/21/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game {
public:
    Game();
    bool Init();
    void Update();
    void Events();
    void Quit();
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    bool mIsRunning;
};
