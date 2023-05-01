#include "entity.h"
#include "iostream"

std::vector<entity> entity::inventory;

void entity::update(int h,int d) {
    health += h;
    damage += d;
    if(health<=0) {
        std::cout << "\t\t\t\t\t\t\t\tYou have slain the " << name << std::endl;
    }
    if (damage<=0) {
        damage = 1;
    }
}

void entity::action(entity &player) {
    std::cout << "You attack the " << name << std::endl;
    std::cout << "the " << name <<" takes " << damage << " damage." << std::endl;
    player.update(-damage, 0);
    player.action(*this);
}

void entity::pickup(entity &item) {
    inventory.push_back(item);
}

int entity::getDamage() {
    return damage; 
}

int entity::getHealth() {
    return health;
}

std::string entity::getName() {
    return name;
}