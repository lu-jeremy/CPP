//
//  Game.hpp
//  SDLGL_CrossOver
//
//  Created by Jeremy on 12/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


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
    SDL_GLContext mContext;
};
