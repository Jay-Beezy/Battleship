//Player.cpp

#include "Player.h"
#include <iostream>

Player::Player(int ships)
{
	m_ships = ships;
	numberOfShips = m_ships;
	shipArray = new Ship[ships];
	shipGrid = new char*[10];
	for(int i = 0; i < 10; i++){
		shipGrid[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			shipGrid[j][k] = '0';
		}
	}

	
	shotGrid = new char*[10];
	for(int i = 0; i < 10; i++){
		shotGrid[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			shotGrid[j][k] = '0';
		}
	}
}

Player::~Player()
{
	for(int i = 0; i < 10; i++)
	{
		delete shipGrid[i];
		delete shotGrid[i];
	}
	delete[] shipGrid;
	delete[] shotGrid;

}

Player::Player()
{
	m_ships = 0;
	shipGrid = new char*[10];
	for(int i = 0; i < 10; i++){
		shipGrid[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			shipGrid[j][k] = '0';
		}
	}

	shotGrid = new char*[10];
	for(int i = 0; i < 10; i++){
		shotGrid[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			shotGrid[j][k] = '0';
		}
	}
}

void Player::placeShips(int length){
	char shipStarterCol;
	int shipStarterRow = 0;
	int shipLength = length;
	std::string shipLocation;
	std::string shipPlacement;

	std::cout << "\nWhat orientation would you like the ship to be placed in?\n";
	do{
		do{
			std::cout << "Vertical or Horizontal? (V / H): ";
			std::cin >> shipPlacement;
		}while(!std::cin.fail() && shipPlacement != "V" && shipPlacement != "v" && shipPlacement != "H" && shipPlacement != "h");
		std::cout << "\nWhere would you like to place the head of the ship? \n";
		do{
			std::cout << "Please input a valid column (A - J): ";
			std::cin >> shipStarterCol;
		}while(validateCol(shipStarterCol) == false);

		do{
			while(1){
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
			}
			else 
				break;
			}
			std::cout << "Please input a valid row (1 - 10): ";
			std::cin >> shipStarterRow;
		}while(validateRow(shipStarterRow) == false);
	}while(validatePosition(shipStarterRow, colToInt(shipStarterCol), shipPlacement, shipLength) == false);

	//if(validatePosition(shipStarterRow, shipStarterCol, shipPlacement, shipLength) == true){
		//shipLocation = shipStarterCol + intToString(shipStarterRow);

		Ship newShip(colToInt(shipStarterCol), shipStarterRow, shipPlacement, shipLength);
		shipArray[shipLength-1] = newShip;
	//}

	int startercolnum = colToInt(shipStarterCol);
	int arrayRow = shipStarterRow-1;
	int arrayCol = startercolnum-1;

	if(shipPlacement=="V" || shipPlacement=="v"){
		for(int i=0;i<shipLength;i++){
			shipGrid[arrayRow+i][arrayCol]='S';
		}
	}
	if(shipPlacement=="H" || shipPlacement=="h"){
		for(int i=0;i<shipLength;i++){
				shipGrid[arrayRow][arrayCol+i]='S';
				//std::cout << "shipGrid: " << arrayRow <<arrayCol+i << " = " << shipGrid[arrayRow][arrayCol+i] << "\n";
		}
	}
}