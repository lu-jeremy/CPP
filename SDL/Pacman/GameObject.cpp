#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y) {
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);
    
    xPos = x;
    yPos = y;
}

void GameObject::update() {
    xPos++;
    yPos++;
    
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.h = srcRect.h * 2;
    destRect.w =  srcRect.w * 2;
    destRect.x = xPos;
    destRect.y = yPos;
};

void GameObject::render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

