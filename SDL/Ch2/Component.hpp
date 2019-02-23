//
//  Component.hpp
//  Chapter2
//
//  Created by Jeremy on 10/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#pragma once
class Component
{
public:
    // Constructor
    // (the lower the update order, the earlier the component updates)
    Component(class Actor* owner, int updateOrder = 100);
    // Destructor
    virtual ~Component();
    // Update this component by delta time
    virtual void Update(float deltaTime);
    
    int GetUpdateOrder() const { return mUpdateOrder; }
protected:
    // Owning actor
    class Actor* mOwner;
    // Update order of component
    int mUpdateOrder;
};
