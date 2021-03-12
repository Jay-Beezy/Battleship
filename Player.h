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
		* @param id - identifies player
		* @return N/A
		**/
		Player(int ships, std::string id);

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
		* @pre a ship has been created, and it is not known if it's position is valid
		* @post returns rue if the position is valid
		* @param int row, the row the 'head' of the ship is located on
		* @param int colnum, the column the 'head' of the ship is located on
		* @param std::string direction, the direction the ship is heading, H or V
		* @param int size, the length of the ship
		* @return bool, is the position is valid
		**/
		virtual bool validatePosition(int row, int colnum, std::string direction, int size);

		/**
		* @pre player's turn begins
		* @post player's shot board will be printed
		* @param turnPlayer player id
		**/
		void showFiringBoard(std::string turnPlayer); // shows top board where you fire your shots

		/**
		* @pre player's turn begins and shot grid has been printed
		* @post player's ship board will be printed
		* @param turnPlayer player id
		**/
		void showShipPlacement(std::string turnPlayer);

		/**
		* @pre the player selects coordinates to fire upon
		* @post area will be hit (or not) and opponent ship grid will be adjusted accordingly
		* @param opp the opponent to be fired upon
		**/
		void takeShot(Parent* opp);

		/**
		* @pre all ships have been constructed
		* @post checks how many ships have not been destroed
		* @return number of ships not destroyed
		**/
		const int shipsRemaining();

		char getShotGrid(char letter, int input);

		/**
		* @pre the player has inputted coordinates to fire upon, we need to process them
		* @post checks if the ship has been hit, if not does so
		* @param std::string shipCoords, the location of the ship
		* @return none
		**/
		void checkGrid(char letterInput, int numberInput,Parent* otherPlayer);

		/**
		* @pre the player has inputted coordinates to fire upon, we need to process them
		* @post checks if the ship has been hit, if not hits area with power shot
		* @param std::string shipCoords, the location of the ship
		* @return none
		**/
		void checkPower(char letterInput, int numberInput,Parent* otherPlayer);


		/**
		* @pre char column value needs to be converted to an integer
		* @post none
		* @param column char to be converted
		* @return integer column equivalent
		**/	
		int colToInt(char column);

		private:
		bool charge; //variable for if player has a power shot charge	
		std::string m_id;
};
#endif
