//
//  PhysicSprite.cpp
//  Susi
//
//  Created by Bernard Yuan on 6/11/15.
//
//

#include "PhysicSprite.h"
#include "GameManager.h"
USING_NS_CC;
void PhysicsSprite::initBody(float x, float y, float width, float height) {
    b2World* world = GameManager::getInstance()->getWorld();
    //body
    b2BodyDef bodyDef;
    bodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
    bodyDef.type = b2_dynamicBody;
    body = world->CreateBody(&bodyDef);
    //fixture
    b2FixtureDef fixtureDef;
    b2PolygonShape shape;	//the collosion area
    shape.SetAsBox(width/2/PTM_RATIO, height/2/PTM_RATIO);
    fixtureDef.shape = &shape;
    fixture = body->CreateFixture(&fixtureDef);
    //store the pointer
    body->SetUserData(this);
}

void PhysicsSprite::initBody(float x, float y, b2Vec2* points, int count)  {
    b2World* world = GameManager::getInstance()->getWorld();
    //body
    b2BodyDef bodyDef;
    bodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
    bodyDef.type = b2_dynamicBody;
    body = world->CreateBody(&bodyDef);
    //fixture
    b2FixtureDef fixtureDef;
    b2PolygonShape shape;	//the collosion area
    shape.Set(points, count);
    fixtureDef.shape = &shape;
    fixture = body->CreateFixture(&fixtureDef);
    //store the pointer
    body->SetUserData(this);
}



bool PhysicsSprite::init(float x, float y, float width, float height) {
    if (!Sprite::init()) {
        return
        false;
    }
    this->width=width;
    this->height=height;
    
    initBody(x, y, width, height);
    return true;
}

bool PhysicsSprite::init(float x, float y, b2Vec2* points, int count) {
    if (!Sprite::init()) {
        return false;
    }
    
    initBody(x, y, points, count);
    return true;
}

void PhysicsSprite::setType(uint16 type) {
    b2Filter filter=fixture->GetFilterData();
    filter.categoryBits=type;
    fixture->SetFilterData(filter);
}


uint16 PhysicsSprite::getType() const{
    return fixture->GetFilterData().categoryBits;
}

void PhysicsSprite::setMask(uint16 type) {
    b2Filter filter=fixture->GetFilterData();
    filter.maskBits=type;
    fixture->SetFilterData(filter);
}

float PhysicsSprite::getBodyBoundingBoxWidth() {
    return width;
}

float PhysicsSprite::getBodyBoundingBoxHeight() {
    return height;
}

b2Body* PhysicsSprite::getBody() const {
    return body;
}

b2Fixture* PhysicsSprite::getFixture() const {
    return fixture;
}

void PhysicsSprite::setPhysicsSpritePosition(float x, float y) {
    this->setPosition(x,y);
    body->SetTransform(b2Vec2(x/PTM_RATIO,y/PTM_RATIO), 0);
}

void  PhysicsSprite::setPhysicsSpritePosition(cocos2d::Vec2 vec2) {
    this->setPosition(vec2);
    body->SetTransform(b2Vec2(vec2.x/PTM_RATIO,vec2.y/PTM_RATIO), 0);
}

void PhysicsSprite::setPhysicsPosition(float x, float y) {
    body->SetTransform(b2Vec2(x/PTM_RATIO,y/PTM_RATIO), 0);
}

void PhysicsSprite::setPhysicsPosition(cocos2d::Vec2 vec2) {
    body->SetTransform(b2Vec2(vec2.x/PTM_RATIO,vec2.y/PTM_RATIO), 0);
}
//You had better not use this
void PhysicsSprite::removePhysicsSprite() {
    if(body!=nullptr) {
        removeBody();
    }
    this->removeFromParent();
}
//You had better not use this
void PhysicsSprite::removeBody() {
    GameManager::getInstance()->getWorld()->DestroyBody(body);
    body=nullptr;
}
//the recommended way of removing physicsSprite
void PhysicsSprite::autoRemovePhysicsSprite() {
    GameManager::getInstance()->pushDeleteSprite(this);
}