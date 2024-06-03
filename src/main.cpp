#include <iostream>

#include "shell.h"
#include "shotgun.h"

int main() {
   Shotgun shotgun;

   shotgun.loading();

    for (int i = 0; i < 8; ++i) {
        shotgun.pumping();
    }

    return 0;
}
