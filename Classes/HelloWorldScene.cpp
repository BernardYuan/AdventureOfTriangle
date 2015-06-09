#include "HelloWorldScene.h"
#include "Player.h"
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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //                                       "CloseNormal.png",
    //                                       "CloseSelected.png",
    //                                       CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    //                            origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);
    cocos2d::Vector<cocos2d::MenuItem*> menuList;
    //auto exitItem = MenuItemFont::create("EXIT", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    //exitItem->setFontName("fonts/Marker Felt.ttf");
    //exitItem->setFontSize(20);
    //exitItem->setAnchorPoint(Vec2(0,0));
    //exitItem->setPosition(Vec2(0,0));
    auto startItem = MenuItemFont::create("START", CC_CALLBACK_1(HelloWorld::menuStartCallback, this));
    startItem->setFontName("fonts/Marker Felt.ttf");
    startItem->setFontSize(20);
    startItem->setAnchorPoint(Vec2(0,0));
    startItem->setPosition(Vec2(0,30));
    menuList.pushBack(startItem);
    //menuList.pushBack(exitItem);
    
    auto menu = Menu:: createWithArray(menuList);
    menu->setAnchorPoint(Vec2(0,0));
    menu->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(menu,1);
    /////////////////////////////
    // 3. add your codes below...
    Triangle.init();
    Triangle.SetPosition(Vec2(300,300));
    this->addChild(Triangle.getSprite(),2);
    Triangle.Walk();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuStartCallback(Ref* pSender) {
    //Director::getInstance()->replaceScene();
    
}