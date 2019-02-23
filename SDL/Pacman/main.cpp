#include "Game.hpp"

Game* game = nullptr;

int main(int argc, const char * argv[]) {
    
    game = new Game();
    
    const int FPS = 100;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    
    game->init("GameWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    while(game->running()) {
        frameStart = SDL_GetTicks();
        game->HandleEvents();
        game->update();
        game->render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
    return 0;
}
