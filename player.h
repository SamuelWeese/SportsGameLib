#ifndef PLAYER_H
#define PLAYER_H
#include <stdlib.h>
#include <string>

float generateStat(float aFloat = 1)
{
   float stat = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
   return stat * aFloat;
}

float generateStrongStat()
{
    return generateStat(static_cast <float> (rand() % 10) / 10.0f + 1.0f); // should return anywhere from stat bottom to statmax * 2;
}

float generateWeakStat()
{
    return generateStat(static_cast <float> (rand() % 10) / 10.0f); // should return anywhere from stat bottom to statmax * 1;
}

enum WildCard { None, Slider, Curveball, Fastball, Cut, Jump, Batter };

WildCard generateSpecialty()
{
    return WildCard[rand() % 7]
}
WildCard generateBatSpecialty()
{
    return WildCard[rand() % 3 + 1];
}

WildCard generateTackleSpecialty()
{
    return WildCard[rand() % 3 + 4];
}
class player
{
public:
    std::string playerName;
    float running;
    float injuryChance;
    float hitting;
    float position;
    float tackle;
    float catching;
    float pitching;
    WildCard quirk;
// Constructors
    player()
    {
         this->running = generateStat();
         this->injuryChance = generateStat();
         this->hitting = generateStat();
         this->position = generateStat();
         this->tackle = generateStat();
         this->catching = generateStat();
         this->pitching = generateStat();
         this->quirk = generateSpecialty();

    };
    player(float running,
    float injuryChance,
    float hitting,
    float position,
    float tackle,
    float catching,
    float pitching,
    BatSpecialty wildCard,
    );

    string generateName(std::string firstNamePath = "./dictionaries/firstname.dct", std::string lastNamePath = "./dictionaries/lastname.dct");
    //void generateInjury();

}
#endif
