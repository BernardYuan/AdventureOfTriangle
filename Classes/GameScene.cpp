#include "GameScene.h"
#include "GameManager.h"
#include "HelloWorldScene.h"
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
	if ( !LayerColor::initWithColor(Color4B(0,250,250,255)) )
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
	staticLayer->addChild(bgLayer);

    objLayer=Layer::create();
    GameManager::getInstance()->objLayer=objLayer;
    staticLayer->addChild(objLayer);
    
	settingLayer = Layer::create(); //add an resume button to the setting layer
	GameManager::getInstance()->settingLayer = settingLayer;
	staticLayer->addChild(settingLayer);
	settingLayer->setVisible(false);
	
	auto settingMenu = Menu::create();
	settingMenu->setAnchorPoint(Vec2(0, 0));
	settingMenu->setPosition(0, 0);
	settingLayer->addChild(settingMenu);
    
    
    auto pauseMenu = Menu::create();
    pauseMenu->setAnchorPoint(Vec2(0,0));
    pauseMenu->setPosition(1000,700);
    objLayer->addChild(pauseMenu);
    
    auto pauseBtn=MenuItemFont::create("PAUSE", CC_CALLBACK_1(GameScene::menuPauseCallback, this));
    pauseBtn->setFontName("fonts/Marker Felt.ttf");
    pauseBtn->setFontSize(15);
    pauseMenu->addChild(pauseBtn);
    
    //form the Map
	//MapAnalysis* mapAnalysis = MapAnalysis::getInstance();
	//mapAnalysis->initMap(level);
	hero = GameManager::getInstance()->hero;
    
    /*
	EventListenerKeyboard* event = EventListenerKeyboard::create();
	event->onKeyPressed = [=](EventKeyboard::KeyCode code, Event* event){
		if(code == EventKeyboard::KeyCode::KEY_K)
		{
			hero->jump();
		}
		else if(code == EventKeyboard::KeyCode::KEY_A)
		{
			hero->moveLeft();
		}
		else if(code == EventKeyboard::KeyCode::KEY_D)
		{
			hero->moveRight();
		}
		else if(code == EventKeyboard::KeyCode::KEY_J)
		{
			hero->fire();
		}
	};
	event->onKeyReleased = [=](EventKeyboard::KeyCode code, Event* event){
		if(code == EventKeyboard::KeyCode::KEY_A && hero->getMoveState() == MOVE_LEFT)
		{
			hero->moveStop();
		}
		else if(code == EventKeyboard::KeyCode::KEY_D && hero->getMoveState() == MOVE_RIGHT)
		{
			hero->moveStop();
		}
	};
     
    */
    
	/*
	Sprite* but_left = Sprite::create("HUD/button_up_left.png");
	but_left->setAnchorPoint(Vec2(0, 0));
	but_left->setPosition(CD_FLOAT("hud_but_left_x"), CD_FLOAT("hud_but_left_y"));
	hudLayer->addChild(but_left);

	Sprite* but_right = Sprite::create("HUD/button_up_right.png");
	but_right->setAnchorPoint(Vec2(0, 0));
	but_right->setPosition(CD_FLOAT("hud_but_right_x"), CD_FLOAT("hud_but_right_y"));
	hudLayer->addChild(but_right);

	Sprite* but_A = Sprite::create("HUD/button_up_A.png");
	but_A->setAnchorPoint(Vec2(0, 0));
	but_A->setPosition(CD_FLOAT("hud_but_A_x"), CD_FLOAT("hud_but_A_y"));
	hudLayer->addChild(but_A);

	Sprite* but_B = Sprite::create("HUD/button_up_B.png");
	but_B->setAnchorPoint(Vec2(0, 0));
	but_B->setPosition(CD_FLOAT("hud_but_B_x"), CD_FLOAT("hud_but_B_y"));
	hudLayer->addChild(but_B);
	
	Menu* hudMenu = Menu::create();
	hudMenu->setAnchorPoint(Vec2(0, 0));
	hudMenu->setPosition(0, 0);
	hudLayer->addChild(hudMenu);
	
	MenuItemImage* pauseButton = MenuItemImage::create("UI/GAME/pause_button.png", "UI/GAME/pause_button.png", "UI/GAME/pause_button.png", CC_CALLBACK_1(GameScene::pauseButton, this));
	pauseButton->setPosition(CD_FLOAT("hud_pause_bt_x"), 640-CD_FLOAT("hud_pause_bt_y"));
	hudMenu->addChild(pauseButton);
	
    Rect rect_but_left = but_left->getBoundingBox();
	Rect rect_but_right = but_right->getBoundingBox();
	Rect rect_but_A = but_A->getBoundingBox();
	Rect rect_but_B = but_B->getBoundingBox();
	
	EventListenerTouchAllAtOnce* touchEvent = EventListenerTouchAllAtOnce::create();
	touchEvent->onTouchesBegan = [=](const std::vector<Touch*>& touches, Event* event){
		for (auto &item : touches)       //±È¿˙»›∆˜÷–µƒ∏˜∏ˆ≥…‘±
		{
			auto touch = item;
			auto location = touch->getLocation();
			//LEFT
			if (rect_but_left.containsPoint(location))
			{
				hero->moveLeft();
			}
			//RIGHT
			else if (rect_but_right.containsPoint(location))
			{
				hero->moveRight();
			} 
			//A
			else if (rect_but_A.containsPoint(location))
			{
				hero->fire();
			} 
			//B
			else if (rect_but_B.containsPoint(location))
			{
				hero->jump();
			}
		}
	};
	//¥•√˛ ±
	touchEvent->onTouchesMoved = [=](const std::vector<Touch*>& touches, Event* event){
		bool left = false;
		bool right = false;
		for (auto &item : touches)       //±È¿˙»›∆˜÷–µƒ∏˜∏ˆ≥…‘±
		{
			auto touch = item;
			auto location = touch->getLocation();
			
			if (rect_but_left.containsPoint(location))
			{
				left = true;
				hero->moveLeft();
			}
			else if (rect_but_right.containsPoint(location))
			{
				right = true;
				hero->moveRight();
			}
		}
		setLeft(left);
		setRight(right);
		if (!left && !right)
		{
			hero->moveStop();
		}
	};
	//¥•√˛Ãß∆
	touchEvent->onTouchesEnded = [=](const std::vector<Touch*>& touches, Event* event){
		bool left = isLeft();
		bool right = isRight();
		for (auto &item : touches)       //±È¿˙»›∆˜÷–µƒ∏˜∏ˆ≥…‘±
		{
			auto touch = item;
			auto location = touch->getLocation();

			if (rect_but_left.containsPoint(location))
			{
				left = false;
			}
			else if (rect_but_right.containsPoint(location))
			{
				right = false;
			}
		}
		setLeft(left);
		setRight(right);
		if (!left && !right)
		{
			hero->moveStop();
		}
	};
	//∞Û∂® ¬º˛
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEvent, this);
	*/
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
    settingLayer->setVisible(false);
    pause= false;
}

void GameScene::settingExitCallback(cocos2d::Ref* ref) {
    Director::getInstance()->end();
}

