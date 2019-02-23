//
//  main.cpp
//  Template
//
//  Created by Jeremy on 11/21/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Game.hpp"

int main(int argc, const char * argv[]) {
    Game mGame;
    if (mGame.Init()) {
        mGame.Update();
    }
    return 0;
}
