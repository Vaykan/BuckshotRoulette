#include "shell.h"

Shell::Shell(ShellType newType) {
    type = newType;
}

ShellType Shell::getType() {
    return type;
}

void Shell::setType(ShellType newType) {
    type = newType;
}