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
        void takeShot(Parent* opp);

        /**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post The ships are anchored to the player's grid
		* @param int length, how long that ships is
		* @return void
		**/
        void placeShips(int length);
		const int shipsRemaining();

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
		bool validatePosition(int row, int colnum, std::string direction, int shipLength);

		/**
		* @pre the player has inputted coordinates to fire upon, we need to process them
		* @post checks if the ship has been hit, if not does so
		* @param colnum xCoordinate
		* @param numberInput yCoordinate
		* @param otherPlayer opponent
		* @return none
		**/
		bool checkGrid(int numberInput, int colnum, Parent* otherPlayer);
        int m_difficulty;
		int m_numberOfShips;
};
#endif