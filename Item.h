#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <vector>
#include "entity.h"
#include "Player.h"
#include "Enemy.h"

class Item : public entity {
public:
    void action(entity &player);
    Item(std::string n,int h,int d) : entity(n,h,d) {};
};

#endif
