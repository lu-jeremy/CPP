//
//  Ship.hpp
//  BasicGame
//
//  Created by Jeremy on 11/22/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"

class Ship : public Game {
public:
    Ship(class Game* mGame);
    virtual void Draw(SDL_Renderer* tempRenderer);
    void SetTexture(SDL_Texture* tempTexture);
    void GetKeyboardState(const uint8_t* mState);
private:
    int mRotation;
    int rotationSpeed;
    SDL_Texture* mTexture;
};
