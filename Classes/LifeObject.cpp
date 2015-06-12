//
//  LifeObject.cpp
//  Susi
//
//  Created by Bernard Yuan on 6/11/15.
//
//

#include "LifeObject.h"
USING_NS_CC;

bool LifeObject::init(float x, float y, float width, float height)
{
    if(!GameObject::init(x, y, width, height))
        return false;
    hp = 1;
    //atk = 0;
    die = false;
    over = false;
    
    scheduleUpdate();
    return true;
}

bool LifeObject::init(float x, float y, b2Vec2* points, int count)
{
    if(!GameObject::init(x, y, points, count))
        return false;
    hp = 1;
    //atk = 0;
    die = false;
    over = false;
    
    scheduleUpdate();
    return true;
}

void LifeObject::setDie(bool die)
{
    this->die = die;
}

bool LifeObject::isDie() const
{
    return die;
}

void LifeObject::setOver(bool over)
{
    this->over = over;
}

bool LifeObject::isOver() const
{
    return over;
}

void LifeObject::update(float ft)
{
    if(hp <= 0 && !die)
    {
        dead();
    }
}

void LifeObject::dead()
{
    die = true;
}

void LifeObject::ended()
{
    over = true;
}
