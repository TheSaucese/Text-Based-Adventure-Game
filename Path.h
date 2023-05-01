#ifndef PATH_H_
#define PATH_H_
#include <string>
#include <iostream>
#include "Player.h"
#include "Path.h"
#include "entity.h"
#include "windows.h"

class Path {
protected:
    static std::string reponse;
    static bool hasrepeated;
public:
    static int level;
    static bool levelchange;
    static void start();
	static void left(Player &player);
	static void right(Player &player);
    static void mountain(Player &player);
	static void backtomountain(Player &player);
	static void endgame(Player &player);
    static void choice(Player &player);
    static void CLS(Player &player);
    static void SwitchLevel(Player &player);
    static void special(entity &enemy,Player &player);
    static void rightend(Player &player);
};

#endif

