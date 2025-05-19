#ifndef BUCKSHOT_ROULETTE_ENUM_H
#define BUCKSHOT_ROULETTE_ENUM_H

enum ShellType {
    LIVE,
    BLANK
};

enum ItemType {
    EMPTY,
    PILL,
    CIGARETTE,
    BEER,
    ADRENALINE,
    MAGNIFIER,
    HANDCUFFS,
    INVERTER,
    SAW,
    PHONE
};

enum Action {
    NODATA,
    SHOOT_TARGET,
    SHOOT_YOURSELF,
    USE_ITEM
};

#endif