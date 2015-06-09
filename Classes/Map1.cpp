//
//  Map1.cpp
//  Game
//
//  Created by Bernard Yuan on 6/8/15.
//
//

#include "cocos2d.h"
#include "Map1.h"

USING_NS_CC;

Map1::Map1() {
    
}

Map1::~Map1(){
    
}

bool Map1::init() {
    if(Layer::init()) {
        return false;
    }
    Size visibleSize=Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    trey.init();
    trey.SetPosition(Vec2(200,200));
    this->addChild(trey.getSprite());
    
    auto keyBoardListener =EventListenerKeyboard::create();
    
    //keyBoardListener->onKeyPressed= CC_CALLBACK_2(Map1::onKeyPressed, this);
    //keyBoardListener->onKeyReleased=CC_CALLBACK_2(Map1::onKeyReleased, this);
    
    
    
    
    
    
    return true;
}

void Map1::onKeyPressed() {
    
}
void Map1::onKeyReleased() {
    
}


