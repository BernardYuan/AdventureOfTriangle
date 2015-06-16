//
//  Crystal.h
//  TestDemo
//
//  Created by Bernard Yuan on 6/16/15.
//
//

#ifndef __TestDemo__Crystal__
#define __TestDemo__Crystal__

#include <stdio.h>
#include "GameObject.h"
USING_NS_CC;
class  Crystal: public GameObject
{
public:
    virtual bool init(float x, float y, float width, float height);
    CREATE_FUNC_4(Crystal, float, float, float, float);
    
    virtual void PreSolve(GameObject* other, b2Contact* contact, const b2Manifold* oldManifold);
};

#endif /* defined(__TestDemo__Crystal__) */
