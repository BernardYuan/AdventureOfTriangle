//
//  WinScene.cpp
//  TestDemo
//
//  Created by Bernard Yuan on 6/16/15.
//
//

#include "WinScene.h"
#include "GameManager.h"
#include "GameScene.h"
USING_NS_CC;

Scene* WinScene::createScene() {
    auto scene=Scene::create();
    auto layer=WinScene::create();
    
    scene->addChild(layer);
    return scene;
}

bool WinScene::init() {
    if ( !Layer::init() )
    {
        return false;
    }
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg=Sprite::create("res/win.png");
    bg->setAnchorPoint(Vec2(0,0));
    bg->setPosition(0,0);
    this->addChild(bg, 0);
    
    auto restartItem = cocos2d::MenuItemFont::create("RESTART", CC_CALLBACK_1(WinScene::menuReStartCallback,this));
    restartItem->setFontName("fonts/Marker Felt.ttf");
    //restartItem->setFontSize(20);
    restartItem->setAnchorPoint(Vec2(0.5,0.5));
    restartItem->setPosition(Vec2(512,300));
    
    auto exitItem = cocos2d::MenuItemFont::create("EXIT",CC_CALLBACK_1(WinScene::menuExitCallback, this));
    exitItem -> setFontName("fonts/Marker Felt.ttf");
    //exitItem -> setFontSize(50);
    exitItem -> setAnchorPoint(Vec2(0.5,0.5));
    exitItem -> setPosition(Vec2(512,250));
    
    
    auto menu = Menu::create();
    menu->setAnchorPoint(Vec2(0,0));
    menu->setPosition(Vec2(0,0));
    this->addChild(menu, 1);
    menu->addChild(restartItem);
    menu->addChild(exitItem);
    /////////////////////////////
    // 3. add your codes below...
    
    return true;
    
}

void WinScene::menuExitCallback(cocos2d::Ref* ref) {
    Director::getInstance()->end();
}

void WinScene::menuReStartCallback(cocos2d::Ref* ref) {
    GameManager::destroyInstance();
    auto reScene=TransitionCrossFade::create(0.3f,GameScene::createScene());
    Director::getInstance()->replaceScene(reScene);
}