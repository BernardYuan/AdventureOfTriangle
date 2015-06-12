//
//  Floor.h
//  Susi
//
//  Created by Bernard Yuan on 6/12/15.
//
//

#ifndef __Susi__Floor__
#define __Susi__Floor__

#include <stdio.h>
#include "GameObject.h"
USING_NS_CC;

class Floor :public GameObject
{
private:
    void initFloor();
public:
    virtual bool init(float x, float y, float width, float height) override;
    CREATE_FUNC_4(Floor, float, float, float, float);
    
    virtual bool init(float x, float y, b2Vec2* points, int count) override;
    CREATE_FUNC_4(Floor, float, float, b2Vec2*, int);
    
    virtual void PreSolve(GameObject* other, b2Contact* contact, const b2Manifold* oldManifold);
};

#endif /* defined(__Susi__Floor__) */
