//Executive.h

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Player.h"
#include <string>
#include <fstream>
#include <iostream>

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
		int isWinner();

	private:
		int** playerOneGrid;
		int** playerTwoGrid;
};
#endif
