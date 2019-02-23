//
//  Component.cpp
//  Chapter2 - Exercise 2.1
//
//  Created by Jeremy on 11/10/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Component.hpp"
#include "Actor.hpp"

Component::Component(Actor* owner, int updateOrder):mOwner(owner), mUpdateOrder(updateOrder) {
    mOwner -> AddComponent(this);
}

Component::~Component() {
    mOwner -> RemoveComponent(this);
}

void Component::Update(float deltaTime) {
    
}
