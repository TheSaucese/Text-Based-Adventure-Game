#include "Enemy.h"
#include "entity.h"
#include "Player.h"
#include "Item.h"
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include "Path.h"

int main() {
    /*Path path;
    std::string reponse;
    std::cout << "\t\t\t\t???? : Hello there, you're finally awake, be not afraid child" << std::endl;
    //Sleep(1000);
	std::cout << "\t\t\t\tSay child, what did GOD name you" << std::endl;
    std::cout << "\t\t\t\t";
	std::cin >> reponse;
    //Sleep(1000);
    Player player(reponse,10,10);
	std::cout << "\t\t\t\tGuardian Angel : Hello " << player.getName() << " I am your guardian angel, I was sent here to guide you through this journey" << std::endl;
    //Sleep(2000);
	path.CLS(player);
	std::cout << "\t\t\t\tIt seems that your ship has been flooded, you must find a way to get back to your home" << std::endl;
    //Sleep(1000);
	std::cout << "\t\t\t\tYou're lucky that you are alive and well, however I can sense a hurricane coming, we must escape the island before it's too late" << std::endl;
    //Sleep(1000);
	std::cout << "\t\t\t\tYou have to find the right combination of items to get back to your home, but you must be careful,as there are many obstacles in your way" << std::endl;
    //Sleep(5000);
	path.CLS(player);
	std::cout << "\t\t\t\tGuardian Angel : Wait, before you enter the woods, take this healing potion, You'll need to past those two mushroom minions first" << std::endl;
    //Sleep(1000);
	Item rune = Item("A rune of faith, it will help you to find the right combination of items",90,0);
    rune.action(player);
    Enemy m1("minion",10,10,{Item("Apples",10,10)});
    player.action(m1);
    Enemy m2("minion's little brother",20,10,{Item("Coconuts",20,30)});
    player.action(m2);
    //Sleep(1000);
	std::cout << "\t\t\t\t*You enter the woods, you see a bonfire on your left*" << std::endl;
    //Sleep(1000);
	std::cout <<"\t\t\t\tGuardian Angel : It seems that this island might be inhabited, Choose your way " << player.getName() <<"." << std::endl;
    //Sleep(1000);
    path.choice(player);*/
    Path::start();








    std::vector<entity> Loot{Item("Apples",10,10),Item("Shield",10,10),Item("Potion",10,10)};
    
    //Player p("Player",100,25);
    //Enemy e("Ene3my",50,50,Loot);
    //p.action(e);
}