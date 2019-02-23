//
//  Ship.cpp
//  Chapter2
//
//  Created by Jeremy on 10/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Ship.hpp"
#include "AnimSpriteComponent.hpp"
#include "Game.hpp"

Ship::Ship(class Game* game) : Actor(game), mRightSpeed(0.0f), mDownSpeed(0.0f) {
    AnimSpriteComponent* asc = new AnimSpriteComponent(this);
    std::vector<SDL_Texture*> anims = {
        game->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Chapter2/Chapter2/Assets/Ship01.png"),
        game->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Chapter2/Chapter2/Assets/Ship02.png"),
        game->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Chapter2/Chapter2/Assets/Ship03.png"),
        game->GetTexture("/Users/Jeremy/Desktop/C++/SDL/Chapter2/Chapter2/Assets/Ship04.png"),
    };
    asc->SetAnimTextures(anims);
}

void Ship::UpdateActor(float deltaTime)
{
    Actor::UpdateActor(deltaTime);
    // Update position based on speeds and delta time
    Vector2 pos = GetPosition();
    pos.x += mRightSpeed * deltaTime;
    pos.y += mDownSpeed * deltaTime;
    // Restrict position to left half of screen
    if (pos.x < 25.0f)
    {
        pos.x = 25.0f;
    }
    else if (pos.x > 500.0f)
    {
        pos.x = 500.0f;
    }
    if (pos.y < 25.0f)
    {
        pos.y = 25.0f;
    }
    else if (pos.y > 743.0f)
    {
        pos.y = 743.0f;
    }
    SetPosition(pos);
}

void Ship::ProcessKeyboard(const uint8_t* state)
{
    mRightSpeed = 0.0f;
    mDownSpeed = 0.0f;
    // right/left
    if (state[SDL_SCANCODE_D])
    {
        mRightSpeed += 250.0f;
    }
    if (state[SDL_SCANCODE_A])
    {
        mRightSpeed -= 250.0f;
    }
    // up/down
    if (state[SDL_SCANCODE_S])
    {
        mDownSpeed += 300.0f;
    }
    if (state[SDL_SCANCODE_W])
    {
        mDownSpeed -= 300.0f;
    }
}
