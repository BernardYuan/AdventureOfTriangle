//
//  Hero.h
//  Susi
//
//  Created by Bernard Yuan on 6/11/15.
//
//

#ifndef __Susi__Hero__
#define __Susi__Hero__

#include <stdio.h>
#include "LifeObject.h"
#include "StaticData.h"
class Hero :public LifeObject
{
protected:
    bool startTag;
    int jumpCount;
    //int coin;
    //bool unbeatable;
    //float unbeatableTime;
    
    
    /*运动状态 moveState*/
    CC_SYNTHESIZE(MOVE, moveState, MoveState);
    /*弹跳力 spring*/
    CC_SYNTHESIZE(float , spring, Spring);
    /*速度 speed*/
    CC_SYNTHESIZE(float , speed, Speed);
public:
    bool moved;     //used for scroll map
    virtual void initParam();
    virtual bool init(float x, float y, float width, float height) override;
    CREATE_FUNC_4(Hero, float, float, float, float);
    
    virtual bool init(float x, float y, b2Vec2* points, int count) override;
    CREATE_FUNC_4(Hero, float, float, b2Vec2*, int);
    
    virtual void dead() override;
    virtual void ended() override;
    
    //void setCoin(int coin);
    //int getCoin();
    
    virtual void moveStop();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void jump();
    
    //virtual void fire();
    
    //virtual void setUnbeatable(float time);
    //virtual bool isUnbeatable();
    
    virtual void update(float ft) override;
    virtual void BeginContact(GameObject* other, b2Contact* contact);
    //virtual void setHp(int hp);
};

#endif /* defined(__Susi__Hero__) */
