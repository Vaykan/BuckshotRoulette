#ifndef NEURAL_NETWORK_NEURAL_NETWORK_H
#define NEURAL_NETWORK_NEURAL_NETWORK_H

#include <vector>
#include <string>


class NeuralNetwork {
private:
    int score = 0;
    std::string fileName;
    std::vector<float> weightArray;
public:
    std::vector<std::vector<float>> neuronArray;

    void createNeuronArray(std::vector<int> neuroneCount);
    void createWeightArray();
    void changeWeights(double (* randomFunction)());
    void calculateNeuronValue();
    void selectFileName(std::string fileName);
    void saveWeightsToFile();
    void loadWeightsFromFile();

    const std::vector<float>* getLastNeuronArray();

    void setScore(int score);
    void changeScore(int delta);
    int getScore() const;

};

#endif