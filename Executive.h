//Executive.h

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Player.h"
#include "AI.h"
#include "Parent.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

class Executive
{

	public:
		/**
		* @pre Executive class is created
		* @post class is created, grids are created
		* @param none
		* @return N/A
		**/
		Executive();
		/**
		* @pre game finishes, need to delete all arrays
		* @post all arrays are deleted, no memory lost
		* @param none
		* @return N/A
		**/
		~Executive();

		/**
		* @pre we need the game to run
	  * @post game is run, communicates with all other classes
		* @param none
		* @return N/A
		**/
		void run();

	private:

		/**
		* @pre shot board needs to be printed
		* @param player which player is taking their turn
		* @param id which player is taking their turn
		* @post print shot board
		**/
		void printShots(Player& player, std::string id);

		/**
		* @pre ship board needs to be printed
		* @param player which player is taking their turn
		* @param id which player is taking their turn
		* @post print ship board
		**/
		void printShips(Player& player, std::string id);

		/**
		* @pre player needs to take their turn
		* @param player which player is taking their turn
		* @post player's current ship map will display and they will select shot location
		**/
		void takeTurn(Player& player, std::string id);

		/**
		* @pre need players to change turns
		* @post screen will clear, followed by a timer for players to switch control of the game
		**/
		void changeTurns();

		/**
		* @pre need to display the playing grid of P1
		* @post playing grid is displayed to user, has labels for each space
		* @param none
		* @return N/A
		**/
		void printPlayerOneGrid();

		/**
		* @pre need to display the playing grid of P2
		* @post playing grid is displayed to user, has labels for each space
		* @param none
		* @return N/A
		**/
		void printPlayerTwoGrid();

		/**
		* @pre need to fill the 2d arrays for players one and two with zeros
		* @post arrays are filled with 0s simultaneously
		* @param none
		* @return N/A
		**/
		void fillGrids();

		/**
		* @pre need to know if there is a winner
		* @post we know if there is a winner now
		* @param none
		* @return returns 1 if player1 wins and 2 if player2 wins
		**/
		bool isWinner(Player playerOne,Parent playerTwo);

		/**
		* @pre need to check if char coordinate is in bounds
		* @post coords validity is returned
		* @param coord character in question
		* @return returns true if char is in bounds
		**/
		bool charIsValid(char coord);

		Parent playerOne;
		Parent playerTwo;
		//int** playerOneGrid;
		//int** playerTwoGrid;
		//Player playerOne;
		//Player playerTwo;
};
#endif
