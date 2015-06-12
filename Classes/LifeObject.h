//
//  LifeObject.h
//  Susi
//
//  Created by Bernard Yuan on 6/11/15.
//
//

#ifndef __Susi__LifeObject__
#define __Susi__LifeObject__

#include <stdio.h>
#include "GameObject.h"
USING_NS_CC;

class LifeObject: public GameObject
{
protected:
    bool die;
    bool over;
public:
    virtual bool init(float x, float y, float width, float height) override;
    CREATE_FUNC_4(LifeObject, float, float, float, float);
    
    
    virtual bool init(float x, float y, b2Vec2* points, int count) override;
    CREATE_FUNC_4(LifeObject, float, float, b2Vec2*, int);

    CC_SYNTHESIZE(int, hp, Hp);
    CC_SYNTHESIZE(DIR, dir, Dir);
    //CC_SYNTHESIZE(int, atk, Atk);

    virtual void setDie(bool die);
    virtual bool isDie() const;
    
    virtual void setOver(bool over);
    virtual bool isOver() const;
    
    virtual void update(float ft);
    virtual void dead();
    virtual void ended();
};

#endif /* defined(__Susi__LifeObject__) */
