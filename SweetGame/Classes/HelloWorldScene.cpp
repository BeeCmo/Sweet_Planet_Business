#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"



//#include "2d/CCSprite.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    const Size& visibleSize = Director::getInstance()->getVisibleSize();
    const Vec2& origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //                                       "CloseNormal.png",
    //                                       "CloseSelected.png",
    //                                       CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    //
    //if (closeItem == nullptr ||
    //    closeItem->getContentSize().width <= 0 ||
    //    closeItem->getContentSize().height <= 0)
    //{
    //    problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    //}
    //
    //// create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + closeItem->getContentSize().height / 2 + visibleSize.height / 2));
    //this->addChild(menu, 10);






   //auto MenuItem1 = MenuItemImage::create(
   //    "CloseNormal.png",
   //    "CloseSelected.png",
   //    CC_CALLBACK_1(HelloWorld::OpenOtherPlanetsCallback, this));
   //
   //MenuItem1->setColor(Color3B::BLUE);
   //MenuItem1->setName("Other Planets");
   //
   //
   //auto MenuItem2 = MenuItemImage::create(
   //    "CloseNormal.png",
   //    "CloseSelected.png",
   //    CC_CALLBACK_1(HelloWorld::OpenFactoriesCallback, this));
   //
   //MenuItem2->setColor(Color3B::RED);
   //MenuItem2->setName("Factories");
   //
   //auto MenuItem3 = MenuItemImage::create(
   //    "CloseNormal.png",
   //    "CloseSelected.png",
   //    CC_CALLBACK_1(HelloWorld::OpenSaleOfficeCallback, this));
   //
   //MenuItem3->setColor(Color3B::YELLOW);
   //MenuItem3->setName("Sale Office");
   //
   //auto MenuItem4 = MenuItemImage::create(
   //    "CloseNormal.png",
   //    "CloseSelected.png",
   //    CC_CALLBACK_1(HelloWorld::OpenShipsCallback, this));
   //
   //MenuItem4->setColor(Color3B::GREEN);
   //MenuItem4->setName("Ships");


    // create menu, it's an autorelease object
   // auto menu = Menu::create(OtherPlanetsMenuItem, NULL);
    //menu->addChild(MenuItem1);
    //menu->addChild(MenuItem2);
    //menu->addChild(MenuItem3);
    //menu->addChild(MenuItem4);
    //
    //menu->alignItemsHorizontally();





    // OpenOtherPlanetsCallback
    // OpenFactoriesCallback(co
    // OpenSaleOfficeCallback(c
    // OpenShipsCallback(cocos2
    // OpenWorkerHouseesCallbac
    //







    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

  




    //auto labelName = Label::createWithTTF("Sweet Planet", "fonts/Marker Felt.ttf", 24);
    //if (labelName == nullptr)
    //{
    //    problemLoading("'fonts/Marker Felt.ttf'");
    //}
    //else
    //{
    //    // position the label on the center of the screen
    //    labelName->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                            origin.y + visibleSize.height - labelName->getContentSize().height));
    //
    //    // add the label as a child to this layer
    //    addChild(labelName, 5);
    //}


    //auto planetSprite = Sprite::create("Planet2.png");
    //if (planetSprite == nullptr)
    //{
    //    problemLoading("'Planet2.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    planetSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //
    //    // add the sprite as a child to this layer
    //    addChild(planetSprite, 5);
    //}
    //
    //auto ResourcesPane = Sprite::create("base.png");
    //if (ResourcesPane == nullptr)
    //{
    //    problemLoading("'base.png'");
    //}
    //else
    //{
    //    ResourcesPane->setPosition(Vec2(ResourcesPane->getContentSize().width / 2, visibleSize.height / 2 + origin.y));
    //    addChild(ResourcesPane, 9);
    //}
    //
    Sprite* Background = Sprite::create("Background.png");
    Background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    addChild(Background, 0);
    

    ShowChooseCharacterUI();



    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}






void HelloWorld::ShowChooseCharacterUI()
{
    const Size& visibleSize = Director::getInstance()->getVisibleSize();
    const Vec2& origin = Director::getInstance()->getVisibleOrigin();
    
    Menu* chooseCharacterMenu = Menu::create();
    addChild(chooseCharacterMenu, 20);

    for (const auto& data : myConstantData.myPlayerTypeData)
    {
        MenuItemImage* playerTypeMenuItem = MenuItemImage::create(
            data.second.mySpriteFilename, 
            data.second.mySpriteFilename,
            [this, data, chooseCharacterMenu](cocos2d::Ref* pSender)
        {
            myPlayer.myType = data.second.myType;
            myPlayer.myResources = myConstantData.myStartingResourcesData;
            ShowChoosePlanetUI();
            removeChild(chooseCharacterMenu);
        });
         
        chooseCharacterMenu->addChild(playerTypeMenuItem);
    }

    chooseCharacterMenu->alignItemsInRows(3, 3, 3);
    chooseCharacterMenu->setPosition(Vec2(origin.x + visibleSize.width / 2.0f, origin.y + visibleSize.height / 2.0f + chooseCharacterMenu->getContentSize().height / 4.0f));
}



void HelloWorld::ShowChoosePlanetUI()
{
    const Size& visibleSize = Director::getInstance()->getVisibleSize();
    const Vec2& origin = Director::getInstance()->getVisibleOrigin();

    Menu* choosePlanetMenu = Menu::create();
    addChild(choosePlanetMenu, 20);
   
    const float widthStep = visibleSize.width / 3.0f;
    const float heightStep = visibleSize.height / 3.0f;
    int widthIndex = 0;
    int heightIndex = 0;

    for (const auto& data : myConstantData.myPlanetsData)
    {
        MenuItemImage* planetMenuItem = MenuItemImage::create(
            data.second.mySpriteFilename,
            data.second.mySpriteFilename,
            [this, data, choosePlanetMenu](cocos2d::Ref* pSender)
        {
            myBuildingManager.myCurrentPlanet = data.first;
            removeChild(choosePlanetMenu);
            ShowPlanetUI(data.first);
        });

        planetMenuItem->setColor(data.second.myColor);
        planetMenuItem->setPosition(Vec2(widthStep / 2.0f + widthStep * widthIndex, origin.y + heightStep / 2.0f + heightStep * heightIndex));
        const float scaleRand = cocos2d::random(0.3f, 1.0f);
        planetMenuItem->setScale(scaleRand, scaleRand);

        ++widthIndex;
        if (widthIndex > 2)
        {
            widthIndex = 0;
            ++heightIndex;
        }

        auto mouseListener = EventListenerMouse::create();
        mouseListener->onMouseMove = [this, planetMenuItem, data](EventMouse* event)
        {
            if (planetMenuItem->getBoundingBox().containsPoint(event->getLocation()))
                ShowPlanetInfo(event->getLocation(), data.first);
        };
        
        myEventDispatcher.addEventListenerWithSceneGraphPriority(mouseListener, this);
        choosePlanetMenu->addChild(planetMenuItem);
    }

    //choosePlanetMenu->alignItemsInRows(3, 3, 3);
    choosePlanetMenu->setPosition(Vec2::ZERO);
}

void HelloWorld::ShowPlanetUI(const std::string& aPlanetID)
{
    const Size& visibleSize = Director::getInstance()->getVisibleSize();
    const Vec2& origin = Director::getInstance()->getVisibleOrigin();

    Label* planetName = Label::createWithTTF(aPlanetID, "fonts/Marker Felt.ttf", 24);
    planetName->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - planetName->getContentSize().height));

    addChild(planetName, 5);
    
    Sprite* planetSprite = Sprite::create(myConstantData.myPlanetsData[aPlanetID].mySpriteFilename);
    planetSprite->setColor(myConstantData.myPlanetsData[aPlanetID].myColor);
    planetSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    planetSprite->setScale(2.0f, 2.0f);
    addChild(planetSprite, 5);




 






    auto MenuItem1 = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::OpenOtherPlanetsCallback, this));
    
    MenuItem1->setColor(Color3B::BLUE);
    MenuItem1->setName("Other Planets");
    
    
    auto MenuItem2 = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::OpenFactoriesCallback, this));
    
    MenuItem2->setColor(Color3B::RED);
    MenuItem2->setName("Factories");
    
    auto MenuItem3 = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::OpenSaleOfficeCallback, this));
    
    MenuItem3->setColor(Color3B::YELLOW);
    MenuItem3->setName("Sale Office");
    
    auto MenuItem4 = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::OpenShipsCallback, this));
    
    MenuItem4->setColor(Color3B::GREEN);
    MenuItem4->setName("Ships");
    
   
    Menu* planetMenu = Menu::create(MenuItem1, MenuItem2, MenuItem3, MenuItem4, NULL);
    planetMenu->alignItemsHorizontally();
    planetMenu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    addChild(planetMenu, 10);

    Sprite* ResourcesPane = Sprite::create("base.png");
    ResourcesPane->setPosition(Vec2(ResourcesPane->getContentSize().width / 2, visibleSize.height / 2 + origin.y));
    addChild(ResourcesPane, 9);

    Sprite* characterImage = Sprite::create(myConstantData.myPlayerTypeData[myPlayer.myType].mySpriteFilename);
    characterImage->setPosition(Vec2(ResourcesPane->getPosition().x, ResourcesPane->getPosition().y + ResourcesPane->getContentSize().height/4.0f));
    addChild(characterImage, 9);

    Sprite* resourceIconMoneys = Sprite::create("icon_money.png");
    resourceIconMoneys->setPosition(ResourcesPane->getPosition().x - ResourcesPane->getContentSize().width/4.0f, 
                                    ResourcesPane->getPosition().y + resourceIconMoneys->getContentSize().height*2.0f);
    ResourcesPane->addChild(resourceIconMoneys, 10);
    Sprite* resourceIconShip = Sprite::create("icon_ship.png");
    resourceIconShip->setPosition(ResourcesPane->getPosition().x - ResourcesPane->getContentSize().width/4.0f,
                                  ResourcesPane->getPosition().y + resourceIconShip->getContentSize().height/2.0f);
    ResourcesPane->addChild(resourceIconShip, 10);
    Sprite* resourceIconWorker = Sprite::create("icon_worker.png");
    resourceIconWorker->setPosition(ResourcesPane->getPosition().x - ResourcesPane->getContentSize().width/4.0f,
                                    ResourcesPane->getPosition().y - resourceIconWorker->getContentSize().height);

    ResourcesPane->addChild(resourceIconWorker, 10);

    Label* resourceLableMoneys = Label::createWithTTF(std::to_string(myPlayer.myResources[ResourceTypes::ResourceType_Moneys]), "fonts/Marker Felt.ttf", 24);
    resourceLableMoneys->setPosition(resourceIconMoneys->getPosition().x + resourceIconMoneys->getContentSize().width, resourceIconMoneys->getPosition().y);
    ResourcesPane->addChild(resourceLableMoneys, 11);
    Label* resourceLableWorkers = Label::createWithTTF(std::to_string(myPlayer.myResources[ResourceTypes::ResourceType_Workers]), "fonts/Marker Felt.ttf", 24);
    resourceLableWorkers->setPosition(resourceIconWorker->getPosition().x + resourceIconWorker->getContentSize().width, resourceIconWorker->getPosition().y);
    ResourcesPane->addChild(resourceLableWorkers, 11);
    Label* resourceLableShips = Label::createWithTTF(std::to_string(myPlayer.myResources[ResourceTypes::ResourceType_Ships]), "fonts/Marker Felt.ttf", 24);
    resourceLableShips->setPosition(resourceIconShip->getPosition().x + resourceIconShip->getContentSize().width, resourceIconShip->getPosition().y);
    ResourcesPane->addChild(resourceLableShips, 11);
}

void HelloWorld::ShowPlanetInfo(const Vec2& aUILocation, const std::string& aPlanetID)
{
    Layer* planetInfoLayer = Layer::create();
    addChild(planetInfoLayer);



}
















void HelloWorld::OpenOtherPlanetsCallback(cocos2d::Ref* pSender){}
void HelloWorld::OpenFactoriesCallback(cocos2d::Ref* pSender){}
void HelloWorld::OpenSaleOfficeCallback(cocos2d::Ref* pSender){}
void HelloWorld::OpenShipsCallback(cocos2d::Ref* pSender){}
void HelloWorld::OpenWorkerHouseesCallback(cocos2d::Ref* pSender){}


























    void Planet::Set(float aTextilesPreferences, float aMechanicsPreferences, float aFoodPreferences, int aClientsAmount, const std::string& aSpriteFile, Color3B aColor)
    {
        mySpecializationPreferences[SpecializationType::Textiles] = aTextilesPreferences;
        mySpecializationPreferences[SpecializationType::Mechanics] = aMechanicsPreferences;
        mySpecializationPreferences[SpecializationType::Food] = aFoodPreferences;
        myClientsAmount = aClientsAmount;
        mySpriteFilename = aSpriteFile;
        myColor = aColor;
    }













    ConstantData::ConstantData() // loading
    {
        myStartingResourcesData[ResourceTypes::ResourceType_Workers] = 4;
        myStartingResourcesData[ResourceTypes::ResourceType_Moneys] = 20;
        myStartingResourcesData[ResourceTypes::ResourceType_Ships] = 1;

        myPlayerTypeData[PlayerType::HumanWorker].Set(PlayerType::HumanWorker, PlayerTypeBonusTypes::BonusType_Workers, 0.5f, "Race_human.png");
        myPlayerTypeData[PlayerType::HumanMoney].Set(PlayerType::HumanMoney, PlayerTypeBonusTypes::BonusType_Moneys, 0.5f, "Race_human2.png");
        myPlayerTypeData[PlayerType::HumanTime].Set(PlayerType::HumanTime, PlayerTypeBonusTypes::BonusType_Time, 0.5f, "Race_human3.png");
        myPlayerTypeData[PlayerType::AlienWorker].Set(PlayerType::AlienWorker, PlayerTypeBonusTypes::BonusType_Workers, 0.5f, "Race_inhuman.png");
        myPlayerTypeData[PlayerType::AlienMoney].Set(PlayerType::AlienMoney, PlayerTypeBonusTypes::BonusType_Moneys, 0.5f, "Race_inhuman2.png");
        myPlayerTypeData[PlayerType::AlienTime].Set(PlayerType::AlienTime, PlayerTypeBonusTypes::BonusType_Time, 0.5f, "Race_inhuman3.png");
        myPlayerTypeData[PlayerType::RobotWorker].Set(PlayerType::RobotWorker, PlayerTypeBonusTypes::BonusType_Workers, 0.5f, "Race_robot.png");
        myPlayerTypeData[PlayerType::RobotMoney].Set(PlayerType::RobotMoney, PlayerTypeBonusTypes::BonusType_Moneys, 0.5f, "Race_robot2.png");
        myPlayerTypeData[PlayerType::RobotTime].Set(PlayerType::RobotTime, PlayerTypeBonusTypes::BonusType_Time, 0.5f, "Race_robot3.png");

        myPlanetsData["Planet1_Textiles"].Set(0.5f, 0.3f, 0.2f, 50, "Planet1.png", Color3B::WHITE);
        myPlanetsData["Planet2_Textiles"].Set(0.6f, 0.2f, 0.2f, 60, "Planet2.png", Color3B::RED);
        myPlanetsData["Planet3_Textiles"].Set(0.7f, 0.1f, 0.2f, 100, "Planet3.png", Color3B::BLUE);

        myPlanetsData["Planet1_Mechanics"].Set(0.3f, 0.5f, 0.2f, 50, "Planet1.png", Color3B::BLUE);
        myPlanetsData["Planet2_Mechanics"].Set(0.2f, 0.6f, 0.2f, 60, "Planet2.png", Color3B::WHITE);
        myPlanetsData["Planet3_Mechanics"].Set(0.1f, 0.7f, 0.2f, 100, "Planet3.png", Color3B::RED);

        myPlanetsData["Planet1_Food"].Set(0.3f, 0.2f, 0.5f, 50, "Planet1.png", Color3B::RED);
        myPlanetsData["Planet2_Food"].Set(0.2f, 0.2f, 0.6f, 60, "Planet2.png", Color3B::BLUE);
        myPlanetsData["Planet3_Food"].Set(0.1f, 0.2f, 0.7f, 100, "Planet3.png", Color3B::WHITE);
    }


        void ConstantData::PlayerTypeData::Set(PlayerType aType, PlayerTypeBonusTypes aBonusType, float aBonusAmount, const std::string& aFileName)
        {
            myType = aType;
            myResourceBonusType = aBonusType;
            myBonusPercentageAmount = aBonusAmount;
            mySpriteFilename = aFileName;
        }