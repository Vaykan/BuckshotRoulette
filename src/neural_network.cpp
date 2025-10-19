#include <iostream>
#include <cmath>
#include <fstream>

#include "neural_network.h"

void NeuralNetwork::createNeuronArray(std::vector<int> neuroneCount) {
    neuronArray.resize(neuroneCount.size());
    for (int i = 0; i < neuronArray.size(); ++i) {
        neuronArray[i].resize(neuroneCount[i]);
    }
}

void NeuralNetwork::createWeightArray() {
    int count = 0;
    for (int i = 0; i < neuronArray.size() - 1; ++i) {
        count += static_cast<int> (neuronArray[i].size() * neuronArray[i + 1].size());
    }
    weightArray.resize(count);
}

void NeuralNetwork::changeWeights(double (* randomFunction)()) {
    for (auto& i: weightArray) {
        i += randomFunction();
    }
}

void NeuralNetwork::calculateNeuronValue() {
    int weightIndex = 0;
    for (int i = 0; i < neuronArray.size() - 1; ++i) {
        for (int j = 0; j < neuronArray[i + 1].size(); ++j) {
            double neuronValue = 0;
            for (double k: neuronArray[i]) {
                neuronValue += weightArray[weightIndex] * k;
                weightIndex++;
            }
            neuronArray[i + 1][j] = std::tanh(neuronValue);
        }
    }
}

void NeuralNetwork::selectFileName(std::string fileName) {
    this->fileName = fileName;
}

void NeuralNetwork::saveWeightsToFile() {
    std::ofstream file(fileName, std::ios::binary);
    file.write(reinterpret_cast<char*>(weightArray.data()), weightArray.size() * sizeof(double));
    file.close();
}

void NeuralNetwork::loadWeightsFromFile() {
    std::ifstream file(fileName, std::ios::binary);
    file.seekg(0, std::ios::end);
    auto fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char*>(weightArray.data()), fileSize);
    file.close();
}

const std::vector<float>* NeuralNetwork::getLastNeuronArray() {
    return &neuronArray[neuronArray.size() - 1];
}


void NeuralNetwork::setScore(int score) {
    this->score = score;
}

void NeuralNetwork::changeScore(int delta) {
    score += delta;
}

int NeuralNetwork::getScore() const {
    return score;
}