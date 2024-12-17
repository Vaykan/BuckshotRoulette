#include "shotgun.h"

#include "random.h"

void Shotgun::pumping() {
    delete magazine[0];
    magazine[0] = nullptr;
    for(int i = 0; i < magazineSize - 1; i++){
        if(magazine[i+1]){
            magazine[i] = magazine[i+1];
            magazine[i+1] = nullptr;
        }
    }
}

void Shotgun::loading() {
    int shellRange = rGetNum(2, 8);
    int liveLeft = shellRange / 2;
    int blankLeft = liveLeft;
    if(shellRange % 2 != 0)
        blankLeft += 1;
    for (int i = 0; i < shellRange; i++) {
        if(liveLeft && blankLeft) {
            ShellType shellType = rGetRandShellType();
            magazine[i] = new Shell(shellType);
            if(shellType == LIVE)
                liveLeft--;
            if(shellType == BLANK)
                blankLeft--;
        }
        else if(!liveLeft) {
            magazine[i] = new Shell(BLANK);
            blankLeft -= 1;
        }
        else {
            magazine[i] = new Shell(LIVE);
            liveLeft -= 1;
        }
    }
}

bool Shotgun::isEmpty() {
    return false;
}
