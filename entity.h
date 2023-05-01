#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>
#include <iostream>
#include <vector>

class entity {
protected:
    std::string name;
    int health;
    int damage;
public:
    static std::vector<entity> inventory;
    virtual void update(int h,int d);
    virtual void action(entity &player);
    virtual void pickup(entity &item);
    int getDamage();
    int getHealth();
    std::string getName();
    entity(std::string n,int h,int d) {
        name = n;
        health = h;
        damage = d;
    }
    virtual ~entity() {
        
    }
};

#endif

