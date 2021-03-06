//
//  FinishScene.h
//  TestDemo
//
//  Created by Bernard Yuan on 6/16/15.
//
//

#ifndef __TestDemo__FinishScene__
#define __TestDemo__FinishScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class FinishScene : public Layer {
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    void menuReStartCallback(cocos2d::Ref*);
    void menuExitCallback(cocos2d::Ref*);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(FinishScene);
};
#endif /* defined(__TestDemo__FinishScene__) */
