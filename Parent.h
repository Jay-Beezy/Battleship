#ifndef PARENT_H
#define PARENT_H

#include "Ship.h"
#include <string>
#include <fstream>
#include <iostream>


class Parent
{
    public:


		/**
		* @pre Player or AI class must be initialized
		* @post shows Player or AI's firing board(grid that maps out where entity has shot at)
		* @param string turnPlayer, tells user whose board it is
		* @return void
		**/
    	virtual void showFiringBoard(std::string turnPlayer); // shows top board where you fire your shots
		
		/**
		* @pre Player or AI class must be initialized
		* @post shows Player or AI's ship board(grid that maps out where entity's ships are placed)
		* @param string turnPlayer, tells user whose board it is
		* @return void
		**/
		virtual void showShipPlacement(std::string turnPlayer); // shows bottom board where youre ships are placed

		/**
		* @pre The ship must be created and anchored to a spot on player grid
		* @post The ships are anchored to the player's grid
		* @param int length, how long that ships is
		* @return void
		**/
		virtual void placeShips(int length);

		/**
		* @pre the player selects coordinates to fire upon
		* @post area will be hit (or not) and opponent ship grid will be adjusted accordingly
		* @param opp the opponent to be fired upon
		**/
		virtual void takeShot(Parent* opp);

		/**
		* @pre all ships have been constructed
		* @post checks how many ships have not been destroed
		* @return number of ships not destroyed
		**/
		virtual const int shipsRemaining();

		virtual void shipHit(Ship& ship);

		virtual void setCharge();

		virtual void setShipGrid(int x, int y, char set);

		virtual char getShipGrid(int x, int y);

		virtual std::string returnID();
    //protected:
        int m_ships;
		int m_numberOfShips;
		char** shipGrid;
		char** shotGrid;
		Ship** shipArray;//max number of ships, allows us to have a location for each ship in memory
		bool charge;

};
#endif