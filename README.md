# SuxiAdventure
Project For Software Engineering

#Finished
re-encapsulation of cocos2d::Sprite with Box2D physics engine.
As Time is quite limited, only two classes are completed: Hero and Floor

#!!!!!TODO!!!!!!
- button need to be put on
- change the T’s A point  
- give the bound of the map  
- make a new map(longer! )
- death! (drop into water, encounter the obstacle, etc.) - and death scene
- sound effect(Alternative)
- logo, title and buttons(Alternative)  done by Bernard

#Todo:
##杨家琦需要关注的函数：

###GameManager:
initRes(̨)    从xml里面加载资源的。   里面的path要你修改。其他看着写。

getAinimation 这个方法好像是根据一个名字从cache里面获取一个动画帧的，但是我目前没有找到在哪里加载的cache（似乎是initRes,但是没有仔细研究不确定）。命名规则需要你来改一改。

getAnimate 这个方法本身和资源没有关系。但是和上述函数有关，所以我写了但是目前注释掉了。
###StaticData class
静态数据处理函数类
###TextData class
字符数据处理类
###MapAnalysis class  ！！！重要
地图处理类
需要注意的是这个是几乎所有资源的加载入口。把TMX做好之后就是从这里做接口的。英雄等各个物体都是在这里初始化。
###ConfigData class
配置数据
###DynamicData class
动态数据
###config.h 文件
一部分宏定义

###物理精灵封装
关于物理精灵：
	物理精灵一系列都已经封装好，但是目前我不知道有哪些需要做的类，但是英雄类已经ok。如果要加类的话基本都是仿照这个，里面有注释可以跟着看。
	物理精灵类的继承顺序为：

	physics sprite -> Gameobject ->LifeObject ->hero
###添加新的游戏元素
有生命的物体可以从LifeObject继承，然后仿写hero。
无生命的物体可以从GameObject继承， 然后仿写Floor
