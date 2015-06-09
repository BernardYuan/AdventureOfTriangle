//
//  WelcomeScene.cpp
//  Game
//
//  Created by Bernard Yuan on 6/8/15.
//
//

#include "WelcomeScene.h"
USING_NS_CC;

Scene* WelcomeScene:: createScene() {
    auto scene=Scene::create();
    auto layer=WelcomeScene::create();
    scene->addChild(layer);
    return scene;
}

bool WelcomeScene:: init() {
    if(Layer::init()) {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //cocos2d::Vector<cocos2d::MenuItem*> menuList;
    /*auto startItem = MenuItemFont::create("START",this,menu_selector(WelcomeScene::menuStartCallBack));
    startItem->setAnchorPoint(Vec2(0,0));
    startItem->setPosition(Vec2(0,0));
    startItem->setFontSize(20);
    startItem->setFontName("fonts/Marker Felt.ttf");
    menuList.pushBack(startItem);*/
    
    auto exitItem = MenuItemImage::create("HelloWorld.png","HelloWorld.png",CC_CALLBACK_1(WelcomeScene::menuExitCallBack,this));
    exitItem->setAnchorPoint(Vec2(0, 0));
    exitItem->setPosition(Vec2(0,0));
    //exitItem->setFontSize(20);
    //exitItem->setFontName("fonts/Marker Felt.ttf");
    auto menu=Menu::create(exitItem, NULL);
    menu->setPosition(Vec2(0,0));
    //menuList.pushBack(exitItem);
    this -> addChild(menu,1);
    /*auto pMenu=Menu::createWithArray(menuList);
    pMenu->setAnchorPoint(Vec2(0,0));
    pMenu->setPosition(Vec2(0,0));
    */
    //this->addChild(pMenu);

    return true;
}

void WelcomeScene:: menuStartCallBack(cocos2d::Ref* pSender) {
    //Director::getInstance()->replaceScene();
}
void WelcomeScene:: menuExitCallBack(cocos2d::Ref* pSender) {
    Director::getInstance()->end();
    exit(0);
}
