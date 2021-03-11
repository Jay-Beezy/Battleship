//Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Parent.h"
#include <string>
#include <fstream>
#include <iostream>

class Player : public Parent
{

	public:
		/**
		* @pre The class is created and a number of ships provided
		* @post The class is created
		* @param int ships, the number of ships the player has
		* @return N/A
		**/
		Player(int ships);

		/**
		* @pre need to delete a player
		* @post deletes all arrays within the class
		* @param none
		* @return N/A
		**/
		~Player();

		/**
		* @pre The class is created using a default constructor with no number of ships specified
		* @post The class is created
		* @return N/A
		**/
		Player();

		/**
		* @pre You need to turn a char column value to an int value
		* @post the char is turned into the corresponding int
		* @param char column, the column value
		* @return int, the column return value
		**/
		//int colToInt(char column);

		/**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post The ships are anchored to the player's grid
		* @param int length, how long that ships is
		* @return void
		**/
		void placeShips(int length);

		/**
		* @pre The function is called
		* @post The player grid is shown
		* @return void
		**/

};
#endif
