#ifndef AI_H
#define AI_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Ship.h"
#include "Parent.h"

class AI: public Parent
{
    public:
        AI(int difficulty, int ships);
        ~AI();
        void takeShot(char** oppGrid);

        /**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post The ships are anchored to the player's grid
		* @param int length, how long that ships is
		* @return void
		**/
        void placeShips(int length);

    private:
        /**
		* @pre a ship has been created, and it is not known if it's position is valid
		* @post returns rue if the position is valid
		* @param int row, the row the 'head' of the ship is located on
		* @param char col, the column the 'head' of the ship is located on
		* @param std::string direction, the direction the ship is heading, H or V
		* @param int size, the length of the ship
		* @return bool, is the position is valid
		**/
        int m_difficulty;
};
#endif