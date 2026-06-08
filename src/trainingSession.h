#pragma once
#include <cstddef>

class Session;

class TrainingSession {
private:
static size_t iterationsLeft;

public:
static size_t getIterationsLeft () {return iterationsLeft;}
static void setIterationsLeft (size_t n) {iterationsLeft = n;}
static void decrementIterationsLeft () {iterationsLeft--;}

static void resetGameSession (Session& session);
};

