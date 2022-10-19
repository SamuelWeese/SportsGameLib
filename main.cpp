#include <iostream>
#include <vector>
#include <limits>

#include "team.h"

using namespace std;

float diceRoll(float modifier, int maxRoll = 20)
{
    return rand() % maxRoll * modifier;
}

float generateTimeFromPosition(float position, int maxRoll = 20)
{
    return 20 - diceRoll(position, maxRoll);
}

bool generateBlock(player *blocker, player *tackler)
{
    if (diceRoll(blocker->tackle) > diceRoll(tackler->tackle)) return false;
    return true;
}

float generateTimeToPitch(player *pitcher, player *snapper)
{
    int diceToRoll = 20;
    float netModifier = 0;
    if (pitcher->quirk == snapper->quirk)
    {
        diceToRoll -= 10;
        netModifier += 0.5;
    }

}

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
        unsigned short downs = 0;
        unsigned short outs = 0;
        while (outs < 3 && down < 5)
        {
            vector<int> blockPosition;
            for (int iterI = 0; iterI < 7; iterI++)
            {
                if (generateBlock(a.playerPosition[iterI].tackle, generateBlock(b.playerPosition[iterI].tackle)))
                {
                    blockPosition.push_back(iterI);
                }
            }
            float minimumTime = FLT_MAX;
            for (auto blockerIter : blockPosition)
            {
                float timeToHit = generateTimeFromPosition(a.playerPosition[blockerIter].position);
                if (diceRoll(timeToHit) < minimumTime) minimumTime = timeToHit;
            }
            if (minimumTime < generateTimeToPitch(a.playerPosition[40], a.playerPosition[6]))
            {
                downs++;
            }
            for (int iterI = 8; iterI < 12; iterI++)
            {
                // generate catch here for each
                // decided target should be based upon random choice
            }
            // catch target should have generate time from position with the line backers

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
