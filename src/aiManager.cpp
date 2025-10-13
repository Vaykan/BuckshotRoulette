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

void AIManager::setLastAction(Action lastAction) {}

void AIManager::setDropLastShell(ShellType shellType) {}

void AIManager::fillShellType() {
    for (int i = 0; i < 8; ++i) {
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_TYPE) + i * 2] = UNKNOWN;
    }
}

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
    auto value = magazine.size();
    if (value)
        neuralNetwork.neuronArray[0][static_cast<int>(InputNeurons::SHELL_HAVE) + value - 1 * 2] = IS_FILLED;
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
