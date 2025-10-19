#ifndef BUCKSHOT_ROULETTE_PLAYER_H
#define BUCKSHOT_ROULETTE_PLAYER_H



class Item;
class Shotgun;
class MyFrame;
class AIManager;

class Player {
private:
    std::string name;
    int hitPoint = 0;
    int maxHitPoint = 0;
    int maxItem = 8;
    bool dead = false;
    bool IsHandcuffed = false;
    bool isAdrenalineActive = false;

    bool isAI = false;

    std::vector<Item*> item;
    std::vector<Item*> itemStorage;
    std::vector<std::string> skipReason;

    Shotgun* shotgun;
    Player* target;

    AIManager* aiManager = nullptr;

    MyFrame* myFrame = nullptr;
public:
    Player();
    ~Player();

    void setName(std::string name);
    std::string getName();

    void changeHitPoint(int delta);
    void setHitPoint(int hitPoint);
    int getHitPoint() const;

    void setMaxHitPoint(int maxHitPoint);

    void setIsHandcuffed(bool isHandcuffed);
    bool isHandcuffed() const;

    bool getIsAdrenalineActive();
    void setIsAdrenalineActive(bool isAdrenalineActive);

    void setIsAI(bool isAI);
    bool getIsAI();

    void useItem(int index);
    void addRandomItems(int count);
    void setArrayItemSize(int size);
    int getItemCount();
    std::vector<Item*>& getItem();

    void setItemStorage(std::vector<Item*> itemStorage);
    std::vector<Item*>& getItemStorage();

    void setTarget(Player& target);
    Player* getTarget();

    void setShotgun(Shotgun& shotgun);
    Shotgun* getShotgun();

    void setAIManager(AIManager& aiManager);
    AIManager& getAIManager();

    void addSkipTurn(std::string reason);
    void decreaseSkipTurn();
    bool isSkipTurn() const;
    std::string getReasonSkipTurn();

    void setMyFrame(MyFrame& myFrame);
    MyFrame* getMyFrame();
};

#endif