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
		* @param int length, length of ship, string shipStart, coordinates for head of ship, string shipOrientation, direction ship does on board
		* @return N/A
		**/
		Ship(int shipHead_XCoordinate, int shipHead_YCoordinate, std::string shipOrientation, int length);

		/**
		* @pre need to know if a ship is destroyed
		* @post outputs bool if ship is destroyed
		* @param none
		* @return returns true if shipIntegrity is zero
		**/
		//bool isDestroyed();

		/**
		* @pre we need to know if the space was a ship
		* @post space is checked and bool is returned
		* @param int row - row of space to be checked, char col - column index of space to be checked
		* @return returns true if the space contains a ship
		**/
		//bool isHit(int row, char col);

		/**
		* @pre we just want to know the ship's information, test function
		* @post tells us information about the ship
		* @param none
		* @return N/A
		**/
		//void shipDocks();

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
		* @pre we need to access the private array in another class
		* @post we've made it so we can access the array from another class
		* @param none
		* @return returns a pointer to the array of coordinates
		**/
		//std::string* getArray();

		char capitalize(char col);

		int getShipPlacementArray(int i, int j);

		void shipMinusHealth();

		int getHealth();

		int getLength();

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
