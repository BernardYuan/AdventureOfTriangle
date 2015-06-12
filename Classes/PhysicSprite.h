//
//  PhysicSprite.h
//  Susi
//
//  Created by Bernard Yuan on 6/11/15.
//
//

#ifndef __Susi__PhysicSprite__
#define __Susi__PhysicSprite__

#include <stdio.h>
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "config.h"
#define GRAVITY 10
#define PTM_RATIO 96.0f



//Since I am quite lazy, I use these macros to get different kinds of create functions
#define CREATE_FUNC_1(varType, var1) \
public: static varType* create(var1 x) \
{\
    varType *pRet＝new varType();\
    if(pRet && pRe->init(x))\
    {\
        pRet->autoRelease();\
        return pRet;\
    }\
    else {\
        delete pRet;\
        pRet=NULL;\
        return NULL;\
    }\
}
#define CREATE_FUNC_2(varType, var1, var2)\
public: static varType* create(var1 x, var2 y)\
{\
    varType *pRet = new varType(); \
    if (pRet && pRet->init(x, y)) \
    { \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
}

#define CREATE_FUNC_3(varType, var1, var2, var3)\
public: static varType* create(var1 x, var2 y, var3 width)\
{\
    varType *pRet = new varType(); \
    if (pRet && pRet->init(x, y, width)) \
    { \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
}

#define CREATE_FUNC_4(varType, var1, var2, var3, var4)\
public: static varType* create(var1 x, var2 y, var3 width, var4 height)\
{\
    varType *pRet = new varType(); \
    if (pRet && pRet->init(x, y, width, height)) \
    { \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
}

#define CREATE_FUNC_5(varType, var1, var2, var3, var4, var5)\
public: static varType* create(var1 x, var2 y, var3 width, var4 height, var5 five)\
{\
    varType *pRet = new varType(); \
    if (pRet && pRet->init(x, y, width, height, five)) \
    { \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
}
class PhysicsSprite : public cocos2d::Sprite
{
protected:
    b2Body* body;
    b2Fixture* fixture;
    float width;
    float height;
public:
    //initialize the sprite
    virtual bool init(float x, float y, float width, float height);
    CREATE_FUNC_4(PhysicsSprite, float, float, float, float);
    
    virtual bool init(float x, float y, b2Vec2* points, int count);
    CREATE_FUNC_4(PhysicsSprite, float, float, b2Vec2*, int);
    
    //initialize physics body
    void initBody(float x, float y, float width, float height);
    void initBody(float x, float y, b2Vec2* points, int count);
    
    //for collision detection
    virtual void setType(uint16 type);  //set the type
    virtual uint16 getType() const;     //get the type
    virtual void setMask(uint16 types);

    //get box width
    virtual float getBodyBoundingBoxWidth();
    //get box height
    virtual float getBodyBoundingBoxHeight();
    
    //get physic body
    virtual b2Body* getBody() const;
    //get fixture
    virtual b2Fixture* getFixture() const;

    
    
    
    //set the position of the physics body and the  sprite
    virtual void setPhysicsSpritePosition(float x, float y);
    virtual void setPhysicsSpritePosition(cocos2d::Vec2 vec2);
    
    //set the position of the physics body
    virtual void setPhysicsPosition(float x, float y);
    virtual void setPhysicsPosition(cocos2d::Vec2 vec2);
    
    //remove the physics sprite  !!!Not Recommended
    virtual void removePhysicsSprite();
    
    //remove the physics body    !!!Not Recommended
    virtual void removeBody();
    
    //The recommended function of removing the physics body
    virtual void autoRemovePhysicsSprite();
    
};
#endif /* defined(__Susi__PhysicSprite__) */
