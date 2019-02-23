//
//  Component.cpp
//  Chapter2
//
//  Created by Jeremy on 10/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#include "Component.hpp"
#include "Actor.hpp"

Component::Component(Actor* owner, int updateOrder)
:mOwner(owner)
,mUpdateOrder(updateOrder)
{
    // Add to actor's vector of components
    mOwner->AddComponent(this);
}

Component::~Component()
{
    mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}
