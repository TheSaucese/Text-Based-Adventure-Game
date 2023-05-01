#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>
#include <vector>
#include "entity.h"
#include "Enemy.h"
#include "Item.h"

class Player : public entity {
private:
    std::string choice;
public:
    void action(entity &enemy);
    void update(int h,int d);
    void pickup(entity &item);
    void use(entity &item);
    Player(std::string n,int h,int d) : entity(n,h,d) {};
};
#endif

