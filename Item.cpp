#include "Item.h"
#include "entity.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <windows.h>

void Item::action(entity &player) {
    std::cout << "\t\t\t\tYou pick up the " << name << "." << std::endl;
    Sleep(1000);
    player.pickup(*this);
    Sleep(1000);
}
