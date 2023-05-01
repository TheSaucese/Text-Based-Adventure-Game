#include "Path.h"

bool Path::hasrepeated = false;
bool Path::levelchange = false;
int Path::level = 0;
std::string Path::reponse = "";


bool iequals(const std::string& a, const std::string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

void Path::CLS(Player &player) {
    int i,j;
    system("cls");
    std::cout << "\t\t\t\tYour Health : " << player.getHealth() << "\n\t\t\t\tYour Power : " << player.getDamage() << std::endl;
}

void Path::SwitchLevel(Player &player) {
    switch (level)
        {
        case 0:
            reponse == "a"?left(player):right(player);
            break;
		case 1:
			reponse == "a"?mountain(player):right(player);
		case 2:
			reponse == "a"?left(player):right(player);
        
        default:
            break;
        }
}

void Path::choice(Player &player) {
    do
    {
     std::cout << "\t\t\t\t";
     std::cin >> reponse;
    } 
    while (reponse != "a" && reponse != "b" );
    SwitchLevel(player);       
}

void Path::start() {
    std::cout << "\t\t\t\t???? : Hello there, you're finally awake, be not afraid child" << std::endl;
    Sleep(1000);
	std::cout << "\t\t\t\tSay child, what did GOD name you" << std::endl;
    std::cout << "\t\t\t\t";
	std::cin >> reponse;
    Sleep(1000);
    Player player(reponse,10,10);
	std::cout << "\t\t\t\tGuardian Angel : Hello " << player.getName() << " I am your guardian angel, I was sent here to guide you through this journey" << std::endl;
    Sleep(1000);
	CLS(player);
	std::cout << "\t\t\t\tIt seems that your ship has been flooded, you must find a way to get back to your home" << std::endl;
    Sleep(1000);
	std::cout << "\t\t\t\tYou're lucky that you are alive and well, however I can sense a hurricane coming, we must escape the island before it's too late" << std::endl;
    Sleep(1000);
	std::cout << "\t\t\t\tYou have to find the right combination of items to get back to your home, but you must be careful,as there are many obstacles in your way" << std::endl;
    Sleep(1000);
	CLS(player);
	std::cout << "\t\t\t\tGuardian Angel : Wait, before you enter the woods, take this healing potion, You'll need to past those two mushroom minions first" << std::endl;
    Sleep(1000);
	Item rune = Item("A rune of faith, it will help you to find the right combination of items",90,0);
    rune.action(player);
	Sleep(1000);
    Enemy m1("minion",10,10,{Item("Apples",10,10)});
    player.action(m1);
    Enemy m2("minion's little brother",20,10,{Item("Coconuts",20,30)});
    player.action(m2);
    Sleep(1000);
	std::cout << "\t\t\t\t*You enter the woods, you see a bonfire on your left*" << std::endl;
    Sleep(1000);
	std::cout <<"\t\t\t\tGuardian Angel : It seems that this island might be inhabited, Choose your way " << player.getName() <<"." << std::endl;
    Sleep(1000);
	std::cout << "\t\t\t\t*Do you choose to go left (a) or right (b) ?*" << std::endl;
    choice(player);
	
}

void Path::right(Player &player) {
	CLS(player);
    level=2;
    std::cout << "\t\t\t\tGuardian Angel : You chose the right way, you must find the right combination of items to get back to your home" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t*You found a body of dead corpses,one has its chest pierced with a spear*" << std::endl;
	Sleep(1000);
	Item spear = Item("A bloody rusty flint spear",0,90);
	std::cout << "\t\t\t\t*A corpse is still breathing*" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tGuardian Angel : it'd be better if we just leave him be" << std::endl;
	Sleep(1000);
	Enemy dyingman = Enemy("Dying man",100,0,{Item("Apples",10,20)});
	player.action(dyingman);
	rightend(player);
}

void Path::rightend(Player &player) {
	std::cout << "\t\t\t\tGuardian Angel : Watchout ! A goblin is emerging from the ground !" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tGoblin : You better back off, these corpses are mine to eat !" << std::endl;
	Sleep(1000);
	Enemy Goblin = Enemy("Green Goblin",100,40,{Item("tasty mud",20,0)});
	player.action(Goblin);
	std::cout << "\t\t\t\tGuardian Angel : Hey look, his house is full of wood logs ! If we find something to bind these toghether we can build ourselves a brand new ship !" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tHobGoblin : You killed my son, you shall die !" << std::endl;
	Sleep(1000);
	Enemy HobGoblin = Enemy("Yellow Goblin",180,100,{Item("Green Sticky Substance",0,10)});
	std::cout << "\t\t\t\tGuardian Angel : This one is tough, I will overheal you but I doubt we'll make it out alive !" << std::endl; 
	Sleep(1000);
    player.update(100,40);
	player.action(HobGoblin);
	std::cout << "\t\t\t\tGuardian Angel : you've done it ! we can finally escape !" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t*Ending 1 : Despite your victory, The hurricane destroys your new ship, you end up on the island again, and you do not remember anything, perhaps you shouldn't have been this brutal" << std::endl;
	Sleep(1000);
	exit(0);
}
void Path::left(Player &player) {
    level=1;
	CLS(player);
	std::cout << "\t\t\t\t*You chose left...*" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t*You finally get near the bonfire, you find a used sword made of bone*" << std::endl;
	Sleep(1000);
	Item sword = Item("Bone Sword", 0, 40);
	sword.action(player);
	std::cout << "\t\t\t\tGuardian Angel : Watch out, someone is coming" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t*A monster appears, he realizes that you stole his sword from him, he rushes towards you*" << std::endl;
	Sleep(1000);
	Enemy monster = Enemy("Monster",100,100);
	player.action(monster);
	std::cout << "\t\t\t\tGuardian Angel : Look, the fog is gone !, and there's a mountain in the distance ! if we manage to reach we could be able to fly out of this island !" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t*(a) Go to the mountain ? \t (b) Go back ?*"<< std::endl;
	Sleep(1000);
	choice(player);
}
void Path::mountain(Player &player) {
    level++;
	CLS(player);
	std::cout << "\t\t\t\t*You chose the mountain*" << std::endl;
	Sleep(1000);
    std::cout << "\t\t\t\tGuardian Angel : I can see at least 5 minions in the distance, this one's gonna be tough !" << std::endl;
	Sleep(1000);
    Enemy m3("minion",50,20,{Item("Apples",10,10),Item("Coconuts",20,30)});
    player.action(m3);
    Enemy m4("minion's little brother",60,20,{Item("Apples",10,10),Item("Coconuts",20,30)});
    player.action(m4);
    Enemy m5("minion",70,20,{Item("Apples",10,10),Item("Coconuts",20,30)});
    player.action(m5);
    Enemy m6("minion's little brother",80,20,{Item("Apples",10,10),Item("Coconuts",20,30)});
    player.action(m6);
    Enemy m7("minion's little brother",90,20,{Item("Apples",10,10),Item("Coconuts",20,30)});
    player.action(m7);
	std::cout << "\t\t\t\t*Moments have passed, and you're very tired*" << std::endl;
	Sleep(1000);
	player.update(0,player.getHealth()-50);
	std::cout << "\t\t\t\tGuardian Angel : I sense that you're tired, we'll have to be careful, monsters here can sense that too, good thing we're at the bridge" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tTroll : Indeed you are at the bridge !,but can you get through it ?" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tTroll : riddle me this, and i'll let you pass, ignore me, and you'll die !" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tTroll : If you say something true, I will let you go!" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t*The troll grabs your guardian angel*" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tTroll : Say something false and i'll release your little angel" << std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tTroll : Time to choose ! oh and to make it harder, say something paradoxial, and you'll lose !" << std::endl;
	Sleep(1000);
	Enemy troll = Enemy("Giant troll",200,40);
	std::cout << "\t\t\t\t*The Troll accidently drops an energy potion, you pick it up*" << std::endl;
	Sleep(1000);
	Item energypotion = Item("Energy potion, can cure headaches",0,60);
    energypotion.action(player);
	player.action(troll);
	std::cout << "\t\t\t\tEnding 7 : You have slain the troll, apparently that didn't help you, you end up stuck in this island and the hurricane wipes you out" << std::endl;
	exit(0);
}
void Path::backtomountain(Player &player) {
	std::cout << "\t\t\t\tyou decide to go back"<< std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tTroll : I TOLD YOU TO GO AWAY!" << std::endl;
	Sleep(1000);
	Enemy tiredtroll = Enemy("Tired Troll",70,40);
	player.action(tiredtroll);
	std::cout << "\t\t\t\tEnding 5 : You slain the troll, nothing happened, you're now hopeless..." << std::endl;
}

void Path::endgame(Player &player) {
	std::cout << "\t\t\t\tYou decide to sit down, watching the hurricane getting closer and closer..." <<std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\tGuardian Angel : so that's what you're gonna do, all this adventure, all for nothing..." <<std::endl;
	Sleep(1000);
	std::cout << "\t\t\t\t*Ending 2 : You gave up, letting everyone down, the hurricane wipes you out. Moments later you wake up at the island, forgetting what happened..." << std::endl;
	Sleep(1000);
	exit(0);
}

void Path::special(entity &enemy, Player &player) {
	if (enemy.getName() == "Tired Troll") {
		std::string r;
		std::cout << "\t\t\t\tGive the troll the potion ? (y/n)" << std::endl;
		Sleep(1000);
		do
		{
			std::cout << "\t\t\t\t";
			std::cin >> r;
		} while (r != "y" && r != "n");
		if (r=="y"){
		std::cout << "\t\t\t\t*You hand the troll the potion, the troll is very happy*" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\t*You have cured me ! I am sorry for screaming at you...I see you're missing a wing, here, I have a spare one." << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\t*Ending 3 : You take the wing, now you are able to fly away, the cycle is finally over." << std::endl;
		}
		else {
		std::cout << "\t\t\t\t*Ending 4 : You don't give the troll the potion, the troll grabs you and slams you against the ground, You die.*" << std::endl;
		Sleep(1000);
		}
		exit(0);
		
	}
	else if (enemy.getName() == "Giant troll") {
		std::string r;
		std::cout << "\t\t\t\t*You say : (a) You will free my guardian angel \t (b) Free my guardian angel \t (c) You will let me in \t (d) You smell awful*" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\t";
		std::cin >> r;
		if(r=="a")
		{
			std::cout << "\t\t\t\t*The troll, clueless, scratching his head*" << std::endl;
			Sleep(1000);
			std::cout << "\t\t\t\tTroll : That cannot be false, but what you said depends on what I will do, UGH PARADOXES GIVE TROLL HEADACHE, JUST GO AND LEAVE ME ALONE" << std::endl;
			Sleep(1000);
			std::cout << "\t\t\t\tGuardian Angel : Thank God we're still alive, let's not waste any time now, the hurricane is getting closer" << std::endl;
			Sleep(1000);
			std::cout << "\t\t\t\tGuardian Angel : We're at the mountain, although you don't have a second wing so we're stuck at the moment..." << std::endl;
			Sleep(1000);
			std::cout << "\t\t\t\t(a) Go back ? (b) Sit down ?" << std::endl;
			Sleep(1000);
			do {
				std::cout << "\t\t\t\t";
				std::cin >> reponse;
				CLS(player);
				reponse=="a"?backtomountain(player):endgame(player);
			}
			while (reponse != "a" && reponse != "b");
		}
		else {
			std::cout << "\t\t\t\thahaha, you're a fool, you're dead" << std::endl;
			Sleep(1000);
			std::cout << "\t\t\t\tGuardian Angel : That's unfair !" << std::endl;
			Sleep(1000);
			std::cout << "\t\t\t\tYou have died" << std::endl;
			exit(0);
		}

	}
	else if (enemy.getName() == "Monster") {
		CLS(player);
		std::cout << "\t\t\t\t*You drop the sword, the Monster suddenly stops*" << std::endl;
		Sleep(1000);
		entity::inventory.pop_back();
		Sleep(1000);
		std::cout << "\t\t\t\tMonster : *speaks gibberish*" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\tGuardian Angel : He's saying he's sorry for scaring you, It seems this was an act of self-defense" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\t*the Monster gives you an angel's wing*" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\tGuardian Angel : You made the right choice, we just need to find the other pair" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\tGuardian Angel : Look, the fog is gone !, and there's a mountain in the distance ! if we manage to reach we could be able to fly out of this island !" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\t*(a) Go to the mountain ? \t (b) Go back and go to the right ?"<< std::endl;
		choice(player);
	}
	else if (enemy.getName() == "Dying man") {
		std::cout << "\t\t\t\t*You spare the dying man" << std::endl;
		Sleep(1000);
		std::cout << "\t\t\t\tDying man : thank you for sparing me, I advice you not to follow this path, there's nothing but chaos !" << std::endl;
		Sleep(1000);
		rightend(player);
	}
	else {
		std::cout << "\t\t\t\tthis "<< enemy.getName() <<" cannot be affected by your special powers, you'll have to slay them" << std::endl;
		Sleep(1000);
	}
	
}