#include "MapAnalysis.h"
#include "GameManager.h"
#include "Floor.h"
#include "Hero.h"
#include "StaticData.h"

USING_NS_CC;

MapAnalysis* MapAnalysis::_mapAnalysis = nullptr;

MapAnalysis* MapAnalysis::getInstance()
{
	if (_mapAnalysis == nullptr)
	{
		_mapAnalysis = new MapAnalysis();
		CC_SAFE_RETAIN(_mapAnalysis);
	}
	return _mapAnalysis;
}

void MapAnalysis::initMap(char* levelName)
{
	GameManager* gameManager = GameManager::getInstance();
	//∂¡»°TiledµÿÕº◊ ‘¥
	TMXTiledMap* tiledMap = TMXTiledMap::create(levelName);
	gameManager->staticLayer->addChild(tiledMap, -1);
	//todo-- ”≤Ó±≥æ∞£¨¥À¥¶–ﬁ∏ƒ!TODO!‘∆≤ 
	Sprite* bkpic = Sprite::create("background.png");
    bkpic->setAnchorPoint(Vec2(0,0));
    bkpic->setPosition(0,0);
	gameManager->staticLayer->addChild(bkpic);
    bkpic->setGlobalZOrder(-100);
    
	//BrickLayer µÿ∞Â   Spikes ∑Ê¥Ã
	TMXObjectGroup* brickLayer = tiledMap->getObjectGroup("BrickLayer");
	ValueVector bricks = brickLayer->getObjects();
	for (int i = 0; i < bricks.size(); i++)
	{
		ValueMap brick = bricks.at(i).asValueMap();
		float w = brick.at("width").asFloat();
		float h = brick.at("height").asFloat();
		float x = brick.at("x").asFloat() + w/2.0f;
		float y = brick.at("y").asFloat() + h/2.0f;

		if (brick.at("name").asString() == "Floor")//Ã®Ω◊
		{
			Floor* b = Floor::create(x, y, w, h);
			gameManager->bgLayer->addChild(b);
		}
    }
/*		if (brick.at("name").asString() == "Brick")//Ã®Ω◊
		{
			Brick* b = Brick::create(x, y, w, h);
			gameManager->gameLayer->addChild(b);
		}
		else if (brick.at("name").asString() == "Wall")//«Ω
		{
			Wall* wa = Wall::create(x, y, w, h);
			gameManager->gameLayer->addChild(wa);
		}
		else if (brick.at("name").asString() == "Spikes")//∑Ê¥Ã
		{
			Spikes* sk = Spikes::create(x, y, w, h);
			gameManager->gameLayer->addChild(sk);
		}
		else if (brick.at("name").asString() == "DeadRoof")//À¿ÕˆÃ®Ω◊
		{
			DeadRoof* dr = DeadRoof::create(x, y, w, h);
			gameManager->gameLayer->addChild(dr);
		}
	}
*/
/*	//CoinLayer Ω±“
	TMXObjectGroup* coinLayer = tiledMap->getObjectGroup("CoinLayer");
	ValueVector coins = coinLayer->getObjects();
	for (int i = 0; i < coins.size(); i++)
	{
		ValueMap coin = coins.at(i).asValueMap();
		float w = SD_FLOAT("coin_float_width");
		float h = SD_FLOAT("coin_float_height");
		float x = coin.at("x").asFloat() + w / 2.0f;
		float y = coin.at("y").asFloat() + h / 2.0f;

		Coin* c = Coin::create(x, y, w, h);
		gameManager->thingLayer->addChild(c);
	}
	//MonsterLayer π÷ŒÔ
	TMXObjectGroup* monsterLayer = tiledMap->getObjectGroup("MonsterLayer");
	ValueVector monsters = monsterLayer->getObjects();
	for (int i = 0; i < monsters.size(); i++)
	{
		ValueMap monster = monsters.at(i).asValueMap();
		//MonsterEx »À–Õπ÷ŒÔ
		if (monster.at("name").asString() == "MonsterEx")
		{
			float w = SD_FLOAT("monster_float_width");
			float h = SD_FLOAT("monster_float_height");
			float x = monster.at("x").asFloat() + w / 2.0f;
			float y = monster.at("y").asFloat() + h / 2.0f;

			MonsterEx* m = MonsterEx::create(x, y, w, h);
			gameManager->monsterLayer->addChild(m);
		}
		//FlyingSlime ∑…–– ∑¿≥ƒ∑
		if (monster.at("name").asString() == "FlyingSlime")
		{
			float w = SD_FLOAT("flyingslime_float_width");
			float h = SD_FLOAT("flyingslime_float_height");
			float x = monster.at("x").asFloat() + w / 2.0f;
			float y = monster.at("y").asFloat() + h / 2.0f;

			FlyingSlime* f = FlyingSlime::create(x, y, w, h);
			gameManager->monsterLayer->addChild(f);
		}
		//Slime  ∑¿≥ƒ∑
		if (monster.at("name").asString() == "Slime")
		{
			float w = SD_FLOAT("slime_float_width");
			float h = SD_FLOAT("slime_float_height");
			float x = monster.at("x").asFloat() + w / 2.0f;
			float y = monster.at("y").asFloat() + h / 2.0f;

			Slime* s = Slime::create(x, y, w, h);
			gameManager->monsterLayer->addChild(s);
		}
		//£°£°£°Bird ƒÒ  ÷–¡¢µƒ--------£°£°£°£°£°
		if (monster.at("name").asString() == "Bird")
		{
			float w = SD_FLOAT("bird_float_width");
			float h = SD_FLOAT("bird_float_height");
			float x = monster.at("x").asFloat() + w / 2.0f;
			float y = monster.at("y").asFloat() + h / 2.0f;

			Bird* b = Bird::create(x, y, w, h);
			gameManager->monsterLayer->addChild(b);
		}
	}
	//ArticleLayer Ωªª•ŒÔÃÂ
	TMXObjectGroup* articleLayer = tiledMap->getObjectGroup("ArticleLayer");
	ValueVector articles = articleLayer->getObjects();
	for (int i = 0; i < articles.size(); i++)
	{
		ValueMap article = articles.at(i).asValueMap();
		//Article Ωªª•ŒÔÃÂ-œ‰◊”
		if (article.at("name").asString() == "Article")
		{
			float w = SD_FLOAT("article_float_width");
			float h = SD_FLOAT("article_float_height");
			float x = article.at("x").asFloat() + w / 2.0f;
			float y = article.at("y").asFloat() + h / 2.0f;

			Article* a = Article::create(x, y, w, h);
			gameManager->thingLayer->addChild(a);
		}
		//Door √≈
		if (article.at("name").asString() == "Door")
		{
			float w = SD_FLOAT("door_float_width");
			float h = SD_FLOAT("door_float_height");
			float x = article.at("x").asFloat() + w / 2.0f;
			float y = article.at("y").asFloat() + h / 2.0f;

			Door* a = Door::create(x, y, w, h);
			gameManager->thingLayer->addChild(a);
		}
		//JumpBoard Ã¯∞Â
		if (article.at("name").asString() == "JumpBoard")
		{
			float w = SD_FLOAT("jump_float_width");
			float h = SD_FLOAT("jump_float_height");
			float x = article.at("x").asFloat() + w / 2.0f;
			float y = article.at("y").asFloat() + h / 2.0f;

			JumpBoard* jb = JumpBoard::create(x, y, w, h);
			gameManager->gameLayer->addChild(jb);
		}
	}
*/
	//HeroLayer ”¢–€
	TMXObjectGroup* heroLayer = tiledMap->getObjectGroup("HeroLayer");
	ValueVector heros = heroLayer->getObjects();
	for (int i = 0; i < heros.size(); i++)
	{
		ValueMap hero = heros.at(i).asValueMap();
		//Article Ωªª•ŒÔÃÂ-œ‰◊”
		if (hero.at("name").asString() == "Hero")
		{
			float w = SD_FLOAT("hero_float_width");
			float h = SD_FLOAT("hero_float_height");
			float x = hero.at("x").asFloat() + w / 2.0f;
			float y = hero.at("y").asFloat() + h / 2.0f;

			Hero* e = Hero::create(x, y, w, h);
			gameManager->objLayer->addChild(e);
			//Œﬁµ–1√Î
			//YJQ DEBUG e->setUnbeatable(1);
			GameManager::getInstance()->hero = e;
		}
	}
}

void MapAnalysis::initMap(int level)
{
	char levle_s[128];
	sprintf(levle_s, "level_%d.tmx", level);
	initMap(levle_s);
}

MapAnalysis::~MapAnalysis()
{
	CC_SAFE_RELEASE_NULL(_mapAnalysis);
}
////////////////////////////////////////////////
MapAnalysis::MapAnalysis()
{
    
}


