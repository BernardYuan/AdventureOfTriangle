//
//  GameManager.h
//  Susi
//
//  Created by Bernard Yuan on 6/10/15.
//
//

#ifndef __Susi__GameManager__
#define __Susi__GameManager__

#include <stdio.h>
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PhysicSprite.h"
#include "Hero.h"
enum GAME_STATIC
{
    WIN,
    FAILED,
    PLAYING
};
class GameManager :public cocos2d::Ref, public b2ContactListener
{
private:
    static GameManager* gameManager;
    cocos2d::Vector<PhysicsSprite*> _deleteSprites;
    b2World* world;
    
    float sceneX;   //position of the screen
    float sceneY;
    GameManager();
public:
    cocos2d::Layer* staticLayer;
    cocos2d::Layer* bgLayer;
    cocos2d::Layer* objLayer;
    cocos2d::Layer* settingLayer;
    Hero* hero;
public:
    static GameManager* getInstance();
    static void destroyInstance();
    
    ~GameManager();
    
    void initPhysicsWorld(float);   //setup the physics world
    void step(float);   //update the physics world
    b2World* getWorld(); //get the physics world
    void initRes(); //initialize the resources
    
    
    cocos2d::Animation* getAnimation(const char* src, float delay = 0.0f, unsigned int loops = 1U);
    cocos2d::Animate* getAnimate(const char* src, float delay = 0.0f, unsigned int loops = 1U);
    
    void pushDeleteSprite(PhysicsSprite* sprite);
    
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
};

#endif /* defined(__Susi__GameManager__) */
