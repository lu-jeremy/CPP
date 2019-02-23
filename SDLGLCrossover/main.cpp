//
//  main.cpp
//  SDLGL_CrossOver
//
//  Created by Jeremy on 12/24/18.
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
