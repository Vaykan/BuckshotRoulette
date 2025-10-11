#ifndef NEURAL_NETWORK_NEURAL_NETWORK_H
#define NEURAL_NETWORK_NEURAL_NETWORK_H

#include <vector>
#include <string>


class NeuralNetwork {
private:
    int score;
    std::string fileName;
    std::vector<double> weightArray;
public:
    std::vector<std::vector<double>> neuronArray;

    void createNeuronArray(std::vector<int> neuroneCount);
    void createWeightArray();
    void changeWeights(double (* randomFunction)());
    void calculateNeuronValue();
    void selectFileName(std::string fileName);
    void saveWeightsToFile();
    void loadWeightsFromFile();

    const std::vector<double>* getLastNeuronArray();

    void setScore(int score);
    void changeScore(int delta);
    int getScore() const;

};

#endif