//
//  Crystal.cpp
//  TestDemo
//
//  Created by Bernard Yuan on 6/16/15.
//
//

#include "Crystal.h"
#include <stdio.h>
#include "GameObject.h"
#include "Hero.h"
#include "WinScene.h"
USING_NS_CC;

bool Crystal::init(float x, float y, float width, float height)
{
    if (!GameObject::init(x, y, width, height))
    {
        return false;
    }
    //atk = SD_INT("spikes_int_atk");
    
    this->setTexture(SD_CHARS("gem_path_texture"));
    this->getBody()->SetType(b2_staticBody);
    this->setType(TYPE_BRICK);
    this->setMask(TYPE_HERO);
    return true;
}

void Crystal::PreSolve(GameObject* other, b2Contact* contact, const b2Manifold* oldManifold)
{
    contact->SetEnabled(false);
    if (other->getType() == TYPE_HERO)
    {
        auto reScene=TransitionCrossFade::create(0.3f,WinScene::createScene());
        Director::getInstance()->replaceScene(reScene);
        //hero->setUnbeatable(SD_FLOAT("spikes_float_unbeatable"));
    }
}