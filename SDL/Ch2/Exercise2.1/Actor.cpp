//
//  Actor.cpp
//  Chapter2 - Exercise 2.1
//
//  Created by Jeremy on 11/10/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Actor.hpp"

Actor::Actor(Game* game):mState(active),
mPosition(Vector2::Zero), mScale(1.0f),
mRotation(0.0f), mGame(game) {
    mGame->AddActor(this);
}

Actor::~Actor() {
    mGame->RemoveComponent(this);
    while (!mComponents.empty()) {
        delete mComponents.back();
    }
}

void Actor::Update(float deltaTime) {
    if (mState == active) {
        UpdateComponents(deltaTime);
        UpdateActor(deltaTime);
    }
}

void Actor::UpdateComponents(float deltaTime) {
    for (auto comp : mComponents) {
        comp->Update(deltaTime);
    }
}

void Actor::UpdateActor(float deltaTime) {

}

void Actor::AddComponent(Component* component) {
    int myOrder = component -> GetUpdateOrder();
    auto iter = mComponents.begin();
    for (; iter != mComponents.end(); ++ iter) {
        if (myOrder < (*iter) -> getUpdateOrder()) {
            break;
        }
    }
    mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component) {
    auto iter = std::find(mComponents.begin(), mComponents.end(), component);
    if (iter != mComponents.end()) {
        mComponents.erase(iter);
    }
}
