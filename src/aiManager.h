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

        MY_ITEM_CIGARETTE_COUNT,
        MY_ITEM_BEER_COUNT,
        MY_ITEM_ADRENALINE_COUNT,
        MY_ITEM_MAGNIFIER_COUNT,
        MY_ITEM_HANDCUFFS_COUNT,
        MY_ITEM_INVERTER_COUNT,
        MY_ITEM_SAW_COUNT,
        MY_ITEM_PHONE_COUNT,
        ENEMY_ITEM_CIGARETTE_COUNT,
        ENEMY_ITEM_BEER_COUNT,
        ENEMY_ITEM_ADRENALINE_COUNT,
        ENEMY_ITEM_MAGNIFIER_COUNT,
        ENEMY_ITEM_HANDCUFFS_COUNT,
        ENEMY_ITEM_INVERTER_COUNT,
        ENEMY_ITEM_SAW_COUNT,
        ENEMY_ITEM_PHONE_COUNT,

        MY_HIT_POINTS,
        ENEMY_HIT_POINTS,
        ENEMY_IS_HANDCUFFED

    };
    NeuralNetwork neuralNetwork;
    static constexpr float UNKNOWN = 0;
    static constexpr float IS_EMPTY = -1;
    static constexpr float IS_FILLED = 1;
public:
    void saveWeightsToFile();
    void loadWeightsFromFile();

    void setShellType(AIShellTypeState aiShellTypeState, int index);
    void fillShellType();

    void setShellLeft(int liveShellLeft, int blankShellLeft);

    void setLastAction(Action lastAction);
    void setDropLastShell(ShellType shellType);
};

#endif