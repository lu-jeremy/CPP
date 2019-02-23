//
//  Ship.hpp
//  Chapter2
//
//  Created by Jeremy on 10/24/18.
//  Copyright © 2018 Jeremy. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include "Actor.hpp"

class Ship : public Actor
{
public:
    Ship(class Game* game);
    void UpdateActor(float deltaTime) override;
    void ProcessKeyboard(const uint8_t* state);
    float GetRightSpeed() const { return mRightSpeed; }
    float GetDownSpeed() const { return mDownSpeed; }
private:
    float mRightSpeed;
    float mDownSpeed;
};

#endif /* Ship_hpp */
