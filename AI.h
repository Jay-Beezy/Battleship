#ifndef AI_H
#define AI_H

#include <iostream>
#include <cstdlib>
#include<ctime>

class AI
{
    public:
        AI(int difficulty);
        ~AI();
        void takeShot(char** oppGrid);

    private:
        const int m_difficulty;
        char** shipGrid;
        char** shotGrid;
};
#endif