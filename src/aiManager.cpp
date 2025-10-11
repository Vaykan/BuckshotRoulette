#include "aiManager.h"
#include "shotgun.h"

AIManager::AIManager() {
    magazine.reserve(8);
}


void AIManager::saveWeightsToFile() {
    neuralNetwork.saveWeightsToFile();
}

void AIManager::loadWeightsFromFile() {
    neuralNetwork.loadWeightsFromFile();
}

void AIManager::setShellType(AIShellTypeState aiShellTypeState, int index) {
    double value;
    switch (aiShellTypeState) {
        case AIShellTypeState::LIVE:
            value = 1;
            break;
        case AIShellTypeState::BLANK:
            value = -1;
            break;
        default:
            std::abort();
    }
    neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_TYPE) + index * 2] = value;
}

void AIManager::fillShellType() {
    for (int i = 0; i < 8; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_TYPE) + i * 2] = UNKNOWN;
    }
}

void AIManager::setLastAction(Action lastAction) {}

void AIManager::setDropLastShell(ShellType shellType) {}

void AIManager::setShellLeft(int liveShellLeft, int blankShellLeft) {
    for (int i = 0; i < Shotgun::MAX_MAGAZINE / 2; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_LIVE_LEFT_0) + i] = IS_EMPTY;
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_BLANK_LEFT_0) + i] = IS_EMPTY;
    }
    neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_LIVE_LEFT_0) + liveShellLeft] = IS_FILLED;
    neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_BLANK_LEFT_0) + blankShellLeft] = IS_FILLED;
}


void AIManager::loadMagazine(int count) {
    magazine.resize(count);
    for (auto& i : magazine) {
        i = UNKNOWN;
    }
}

void AIManager::syncMagazine(std::vector<ShellType>* magazine) {
    while (magazine->size() != this->magazine.size()) {
        this->magazine.pop_back();
    }
    setShellHave();
}

void AIManager::setShellHave() {
    for (int i = 0; i < 8; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_HAVE) + i * 2] = IS_EMPTY;
    }
    int value = magazine.size();
    if (value)
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_HAVE) + value - 1 * 2] = IS_FILLED;
}