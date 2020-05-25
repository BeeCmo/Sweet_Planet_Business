#pragma once

#include "cocos2d.h"


USING_NS_CC;

enum SpecializationType
{
    Textiles, 
    Mechanics,
    Food
};

enum ResourceTypes
{
    ResourceType_Workers,
    ResourceType_Moneys,
    ResourceType_Ships
};

enum PlayerType
{
    HumanWorker,
    HumanMoney,
    HumanTime,
    AlienWorker,
    AlienMoney,
    AlienTime,
    RobotWorker,
    RobotMoney,
    RobotTime
};

enum PlayerTypeBonusTypes
{
    BonusType_Workers,
    BonusType_Moneys,
    BonusType_Time
};


class Player
{
public:
    std::map<ResourceTypes, int> myResources;
   // std::vector<PlayerUpgrade> myUpgrades;
    PlayerType myType;


};

struct Product
{
    int myCreationCost;
    int myQuality;
    int myDurability;
    int myPrice;
};


struct Planet
{
    void Set(float aTextilesPreferences, float aMechanicsPreferences, float aFoodPreferences, int aClientsAmount, const std::string& aSpriteFile, Color3B aColor);

    std::map<SpecializationType, float> mySpecializationPreferences;
    int myClientsAmount;

    std::string mySpriteFilename;
    Color3B myColor;
};




//struct PlayerUpgrade
//{
//
//};


enum BuildableTypes
{
    Production,
    SaleOffice,
    WorkerHouse,
    Spaceship
};

struct Buildable
{
    Buildable(BuildableTypes, int, float) {}

    BuildableTypes myType;
    int myCost;
    float myBuildTime;
};




struct ProductionBuilding : public Buildable
{
    ProductionBuilding() : Buildable(BuildableTypes::Production, 10, 20) {}
    SpecializationType mySpecialization;
    float myProductionTime;
};

struct SaleOfficeBuilding : public Buildable
{
    SaleOfficeBuilding() : Buildable(BuildableTypes::SaleOffice, 5, 10) {}
    SpecializationType mySpecialization;
    int myproductsAmount;
};

struct WorkerHouseBuilding : public Buildable
{
    WorkerHouseBuilding() :Buildable(BuildableTypes::WorkerHouse, 10, 5) {}
    int myNewWorkersAmount;
};

struct SpaceshipBuildable : public Buildable
{
    SpaceshipBuildable() :Buildable(BuildableTypes::Spaceship, 2, 4) {}
    int myProductsAmount;
};  





class BuildingManager
{
public:
    void BuildNew(/*type*/) {}
    //takes resources
    //creates a task for a building
    //keeps tasks and recovers them from 
    //as soon as it finishesh

    std::map<BuildableTypes, float> myBuildingJobFinishTimes;
    std::map<BuildableTypes, int> myBuildableAmounts;

    std::string myCurrentPlanet;
    std::map<std::string, std::map<BuildableTypes, int>> myBuildableAmountsPerPlanet;
};






struct Test
{
    std::string myQuestion;
    std::map<int, std::string> myOptions;
    int myCorrectOption;
    int myReward;
};

class TestManager
{
    void LoadTests() {}
    void ShowTest(){}
    void GetReward() {}


};

class ConstantData
{

public:
    ConstantData();

    std::map<ResourceTypes, int> myStartingResourcesData;

    ProductionBuilding myProductionBuildingData;
    SaleOfficeBuilding mySaleOfficeBuildingData;
    WorkerHouseBuilding myWorkerHouseData;
    SpaceshipBuildable mySpaceshipData;

    //PlayerUpgrade myPlayerUpgradeData;
    std::vector<Test> myTestsData;



    struct PlayerTypeData
    {
        void Set(PlayerType aType, PlayerTypeBonusTypes aBonusType, float aBonusAmount, const std::string& aFileName);

        PlayerType myType;
        PlayerTypeBonusTypes myResourceBonusType;
        float myBonusPercentageAmount;
        std::string mySpriteFilename;
    };
    std::map<PlayerType, PlayerTypeData> myPlayerTypeData;

    std::map<std::string, Planet> myPlanetsData;
};





class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();






    bool init() override;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


    //void CreateMenueButton(const std::string& normalImage, const std::string& selectedImage, const ccMenuCallback& callback);



    void OpenOtherPlanetsCallback(cocos2d::Ref* pSender);
    void OpenFactoriesCallback(cocos2d::Ref* pSender);
    void OpenSaleOfficeCallback(cocos2d::Ref* pSender);
    void OpenShipsCallback(cocos2d::Ref* pSender);
    void OpenWorkerHouseesCallback(cocos2d::Ref* pSender);



    void ShowChooseCharacterUI();
    void ShowChoosePlanetUI();
    void ShowPlanetUI(const std::string& aPlanetID);
    void ShowPlanetInfo(const Vec2& aUILocation, const std::string& aPlanetID);

    Player myPlayer;
    ConstantData myConstantData;
    EventDispatcher myEventDispatcher;

    BuildingManager myBuildingManager;
};
