//
//  Hero.cpp
//  Susi
//
//  Created by Bernard Yuan on 6/11/15.
//
//

#include "Hero.h"
#include "GameManager.h"
#include "HelloWorldScene.h"
#include "FinishScene.h"
USING_NS_CC;

void Hero::initParam() {    //initialize the parameters
    moved=false;
    startTag=true;
    jumpCount=0;
    //setCoin(0);
    //unbeatable=false;
    //unbeatableTime=0;
    speed = SD_FLOAT("hero_float_speed");
    spring = SD_FLOAT("hero_float_spring");
    moveState=MOVE_STOP;
    this->setDir(DIR_RIGHT);
    
    //this->setHp();
    this->getBody()->SetFixedRotation(true);
    
    b2MassData  mass;
    mass.mass=SD_FLOAT("hero_float_mass");
    mass.I=SD_FLOAT("hero_float_i");
    mass.center = this->getBody()->GetLocalCenter();
    this->getBody()->SetMassData(&mass);
    this->setType(TYPE_HERO);
    this->setMask(TYPE_BRICK |
                  TYPE_COIN |
                  TYPE_MONSTER |
                  TYPE_PRIZE |
                  TYPE_ARTICLE |
                  TYPE_WEAPON);
    moveStop();
}

bool Hero::init(float x, float y, float width, float height) {    //first initializer
    if (!LifeObject::init(x,y,width,height)) {
        return false;
    }
    initParam();
    return true;
}

bool Hero::init(float x, float y, b2Vec2* points, int count) {      //alternative initializer
    if (!LifeObject::init(x,y,points,count)) {
        return false;
    }
    initParam();
    return true;
}

void Hero::dead() {     //dying
    LifeObject::dead();
    
    setMask(TYPE_BRICK);
    this->moveStop();
    Animate* animate = GameManager::getInstance()->getAnimate(SD_CHARS("hero_animate_dead"), SD_FLOAT("hero_float_dead_speed"));
    Action* action = Sequence::createWithTwoActions(animate, CallFunc::create(CC_CALLBACK_0(Hero::ended, this)));
    this->stopAllActions();
    this->runAction(action);

}

void Hero::ended() {   //ended
    LifeObject::ended();
    //restart
    auto restart = FinishScene::createScene();
    Director::getInstance()->replaceScene(restart);
}

//void Hero::setCoin(int coin) {
    
//}

//int getCoin() {
    
//}

void Hero::moveStop() {   //stop moving
    if (!startTag&&moveState==MOVE_STOP) {
        return;
    }
    startTag=false;
    moveState=MOVE_STOP;
    b2Vec2 vec=this->getBody()->GetLinearVelocity();
    vec.x=0;
    this->getBody()->SetLinearVelocity(vec);
    
    Animate* animate = GameManager::getInstance()->getAnimate(SD_CHARS("hero_animate_stop"), SD_FLOAT("hero_float_stop_speed"));
    this->stopAllActions();
    this->runAction(RepeatForever::create(animate));
    moved = false;
}

void Hero::moveLeft() { //moving left
    if (moveState==MOVE_LEFT) {
        return ;
    }
    if (isDie()||isOver()) {
        return ;
    }
    this->setDir(DIR_LEFT);
    moveState=MOVE_LEFT;
    Animate* animate = GameManager::getInstance()->getAnimate(SD_CHARS("hero_animate_walk_left"), SD_FLOAT("hero_float_walk_left_speed"));
    this->stopAllActions();
    this->runAction(RepeatForever::create(animate));
    moved = true;
}

void Hero::moveRight() {  //moving right
    if (moveState==MOVE_RIGHT) {
        return ;
    }
    if (isDie()||isOver()) {
        return ;
    }
    this->setDir(DIR_RIGHT);
    moveState=MOVE_RIGHT;
    Animate* animate = GameManager::getInstance()->getAnimate(SD_CHARS("hero_animate_walk_right"), SD_FLOAT("hero_float_walk_right_speed"));
    this->stopAllActions();
    this->runAction(RepeatForever::create(animate));
    moved = true;
}

void Hero::jump() {  //jumping
    if (jumpCount>=2) {
        return ;
    }
    if (isDie()||isOver()) {
        return ;
    }
    b2Vec2 vec=this->getBody()->GetLinearVelocity();
    vec.y=spring;
    this->getBody()->SetLinearVelocity(vec);
    moved = true;
    jumpCount++;
}

//virtual void fire(){}
//virtual void setUnbeatable(float time) {}
//virtual bool isUnbeatable() {}

void Hero::update(float ft)  {     //updating the heroe's state
    LifeObject::update(ft);
    //move left
    if(moveState == MOVE_LEFT)
    {
        b2Vec2 vec = this->getBody()->GetLinearVelocity();
        vec.x = -speed;
        this->getBody()->SetLinearVelocity(vec);
    }
    //move right
    else if(moveState == MOVE_RIGHT)
    {
        b2Vec2 vec = this->getBody()->GetLinearVelocity();
        vec.x = speed;
        this->getBody()->SetLinearVelocity(vec);
    }
    /*
    unbeatableTime = unbeatableTime - ft;
    if (unbeatableTime <= 0)
        unbeatable = false;*/
}

void Hero::BeginContact(GameObject* other, b2Contact* contact) {   //dealing with the contact
    if(other->getType() == TYPE_BRICK )         //if touches the bricks, stop jumping
    {   //if jump on the floor
        //get the direction of the bouncing force
        float y = contact->GetManifold()->localNormal.y;
        if (y > 0)
        { //on the floor
            jumpCount = 0;	//jump count to zero
        }
    }
    //else if (other->getType() == TYPE_ARTICLE)
    //{
    //    jumpCount = 0;
    //}
}



