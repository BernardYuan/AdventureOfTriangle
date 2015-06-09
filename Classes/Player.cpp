//
//  Player.cpp
//  Game
//
//  Created by Bernard Yuan on 6/8/15.
//
//

#include "Player.h"
USING_NS_CC;
Player::Player() {
    
}
Player::~Player(){
    
}
Sprite* Player:: getSprite(){
    return _player;
}

void Player::init() {
    _player=cocos2d::Sprite::create("res/t0.png");
    _player->setAnchorPoint(Vec2(0.5,0));
    Vector<SpriteFrame*> frames;
    frames.pushBack(SpriteFrame::create("res/t1.png",Rect(0,0,128,128)));
    frames.pushBack(SpriteFrame::create("res/t2.png",Rect(0,0,128,128)));
    auto WalkAnimation=cocos2d::Animation::createWithSpriteFrames(frames,0.1);
    WalkAnimation->setRestoreOriginalFrame(false);
    WalkAnimation->setLoops(10000);
    auto WalkAnimate=Animate::create(WalkAnimation);
    auto walk=MoveBy::create(10, Vec2(400,0));
    walkAction=Spawn::createWithTwoActions(walk, WalkAnimate);
}

void Player::Walk() {
    _player->runAction(walkAction);
}

void Player::SetPosition(Vec2 des) {
    _player->setPosition(des);
}