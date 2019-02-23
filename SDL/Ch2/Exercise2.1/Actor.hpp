//
//  Actor.hpp
//  Chapter2 - Exercise 2.1
//
//  Created by Jeremy on 11/10/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#pragma once
#include <vector>
#include "Math.hpp"


class Actor {
public:
    enum State {
        active, paused, dead
    };
    Actor(class Game* game);
    virtual ~Actor();
    void Update(float deltaTime);
    void UpdateComponents(float deltaTime);
    virtual void UpdateActor(float deltaTime);
    const Vector2& getPosition() const {
        return mPosition;
    }
    void setPosition(Vector2& position) {
        mPosition = position;
    }
    float getScale() const {
        return mScale;
    };
    void setScale(float scale) {
        mScale = scale;
    }
    float getRotation() const {
        return mRotation;
    }
    void setRotation(float rotation) {
        mRotation = rotation;
    }
    State getState() const {
        return mState;
    }
    void setState(State state) {
        mState = state;
    }
    class Game* getGame() {
        return mGame;
    }
    void AddComponent(class Component* component);
    void RemoveComponent(class Component* component);
private:
    State mState;
    Vector2 mPosition;
    float mScale;
    float mRotation;
    std::vector<class Component*> mComponents;
    class Game* mGame;
};
