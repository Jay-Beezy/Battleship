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
		void takeShot(Parent& opp);

		/**
		* @pre the player has inputted coordinates to fire upon, we need to process them
		* @post checks if the ship has been hit, if not hits area with power shot
		* @param std::string shipCoords, the location of the ship
		* @return none
		**/
		void checkPower(char letterInput, int numberInput,Parent& otherPlayer);

		private:
		std::string m_id;
};
#endif
