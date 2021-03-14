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

		/**
		* @pre input on difficulty and number of ships
		* @post The class is created
		* @param int ships, the number of ships the player has
		* @param int difficulty, determines  AI level of difficulty player wants to play against
		* @return N/A
		**/
        AI(int difficulty, int ships);
		/**
		* @pre deletes AI entity
		* @post deletes all arrays within the class
		* @param none
		* @return N/A
		**/
        ~AI();

		/**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post AI fires on player's ship,results vary on difficulty, player grid will  say 'H' for hit and 'M' for miss
		* @param Parent* opp, the enemy player
		* @return void
		**/
        void takeShot(Parent* opp);
		
		/**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post Helper function for recursive method of difficulty 2
		* @param Parent* opp, the enemy player
		* @return void
		**/
		void takeShot2(Parent* opp);
		
		/**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post recursivly sniffs out ships for ai difficulty 2
		* @param Parent* opp, the enemy player
		* @return void
		**/
		bool takeShotR(Parent* opp, int direction);

        /**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post The ships are anchored to the player's grid
		* @param int length, how long that ships is
		* @return void
		**/
        void placeShips(int length);

		/**
		* @pre ships must be initialzied
		* @post  returns numberOfShips AI has left
		* @param none
		* @return int, numberOfShips AI has
		**/
		const int shipsRemaining();


		/**
		* @pre ship grid must be updated
		* @post ship grid will be updated
		* @param x y coordinate
		* @param y x coordinate
		* @param set the character to be set
		**/
		void setShipGrid(int x, int y, char set);

		/**
		* @pre ship grid cell must be obtained
		* @post ship grid cell returned
		* @param x y coordinate
		* @param y x coordinate
		* @return ship grid cell[x][y]
		**/
		char getShipGrid(int x, int y);

		/**
		* @pre player ID is required elsewhere
		* @return AI ID
		**/
		std::string returnID();

    private:
        /**
		* @pre a ship has been created, and it is not known if it's position is valid
		* @post returns true if the position is valid
		* @param int row, the row the 'head' of the ship is located on
		* @param char col, the column the 'head' of the ship is located on
		* @param std::string direction, the direction the ship is heading, H or V
		* @param int size, the length of the ship
		* @return bool, if the position is valid
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
		int m_shipHealth;
		int m_ships;
		int mX;
		int mY;
		int nX;
		int nY;
		int mode;
	};
#endif