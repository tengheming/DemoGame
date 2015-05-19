#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto rect = DrawNode::create();
    rect->drawRect(Vec2(0,0), Vec2(300,300), Color4F(1.0, 0, 0, 1.0));
    addChild(rect);
    
    auto dot = DrawNode::create();
    dot->drawDot(Vec2(0,0), 10, Color4F(1.0,1.0,1.0,1.0));
    rect->addChild(dot);
    
    auto cir = DrawNode::create();
    cir->drawLine(Vec2(0,0), Vec2(100,100), Color4F(1.0,1.0,1.0,1.0));
    rect->addChild(cir);
    
    rect->setPosition(visibleSize/2);
    dot->setPosition(10,10);
    rect->setContentSize(Size(300, 300));
    rect->setAnchorPoint(Vec2(0.5,0.5));
   
    schedule([rect,dot](float f){
    
        rect->setRotation(rect->getRotation()+1);
    }, "test");
    
   
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
