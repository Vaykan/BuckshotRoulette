#ifndef BUCKSHOT_ROULETTE_EXE_AIMANAGER_H
#define BUCKSHOT_ROULETTE_EXE_AIMANAGER_H

#include "neural_network.h"
#include "enum.h"

enum class AIShellTypeState {
    LIVE,
    BLANK,
    UNKNOWN,
    EMPTY
};

enum class AIHitPoint {
    ONE,
    TWO,
    THREE,
    FOUR
};

enum class AIL;

class NeuralNetwork;
class Item;

class AIManager {
    enum class InputNeurons {
        // 1-8 - ammo
        // 2-4(1-4) - hp

        SHELL_HAVE,
        SHELL_TYPE,
        SHELL_HAVE_2,
        SHELL_TYPE_2,
        SHELL_HAVE_3,
        SHELL_TYPE_3,
        SHELL_HAVE_4,
        SHELL_TYPE_4,
        SHELL_HAVE_5,
        SHELL_TYPE_5,
        SHELL_HAVE_6,
        SHELL_TYPE_6,
        SHELL_HAVE_7,
        SHELL_TYPE_7,
        SHELL_HAVE_8,
        SHELL_TYPE_8,

        SHELL_LIVE_LEFT_0,
        SHELL_LIVE_LEFT_1,
        SHELL_LIVE_LEFT_2,
        SHELL_LIVE_LEFT_3,
        SHELL_LIVE_LEFT_4,
        SHELL_BLANK_LEFT_0,
        SHELL_BLANK_LEFT_1,
        SHELL_BLANK_LEFT_2,
        SHELL_BLANK_LEFT_3,
        SHELL_BLANK_LEFT_4,

        MY_ITEM_PILL_COUNT,
        MY_ITEM_CIGARETTE_COUNT,
        MY_ITEM_BEER_COUNT,
        MY_ITEM_ADRENALINE_COUNT,
        MY_ITEM_MAGNIFIER_COUNT,
        MY_ITEM_HANDCUFFS_COUNT,
        MY_ITEM_INVERTER_COUNT,
        MY_ITEM_SAW_COUNT,
        MY_ITEM_PHONE_COUNT,
        ENEMY_ITEM_PILL_COUNT,
        ENEMY_ITEM_CIGARETTE_COUNT,
        ENEMY_ITEM_BEER_COUNT,
        ENEMY_ITEM_ADRENALINE_COUNT,
        ENEMY_ITEM_MAGNIFIER_COUNT,
        ENEMY_ITEM_HANDCUFFS_COUNT,
        ENEMY_ITEM_INVERTER_COUNT,
        ENEMY_ITEM_SAW_COUNT,
        ENEMY_ITEM_PHONE_COUNT,

        MY_HIT_POINT_HAVE_1,
        MY_HIT_POINT_HAVE_2,
        MY_HIT_POINT_HAVE_3,
        MY_HIT_POINT_HAVE_4,
        ENEMY_HIT_POINT_HAVE_1,
        ENEMY_HIT_POINT_HAVE_2,
        ENEMY_HIT_POINT_HAVE_3,
        ENEMY_HIT_POINT_HAVE_4,

        ENEMY_IS_HANDCUFFED,
        SIZE

    };
    NeuralNetwork neuralNetwork;
    std::vector<float> magazine{};
    static constexpr float LIVE = 1;
    static constexpr float BLANK = -1;
    static constexpr float UNKNOWN = 0;
    static constexpr float IS_EMPTY = -1;
    static constexpr float IS_FILLED = 1;

    void setShellType();
    void setShellHave();
    void setShellLeft(int liveShellLeft, int blankShellLeft);
public:
    AIManager();



    void setMagazineType(AIShellTypeState aiShellTypeState, int index);
    void pumpingMagazine();
    void loadMagazine(int count);

    void syncHitPoints(int myHitPoints, int enemyHitPoints);
    void syncMagazineAndShells(int liveShellLeft, int blankShellLeft);
    void syncItemCount(std::vector<Item*>& myItem, std::vector<Item*>& enemyItem);

    void saveWeightsToFile();
    void loadWeightsFromFile();

    void setHitPoint(int objectHitPoint, int subjectHitPoint);
    void setLastAction(Action lastAction);
    void setDropLastShell(ShellType shellType);
};

#endif