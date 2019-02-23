//
//  Ship.cpp
//  BasicGame
//
//  Created by Jeremy on 11/22/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Ship.hpp"
#include "Game.hpp"

Ship::Ship(Game* mGame) {
    SDL_Texture* tempShip = mGame->GetTexture("/Users/Jeremy/Desktop/C++/SDL/BasicGame/BasicGame/BasicGame/Assets/Ship.png");
    this->SetTexture(tempShip);
}

void Ship::Draw(SDL_Renderer* tempRenderer) {
    SDL_Rect r;
    r.h = 100;
    r.w = 100;
    r.x = 640;
    r.y = 400;
    mRotation += rotationSpeed;
    SDL_RenderCopyEx(tempRenderer, mTexture, nullptr, &r, mRotation, nullptr, SDL_FLIP_NONE);
}

void Ship::SetTexture(SDL_Texture* tempTexture) {
    mTexture = tempTexture;
}

void Ship::GetKeyboardState(const uint8_t* mState) {
    if (mState[SDL_SCANCODE_RIGHT]) {
        rotationSpeed = 5;
    }
    else if (mState[SDL_SCANCODE_LEFT]) {
        rotationSpeed = -5;
    }
    else {
        rotationSpeed = 0;
    }
}
