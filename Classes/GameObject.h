//
//  GameObject.h
//  Susi
//
//  Created by Bernard Yuan on 6/11/15.
//
//

#ifndef __Susi__GameObject__
#define __Susi__GameObject__

#include <stdio.h>
#include "PhysicSprite.h"

class GameObject: public PhysicsSprite
{
public:
    virtual bool init(float x, float y, float width, float height) override;
    CREATE_FUNC_4(GameObject, float, float, float, float);
    
    virtual bool init(float x, float y, b2Vec2* points, int count) override;
    CREATE_FUNC_4(GameObject, float, float, b2Vec2*, int);
    
    virtual void BeginContact(GameObject* other, b2Contact* contact);
    virtual void EndContact(GameObject* other, b2Contact* contact);
    virtual void PreSolve(GameObject* other, b2Contact* contact, const b2Manifold* oldManifold);
    virtual void PostSolve(GameObject* other, b2Contact* contact, const b2ContactImpulse* impulse);
};

#endif /* defined(__Susi__GameObject__) */
