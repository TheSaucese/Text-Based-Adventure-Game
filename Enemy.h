#ifndef ENEMY_H_
#define ENEMY_H_
#include <string>
#include <vector>
#include "entity.h"
#include "Item.h"
#include "Player.h"

class Enemy : public entity {
public:
    std::vector<entity> Loot;
    void action(entity &player);
    void update(int h,int d);
    void Dialog(std::string s);
    Enemy(std::string n,int h,int d,std::vector<entity> Loot) : entity(n,h,d) {
        this->Loot = Loot;
    };
    Enemy(std::string n,int h,int d) : entity(n,h,d) {
        
    };


};

#endif

