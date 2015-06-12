//
//  Floor.cpp
//  Susi
//
//  Created by Bernard Yuan on 6/12/15.
//
//

#include "Floor.h"
#include "StaticData.h"
USING_NS_CC;

void Floor::initFloor()
{
    this->getBody()->SetType(b2_staticBody);
    this->setType(TYPE_BRICK);
    this->setMask(
                  TYPE_HERO |
                  TYPE_ANIMAL |
                  TYPE_COIN |
                  TYPE_MONSTER |
                  TYPE_ARTICLE |
                  TYPE_WEAPON);
    //设置纹理-一般不用
    //this->setTexture(SD_STRING("brick_path_texture"));
}

bool Floor::init(float x, float y, float width, float height)
{
    if(!GameObject::init(x, y, width, height))
    {
        return false;
    }
    initFloor();
    return true;
}

bool Floor::init(float x, float y, b2Vec2* points, int count)
{
    if(!GameObject::init(x, y, points, count))
    {
        return false;
    }
    initFloor();
    return true;
}

void Floor::PreSolve(GameObject* other, b2Contact* contact, const b2Manifold* oldManifold)
{
    
    //碰撞之前的预处理，这是一种写法，可以学习一下
    /*if(other->getType() == TYPE_HERO || other->getType() == TYPE_MONSTER)
    {
        //如果在砖块下方，那么穿透，也就是实现了地板的单向碰撞
        float otherHeight = other->getBodyBoundingBoxHeight();
        float otherY = other->getPositionY() - otherHeight/2.0f;
        float y = this->getPositionY() + height/2.0f;
        if(otherY < y)
            contact->SetEnabled(false);
    }*/
}