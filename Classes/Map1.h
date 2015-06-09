//
//  Map1.h
//  Game
//
//  Created by Bernard Yuan on 6/8/15.
//
//

#ifndef __Game__Map1__
#define __Game__Map1__

#include <stdio.h>
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;
class Map1 : public cocos2d::Layer
{
public:
    Player trey;
    Map1();
    ~Map1();
    virtual bool init();
    CREATE_FUNC(Map1);
    void onKeyPressed();
    void onKeyReleased();
};
#endif /* defined(__Game__Map1__) */
