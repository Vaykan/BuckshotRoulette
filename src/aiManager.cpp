#include "aiManager.h"
#include "shotgun.h"
#include "items/item.h"


AIManager::AIManager() {
    magazine.reserve(8);
}

void AIManager::setHitPoint(int objectHitPoint, int subjectHitPoint) {

}

void AIManager::saveWeightsToFile() {
    neuralNetwork.saveWeightsToFile();
}

void AIManager::loadWeightsFromFile() {
    neuralNetwork.loadWeightsFromFile();
}

void AIManager::setLastAction(Action lastAction) {}

void AIManager::setDropLastShell(ShellType shellType) {}


void AIManager::setMagazineType(AIShellTypeState aiShellTypeState, int index) {
    float value;
    switch (aiShellTypeState) {
        case AIShellTypeState::LIVE:
            value = LIVE;
            break;
        case AIShellTypeState::BLANK:
            value = BLANK;
            break;
        default:
            std::abort();
    }
    magazine[index] = value;
}

void AIManager::loadMagazine(int count) {
    magazine.resize(count);
    for (auto& i : magazine) {
        i = UNKNOWN;
    }
}

void AIManager::syncMagazineAndShells(int liveShellLeft, int blankShellLeft) {
    setShellType();
    setShellHave();
    setShellLeft(liveShellLeft, blankShellLeft);
}

void AIManager::setShellType() {
    for (int i = 0; i < 8; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_TYPE) + i * 2] = UNKNOWN;
    }
    for (int i = 0; i < magazine.size(); ++i) {
        if (magazine[i] == LIVE)
            neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_TYPE) + i * 2] = LIVE;
        if (magazine[i] == BLANK)
            neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_TYPE) + i * 2] = BLANK;
    }
}

void AIManager::setShellHave() {
    for (int i = 0; i < 8; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_HAVE) + i * 2] = IS_EMPTY;
    }
    auto index = magazine.size();
    if (index)
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_HAVE) + index - 1 * 2] = IS_FILLED;
}

void AIManager::setShellLeft(int liveShellLeft, int blankShellLeft) {
    for (int i = 0; i < Shotgun::MAX_MAGAZINE / 2; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_LIVE_LEFT_0) + i] = IS_EMPTY;
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_BLANK_LEFT_0) + i] = IS_EMPTY;
    }
    neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_LIVE_LEFT_0) + liveShellLeft] = IS_FILLED;
    neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_BLANK_LEFT_0) + blankShellLeft] = IS_FILLED;
}

void AIManager::pumpingMagazine() {
    magazine.pop_back();
}

void AIManager::syncItemCount(std::vector<Item*>& myItem, std::vector<Item*>& enemyItem) {
    std::array<int, 9> myItemCounts{};
    if (!myItem.empty()) {
        for (auto& i: myItem) {
            myItemCounts[static_cast<int>(i->getItemType()) - 1] += 1;
        }
    }
    std::array<int, 9> enemyItemCounts{};
    if (!enemyItem.empty()) {
        for (auto& i: enemyItem) {
            enemyItemCounts[static_cast<int>(i->getItemType()) - 1] += 1;
        }
    }
    for (int i = 0; i < myItemCounts.size(); ++i) {
        float value = static_cast<float>(myItemCounts[i]) / 4 - 1;
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::MY_ITEM_PILL_COUNT) + i] = value;
    }
    for (int i = 0; i < enemyItemCounts.size(); ++i) {
        float value = static_cast<float>(enemyItemCounts[i]) / 4 - 1;
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::MY_ITEM_PILL_COUNT) + i] = value;
    }
}

void AIManager::syncHitPoints(int myHitPoints, int enemyHitPoints) {
    for (int i = 0; i < 4; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::MY_HIT_POINT_HAVE_1) + i] = IS_EMPTY;
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::ENEMY_HIT_POINT_HAVE_1) + i] = IS_EMPTY;
    }
    neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::MY_HIT_POINT_HAVE_1) + myHitPoints - 1] = IS_FILLED;
    neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::ENEMY_HIT_POINT_HAVE_1) + enemyHitPoints - 1] = IS_FILLED;
}
