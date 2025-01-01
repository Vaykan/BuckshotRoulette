#ifndef BUCKSHOT_ROULETTE__SHELL_H
#define BUCKSHOT_ROULETTE__SHELL_H

#include "enum.h"

class Shell{
private:
    ShellType type;

public:
    explicit Shell(ShellType newType);
    ShellType getType();
    void setType(ShellType newType);
};

#endif
