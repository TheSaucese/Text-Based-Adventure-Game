#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include "entity.h"
#include <windows.h>
#include "Path.h"

void Player::action(entity &enemy) {
    std::cout<< "\t\t\t\t\t\t\t\tYou are fighting against : " << enemy.getName() << std::endl << std::endl;
    do {
        Sleep(1000);
        std::cout << "\t\t\t\t\t\t\tYour Health : " << health << "\t\t\t Enemy Health : "<< enemy.getHealth() << "\n\t\t\t\t\t\t\tYour Power : " << damage << "\t\t\t\t Enemy Power : "<< enemy.getDamage() << std::endl;
        std::cout << "\t\t\t\t\t\t(a) attack \t (b) Special \t (c) Defend yourself \t (d) Open Inventory" << std::endl;
        std::cout << "\t\t\t\t\t\t\t\t";
        do {
        std::cin >> choice;
        if (choice == "a") {
            std::cout << "\t\t\t\t\t\t\t\tYou attack the " << enemy.getName() << std::endl;
            std::cout << "\t\t\t\t\t\t\t\tthe " << enemy.getName() <<" takes " << damage << " damage." << std::endl;
            enemy.update(-damage, 0);
            enemy.action(*this);
        } else if (choice == "b") {
            Path::special(enemy,*this);
        } else if (choice == "c") {
            std::cout << "\t\t\t\t\t\t\t\tYou defend yourself!" << std::endl;
            std::cout << "\t\t\t\t\t\t\t\tYou take " << enemy.getDamage()/2 << " damage." << std::endl;
            std::cout << "\t\t\t\t\t\t\t\tYou siphon " << enemy.getDamage()/2 << " damage." << std::endl;
            update(-enemy.getDamage()/2,+enemy.getDamage()/2);
        } else if (choice == "d"&&inventory.size()>0) {
            std::cout << "\t\t\t\t\t\t\t\tYou open your inventory." << std::endl;
            for(int i=0;i<inventory.size();i++) {
                std::cout << "\t\t\t\t\t\t\t\t" << i+1 << " - " << inventory[i].getName() << " Health : "<< inventory[i].getHealth() << " | Damage : " << inventory[i].getDamage() << std::endl;
            }
            std::cout << "\t\t\t\t\t\t\t\t Which item do you want to use?" << std::endl;
            std::cout << "\t\t\t\t\t\t\t\t";
            int item;
            std::cin >> item;
            if (item>inventory.size()) {
                std::cout << "\t\t\t\t\t\t\t\tYou don't have that item." << std::endl;
            } else {
                std::cout << "\t\t\t\t\t\t\t\tYou use " << inventory[item-1].getName() << std::endl;
                use(inventory[item-1]);
                inventory.erase(inventory.begin() + item);
                Sleep(1000);
                enemy.action(*this);
            }
        }
        else {
            std::cout << "\t\t\t\tInvalid input." << std::endl;
            Sleep(1000);
        }
        } while (choice != "a" && choice != "b" && choice != "c" && choice != "d");
        Sleep(1000);
        system("cls");
    } while (enemy.getHealth() > 0);
    Sleep(1000);
}

void Player::update(int h,int d) {
    health += h;
    damage += d;
    if(health<=0) {
        std::cout << "\t\t\t\tYou have died." << std::endl;
        exit(0);
    }
    if(damage<=0) {
        damage = 1;
    }
    Sleep(1000);
}

void Player::pickup(entity &item) {
    inventory.push_back(item);
}

void Player::use(entity &item) {
    Player::update(item.getHealth(), item.getDamage());
}