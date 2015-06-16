#include "GameScene.h"
#include "GameManager.h"
#include "HelloWorldScene.h"
#include "MapAnalysis.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
    
	return scene;
}

bool GameScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	pause = false;
    
	//char levelStr[5];
	//sprintf(levelStr, "level_%d_", level);
    //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //	umeng::MobClickCpp::startLevel(levelStr);
    //#endif

	staticLayer = this;
	GameManager::getInstance()->staticLayer = staticLayer;
	
	bgLayer = Layer::create();
	GameManager::getInstance()->bgLayer = bgLayer;
	staticLayer->addChild(bgLayer,0);

    objLayer=Layer::create();
    GameManager::getInstance()->objLayer=objLayer;
    bgLayer->addChild(objLayer,1); // Try to make "follow"
    
	settingLayer = Layer::create(); //add an resume button to the setting layer
	GameManager::getInstance()->settingLayer = settingLayer;
	staticLayer->addChild(settingLayer,2);
	settingLayer->setVisible(false);
	
	auto settingMenu = Menu::create();
	settingMenu->setAnchorPoint(Vec2(0, 0));
	settingMenu->setPosition(0, 0);
	settingLayer->addChild(settingMenu);
    
    auto backBtn=MenuItemFont::create("RESUME", CC_CALLBACK_1(GameScene::settingBackCallback, this));
    backBtn->setFontName("fonts/Marker Felt.ttf");
    //backBtn->setFontSize(50);
    backBtn->setAnchorPoint(Vec2(0.5,0.5));
    backBtn->setPosition(500,350);
    settingMenu->addChild(backBtn);
    auto exitBtn=MenuItemFont::create("EXIT",CC_CALLBACK_1(GameScene::settingExitCallback, this));
    exitBtn->setFontName("fonts/Marker Felt.ttf");
    //exitBtn->setFontSize(50);
    exitBtn->setAnchorPoint(Vec2(0.5,0.5));
    exitBtn->setPosition(500,300);
    settingMenu->addChild(exitBtn);
    
    
    auto pauseMenu = Menu::create();
    pauseMenu->setAnchorPoint(Vec2(0,0));
    pauseMenu->setPosition(Director::getInstance()->getVisibleSize().width-150,Director::getInstance()->getVisibleSize().height-50);
    staticLayer->addChild(pauseMenu);
    
    auto pauseBtn=MenuItemFont::create("PAUSE", CC_CALLBACK_1(GameScene::menuPauseCallback, this));
    pauseBtn->setFontName("fonts/Marker Felt.ttf");
    pauseBtn->setFontSize(15);
    //pauseBtn->setAnchorPoint(Vec2(0,0));
    //pauseBtn->setPosition(Vec2(0,0));
    pauseMenu->addChild(pauseBtn);
    
    //form the Map
	MapAnalysis* mapAnalysis = MapAnalysis::getInstance();
	mapAnalysis->initMap((int)1); //YJQ DEBUG
	hero = GameManager::getInstance()->hero;
    
    auto event = EventListenerKeyboard::create();
    event->onKeyPressed=CC_CALLBACK_2(GameScene::keyPressed, this);
    event->onKeyReleased=CC_CALLBACK_2(GameScene::keyReleased, this);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(event, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event, this);
	scheduleUpdate();
	return true;
}

void GameScene::update(float time)
{
	if (!pause)
		GameManager::getInstance()->step(time);
}

void GameScene::setLeft(bool left)
{
	_left = left;
}

bool GameScene::isLeft()
{
	return _left;
}

void GameScene::setRight(bool right)
{
	_right = right;
}

bool GameScene::isRight()
{
	return _right;
}


void GameScene::menuPauseCallback(Ref* ref)
{
	pause = true;
	settingLayer->setVisible(true);
}

void GameScene::settingBackCallback(cocos2d::Ref* ref) {
    pause= false;
    settingLayer->setVisible(false);
}

void GameScene::settingExitCallback(cocos2d::Ref* ref) {
    Director::getInstance()->end();
}
void GameScene::keyPressed(EventKeyboard::KeyCode code, Event* event) {
    if(code==EventKeyboard::KeyCode::KEY_LEFT_ARROW||code==EventKeyboard::KeyCode::KEY_A) {
        hero->moveLeft();
    }
    else if(code==EventKeyboard::KeyCode::KEY_RIGHT_ARROW||code==EventKeyboard::KeyCode::KEY_D) {
        hero->moveRight();
    }
    else if(code==EventKeyboard::KeyCode::KEY_UP_ARROW||code==EventKeyboard::KeyCode::KEY_W) {
        hero->jump();
    }
    else if(code==EventKeyboard::KeyCode::KEY_SPACE) {
        if (pause) {
            pause= false;
            settingLayer->setVisible(false);
        }
        else {
            pause = true;
            settingLayer->setVisible(true);
        }
    }
}
void GameScene::keyReleased(EventKeyboard::KeyCode code, Event* event) {
    if(code==EventKeyboard::KeyCode::KEY_LEFT_ARROW|| code==EventKeyboard::KeyCode::KEY_A) {
        hero->moveStop();
    }
    else if(code==EventKeyboard::KeyCode::KEY_RIGHT_ARROW||code==EventKeyboard::KeyCode::KEY_D) {
        hero->moveStop();
    }
}
