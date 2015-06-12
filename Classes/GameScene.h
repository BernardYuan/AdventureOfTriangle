//
//  GameScene.h
//  Susi
//
//  Created by Bernard Yuan on 6/10/15.
//
//

#ifndef __Susi__GameScene__
#define __Susi__GameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "Hero.h"
USING_NS_CC;
class GameScene :public cocos2d::LayerColor
{
private:
    bool pause;
    cocos2d::Layer* staticLayer;
    cocos2d::Layer* bgLayer;
    cocos2d::Layer* objLayer;
    cocos2d::Layer* settingLayer;
    bool _left;
    bool _right;
    
    Hero* hero;
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    CREATE_FUNC(GameScene);
    
    void update(float);
    
    bool isRight();
    bool isLeft();
    
    void setRight(bool);
    void setLeft(bool);
    
    
    void menuPauseCallback(cocos2d::Ref* );
    
};

#endif /* defined(__Susi__GameScene__) */
