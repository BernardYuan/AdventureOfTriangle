//
//  GameManager.cpp
//  Susi
//
//  Created by Bernard Yuan on 6/10/15.
//
//

#include "GameManager.h"

USING_NS_CC;

GameManager* GameManager::gameManager=nullptr;

GameManager::GameManager() {
    hero=nullptr;
    initRes();
    initPhysicsWorld(GRAVITY);
}
GameManager:: ~GameManager() {
    CC_SAFE_DELETE(world);
}

GameManager* GameManager::getInstance() {
    if(!gameManager) {
        gameManager=new GameManager();
        gameManager->retain(); //counting plus 1
    }
    return gameManager;
}

void GameManager::destroyInstance() {
    CC_SAFE_DELETE(gameManager);
}

void GameManager::initPhysicsWorld(float gravity) {
    world = new b2World(b2Vec2(0, -gravity));
    world->SetContactListener(this);
    
    sceneX = Director::getInstance()->getVisibleSize().width / 2;
    //sceneY = Director::getInstance()->getVisibleSize().height / 2;
    //sceneY = 0;
}

void GameManager::step(float duration) {
    Vec2 heroLastPostion = hero->getPosition();
    
    world->Step(duration, 8, 3);

    for(b2Body* body=world->GetBodyList(); body; body=body->GetNext())
    {
        Sprite* sprite = (Sprite*)body->GetUserData();
        if(sprite == NULL)
            continue;
        sprite->setPosition(body->GetPosition().x*PTM_RATIO, body->GetPosition().y*PTM_RATIO);
        sprite->setRotation(-1*CC_RADIANS_TO_DEGREES(body->GetAngle()));
    }
    

    for(auto it  = _deleteSprites.begin(); it != _deleteSprites.end(); )
    {
        (*it)->removePhysicsSprite();
        it = _deleteSprites.erase(it);
    }

    Vec2 heroNowPostion = hero->getPosition();
    sceneX = sceneX + heroLastPostion.x - heroNowPostion.x;
    //sceneY = sceneY + heroLastPostion.y - heroNowPostion.y;
    GameManager::getInstance()->bgLayer->setPosition(sceneX, sceneY);
    log("X:%f Y:%f\n", heroNowPostion.x, heroNowPostion.y);
    
}

b2World* GameManager::getWorld() {
    return world;
}

void GameManager::initRes()
{
    std::string path = FileUtils::getInstance()->fullPathForFilename("load.xml");
    ValueMap vm = FileUtils::getInstance()->getValueMapFromFile(path);
    for (int i = 0; i < vm.size(); i++)
    {
        char buf[12];
        sprintf(buf, "%d", i+1);
        std::string s = vm.at(buf).asString();
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(s);
    }
    vm.clear();
}

Animation* GameManager::getAnimation(const char* src, float delay, unsigned int loops)
{
    Vector<SpriteFrame*> frames;

    char _src[30];
    for(int i=0; i<10000; i++)
    {
        sprintf(_src, "%s%04d", src, i);
        SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(_src);
        if(sf == nullptr)
        {
            log("%s is null\n",_src);
            break;
        }
        frames.pushBack(sf);
    }
    return Animation::createWithSpriteFrames(frames, delay, loops);
}

cocos2d::Animate* GameManager::getAnimate(const char* src, float delay /*= 0.0f*/, unsigned int loops /*= 1U*/)
{
    Animation* animation = getAnimation(src, delay, loops);
    return Animate::create(animation);
}

//loading animation frames
/*void GameManager::initRes() {
    std::string path = FileUtils::getInstance()->fullPathForFilename("load.xml");
        ValueMap vm = FileUtils::getInstance()->getValueMapFromFile(path);
        for (int i = 0; i < vm.size(); i++)
        {
            char buf[12];
            sprintf(buf, "%d", i+1);
            std::string s = vm.at(buf).asString();
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile(s);
        }
	vm.clear();
}*/

//for getting the specific frames
/*cocos2d::Animation* GameManager::getAnimation(const char* src, float delay = 0.0f, unsigned int loops = 1U)
{
    
}


cocos2d::Animate* GameManager::getAnimate(const char* src, float delay = 0.0f, unsigned int loops = 1U) {
    Animation* animation = getAnimation(src, delay, loops);
	return Animate::create(animation);
}*/

void GameManager::pushDeleteSprite(PhysicsSprite* sprite) {
    _deleteSprites.pushBack(sprite);
}
void GameManager::BeginContact(b2Contact* contact) {
    GameObject* a = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
    GameObject* b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();
    
    a->BeginContact(b, contact);
    b->BeginContact(a, contact);
}

void GameManager::EndContact(b2Contact* contact) {
    GameObject* a = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
    GameObject* b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();
    
    a->EndContact(b, contact);
    b->EndContact(a, contact);
}

void GameManager::PreSolve(b2Contact* contact,const b2Manifold* oldManifold) {
    GameObject* a = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
    GameObject* b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();
    
    a->PreSolve(b, contact, oldManifold);
    b->PreSolve(a, contact, oldManifold);
}

void GameManager::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
    GameObject* a = (GameObject*)contact->GetFixtureA()->GetBody()->GetUserData();
    GameObject* b = (GameObject*)contact->GetFixtureB()->GetBody()->GetUserData();
    
    a->PostSolve(b, contact, impulse);
    b->PostSolve(a, contact, impulse);
}

