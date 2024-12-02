#include <iostream>
#include <vector>

#include "items/item.h"
#include "items/pill.h"
#include "shell.h"
#include "shotgun.h"

int main() {
    std::vector<Item> vector;
    vector.resize(8);
    Item i;
    Pill p;
    vector[0] = Pill();
    Item iii;
    Pill ppp;
    iii = ppp;

    return 0;
}
