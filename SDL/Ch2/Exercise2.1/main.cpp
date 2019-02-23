//
//  main.cpp
//  Chapter2 - Exercise 2.1
//
//  Created by Jeremy on 10/31/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"


int main(int argc, const char * argv[]) {
    Game game;
    bool success = game.Init();
    if (success) {
        game.gameLoop();
    }
    game.shutDown();
    return 0;
}
