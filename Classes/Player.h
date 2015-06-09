//
//  Player.h
//  Game
//
//  Created by Bernard Yuan on 6/8/15.
//
//

#ifndef __Game__Player__
#define __Game__Player__

#include <stdio.h>
#include "cocos2d.h"

class Player
{
public:
    Player();
    ~Player();
    virtual void init();
    void SetPosition(cocos2d::Vec2);
    void Walk();
    //void Jump();
    cocos2d::Sprite* getSprite();
private:
    cocos2d::Sprite* _player;
    cocos2d::Spawn* walkAction;
    //cocos2d::Animate* WalkAnimate;
    //cocos2d::Animate* JumpAnimate;
};



#endif /* defined(__Game__Player__) */
