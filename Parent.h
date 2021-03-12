#ifndef PARENT_H
#define PARENT_H

#include "Ship.h"
#include <string>
#include <fstream>
#include <iostream>


class Parent
{
    public:

    void showFiringBoard(std::string); // shows top board where you fire your shots
		void showShipPlacement(std::string); // shows bottom board where youre ships are placed

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
		* @param int colnum, the column the 'head' of the ship is located on
		* @param std::string direction, the direction the ship is heading, H or V
		* @param int size, the length of the ship
		* @return bool, is the position is valid
		**/
		bool validatePosition(int row, int colnum, std::string direction, int size);

		/**
		* @pre we need to turn an int to a string
		* @post we turned an int into a string
		* @param int num, number we're turning into a string
		* @return std::string, the string
		**/
		std::string intToString(int num);

		/**
		* @pre the player has inputted coordinates to fire upon, we need to process them
		* @post checks if the ship has been hit, if not does so
		* @param std::string shipCoords, the location of the ship
		* @return none
		**/
		void checkGrid(char letterInput, int numberInput,Parent& otherPlayer);

		/**
		* @pre all ships have been constructed
		* @post checks how many ships have not been destroed
		* @return number of ships not destroyed
		**/
		const int shipsRemaining();

		void shipHit(Ship& ship);
		
		char getShotGrid(char letter, int number);

        int colToInt(char column);

		/**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post The ships are anchored to the player's grid
		* @param int length, how long that ships is
		* @return void
		**/

		bool charge; //variable for if player has a power shot charge	

    //protected:
        int m_ships;
		int m_numberOfShips;
		char** shipGrid;
		char** shotGrid;
		Ship* shipArray;//max number of ships, allows us to have a location for each ship in memory

};
#endif