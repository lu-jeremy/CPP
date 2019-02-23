//
//  Game.hpp
//  Template
//
//  Created by Jeremy on 11/21/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#pragma once
#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game {
public:
    Game();
    bool Init();
    void Update();
    void Events();
    void Quit();
    SDL_Texture* GetTexture(const std::string& FILENAME);
    void SetTexture(SDL_Texture* tempTexture);
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Texture* mTexture;
    class Ship* mShip;
    bool mIsRunning;
};
