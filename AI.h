#ifndef AI_H
#define AI_H

#include <iostream>
#include <cstdlib>
#include<ctime>
#include<string>

class AI
{
    public:
        AI(int difficulty);
        ~AI();
        void takeShot(char** oppGrid);
        void placeShips(int length);

    private:
        bool validatePosition(int row, int col, std::string direction, int shipLength);
        int m_difficulty;
        char** shipGrid;
        char** shotGrid;
};
#endif