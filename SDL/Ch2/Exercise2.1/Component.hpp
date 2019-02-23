//
//  Component.hpp
//  Chapter2 - Exercise 2.1
//
//  Created by Jeremy on 11/10/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#pragma once

class Component {
public:
    Component(class Actor* owner, int updateOrder = 100);
    virtual ~Component();
    virtual void Update(float deltaTime);
    int GetUpdateOrder() const {
        return mUpdateOrder;
    }
protected:
    class Actor* mOwner;
    int mUpdateOrder;
};
