#ifndef TEAM_H
#define TEAMA_H
#include <player.h>
#include <string>
#include <vector>
#define TEAM_SIZE 48
class team
{

public:
    /* thinking
     * player 0 - 9 = linemen Offense
     * player 10 - 19 = hitters
     * player 20 - 29 = runners
     * player 30 - 40 = defenseiv line
     * player 40 - 47 = pitchers*/
    std::vector<player> playerPosition;
    std::string name;
    std::string pathToImage;

    team()
    {
        int iterI = 0;
        while (iterI < TEAMSIZE)
        {
            player aPlayer();
            playerPosition.push_back(aPlayer());
        }
    };



}

#endif
