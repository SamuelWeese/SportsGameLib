#include <iostream>

#include "team.h"

using namespace std;

float diceRoll(float modifier, int maxRoll = 20)
{
    return rand() % maxRoll * modifier;
}
/*
void generateTimeToBat(player *pitcher, player *lineMan)
{

}
*/
float generateAtBat(player *batter, player *pitcher)
{
    int batterDice = 0;
    int pitcherDice = 0;
    if (batter->quirk == pitcher->quirk)
    {
        batterDice += 20;
        pitcherDice += 10;
    }
    float pitchScore = diceRoll(pitcher->pitching, pitcherDice) - diceRoll(batter->hitting, batterDice);
    return pitchScore;

}

bool playGame(team &a, team &b) // team a always goes first
{
    unsigned short team_a_score = 0;
    unsigned short team_b_score = 0;
    unsigned short innings = 1;
    while (innings < 9)
    {
        // main game loop
        unsigned short outs = 0;
        while (outs < 3)
        {
            if ()

            // calculate if pitch gets off
            // calculate if pitch is hit
            // calculate if pitch is caught
            // calculate time to grab pitch
            // calculate yardage
            // calculate touchdown
        }
    }

}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
