#include "HelloWorldScene.h"
#include "GameScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto startItem = cocos2d::MenuItemFont::create("START", CC_CALLBACK_1(HelloWorld::menuStartCallback, this));
    startItem->setFontName("fonts/Marker Felt.ttf");
    startItem->setFontSize(20);
    startItem->setAnchorPoint(Vec2(0,0));
    startItem->setPosition(Vec2(0,0));
    auto menu = Menu::create(startItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    return true;
}


void HelloWorld::menuStartCallback(cocos2d::Ref* ref) {
    auto reScene=TransitionCrossFade::create(0.3f,GameScene::createScene());
    Director::getInstance()->replaceScene(reScene);
}
