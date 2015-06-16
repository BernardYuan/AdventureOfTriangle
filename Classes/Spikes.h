//
//  Spikes.h
//  TestDemo
//
//  Created by Bernard Yuan on 6/16/15.
//
//

#ifndef __TestDemo__Spikes__
#define __TestDemo__Spikes__

#include <stdio.h>
#include "GameObject.h"
USING_NS_CC;

class Spikes : public GameObject
{
private:
    int atk;
public:
    virtual bool init(float x, float y, float width, float height);
    CREATE_FUNC_4(Spikes, float, float, float, float);
    
    virtual void PreSolve(GameObject* other, b2Contact* contact, const b2Manifold* oldManifold);
    //virtual void BeginContact(GameObject* other, b2Contact* contact);
};

#endif /* defined(__TestDemo__Spikes__) */
