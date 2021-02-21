//Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include <string>
#include <fstream>
#include <iostream>

class Player
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
		int colToInt(char column);

		/**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post The ships are anchored to the player's grid
		* @param int length, how long that ships is
		* @return void
		**/
		void anchorShips(int length);

		/**
		* @pre The function is called
		* @post The player grid is shown
		* @return void
		**/
		void showWaters();

		/**
		* @pre A column value must be checked to see if it is valid
		* @post returns true if the column is a valid proposal
		* @param char column, the column value to check
		* @return bool, is the column valid
		**/
		bool validateCol(char column);

		/**
		* @pre A row value must be checked to see if it is valid
		* @post returns true if the row is a valid proposal
		* @param int row, the row value to check
		* @return bool, is the row valid
		**/
		bool validateRow(int row);

		/**
		* @pre a ship has been created, and it is not known if it's position is valid
		* @post returns rue if the position is valid
		* @param int row, the row the 'head' of the ship is located on
		* @param char col, the column the 'head' of the ship is located on
		* @param std::string direction, the direction the ship is heading, H or V
		* @param int size, the length of the ship
		* @return bool, is the position is valid
		**/
		bool validatePosition(int row, char col, std::string direction, int size);

		/**
		* @pre we need to turn an int to a string
		* @post we turned an int into a string
		* @param int num, number we're turning into a string
		* @return std::string, the string
		**/
		std::string intToString(int num);

		/**
		* @pre the player has inputted coordinates to fire upon, we need to check them
		* @post checks if the ship has been hit, informs player
		* @param std::string shipCoords, the location of the ship
		* @return true if hit lands, false if miss
		**/
		bool checkGrid(std::string shipCoords);
		
		/**
		* @pre all ships have been constructed
		* @post checks how many ships have not been destroed
		* @return number of ships not destroyed
		**/
		int shipsRemaining();

	private:
		int m_ships;
		char** playerGrid;
		Ship shipArray[5];//max number of ships, allows us to have a location for each ship in memory

};
#endif
