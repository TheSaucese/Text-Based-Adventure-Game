#include "Enemy.h"
#include <iostream>
#include "entity.h"
#include "windows.h"
#include "Player.h"

void Enemy::action(entity &player) {
    if (health > 0) {
        std::cout << "\t\t\t\t\t\t\t\tThe " << name << " attacks you!" << std::endl;
        Sleep(1000);
        std::cout << "\t\t\t\t\t\t\t\tYou take " << damage << " damage." << std::endl;
        player.update(-damage,0);
        Sleep(1000);
    }
}

void Enemy::update(int h,int d) {
    entity::update(h,d);
    if(health<=0) {
        Sleep(1000);
        std::cout << "\n\t\t\t\tThe " << name << " has dropped : \n" << std::endl;
        Sleep(1000);
        for(int i=0;i<Loot.size();i++) {
            Sleep(1000);
            std::cout << "\t\t\t\t" << Loot[i].getName() << std::endl;
            inventory.push_back(Loot[i]);
        }
        
    }
}
