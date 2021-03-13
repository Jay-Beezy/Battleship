//Ship.h

#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <fstream>
#include <iostream>

class Ship
{

	public:

		/**
		* @pre Ship default constructor is called
		* @post The class is created, m_shipArray is filled with zeros
		* @return N/A
		**/
		Ship();

		/**
		* @pre need to delete a ship
		* @post deletes all arrays within the class
		* @param none
		* @return N/A
		**/
		~Ship();

		/**
		* @pre Ship constructor is called and given a coordinate to start, string orientation and length
		* @post The class is created, m_shipArray is filled with zeros
		* @param int length, length of ship
		* @param string shipStart, coordinates for head of ship
		* @param string shipStart, coordinates for head of ship 
		* @param string shipOrientation, direction ship goes on board
		* @return N/A
		**/
		Ship(int shipHead_XCoordinate, int shipHead_YCoordinate, std::string shipOrientation, int length);

		/**
		* @pre we need to store the values of the ship's coordinates in an array
		* @post an array of strings(coordinates) is made, any unfilled elements stay as zero
		* @param none
		* @return N/A
		**/
		void createArray();

		/**
		* @pre we need to turn an int to a string
		* @post we turned an int into a string
		* @param int num, number we're turning into a string
		* @return std::string, the string
		**/
		std::string numToString(int num);

		/**
		* @pre input from user is a lowercase letter
		* @post changes lowercase letter to uppercase for colToInt function
		* @param char col, the input from user on where to fire their shot(A-J)
		* @return returns user-inputted letter capitalized
		**/
		char capitalize(char col);

		/**
		* @pre ship object is intialized
		* @post char of coordinate on ship's grid is returned
		* @param int i, the x-position of the grid
		* @param int j, the y-position of the grid
		* @return returns value of array
		**/
		int getShipPlacementArray(int i, int j);

		/**
		* @pre ship object is intialized
		* @post shipHealth is decreased by 1
		* @param none
		* @return void
		**/
		void shipMinusHealth();
		/**
		* @pre ship object is intialized
		* @post shipHealth is returned
		* @param none
		* @return m_shipHealth
		**/
		int getHealth();
		/**
		* @pre ship object is intialized
		* @post tells health of ship
		* @param none
		* @return returns m_shipLength
		**/
		int getLength();
		/**
		* @pre ship object is intialized
		* @post ship is sunk or not sunk
		* @param none
		* @return true if shipHealth is 0, false if not 0
		**/
		bool checkIfSunk();

	private:
		int m_shipLength = 0;
		int m_shipHealth = 0;
		char m_shipHead_XCoordinate;
		int m_shipHead_YCoordinate;
		std::string m_shipDirection;
		char** individualShipPlacements;
		//std::string m_shipArray[5]; //Max ship length is 6

};
#endif
