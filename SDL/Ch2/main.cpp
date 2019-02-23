//
//  Actor.cpp
//  SDL_Development
//
//  Created by Jeremy on 10/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"

//"Users/Jeremy/Desktop/C++/SDL/Chapter2/Chapter2/Assets/Farback01.png"

int main(int argc, char** argv)
{
    Game game;
    bool success = game.Initialize();
    if (success)
    {
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}
