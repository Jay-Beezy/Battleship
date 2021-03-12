//Player.cpp

#include "Player.h"
#include <iostream>

Player::Player(int ships)
{
	charge = 0;
	m_ships = ships;
	m_numberOfShips = m_ships;
	shipArray = new Ship*[ships];
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
	for(int i = 0; i < m_ships; i++)
	{
		delete shipArray[i];
	}
	delete[] shipGrid;
	delete[] shotGrid;
	delete[] shipArray;

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

		shipArray[shipLength-1] = new Ship(colToInt(shipStarterCol), shipStarterRow, shipPlacement, shipLength);
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

void Player::checkPower(char letterInput, int numberInput, Parent& otherPlayer){
	//char col = shipCoords.at(0);
	//char row= shipCoords.at(1);
	int colnum = colToInt(letterInput);
	//std::cout <<"colnum: " << colnum << "\n";
	//std::cout << "numberInput: " << numberInput << "\n";	
	int fire = 0;//marker for if a hit was made
	for(int k = 0; k < 3; k++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(!(((numberInput-2+k)>9)||((numberInput-2+k)<0)||((colnum-2+j)>9)||((colnum-2+j)<0)))//make sure shot is still valid
			{	
				if(otherPlayer.shipGrid[numberInput-2+k][colnum-2+j]== 'S')
				{	
					fire = 1;
					//print hit notif. check isDestroyed(), change values in showWaters to whatever we're using for hits
					//check isWinner? or do that in Executive
					shotGrid[numberInput-2+k][colnum-2+j] = 'H';
					otherPlayer.shipGrid[numberInput-2+k][colnum-2+j] = 'H';
					for(int i = 0; i < m_ships;i++)
					{
						//std::cout << shipArray[i].getShipPlacementArray(numberInput-1,colnum-1)<< "\n";
						//not sure why this is here^
						if(shipArray[i]->getShipPlacementArray(numberInput-2+k,colnum-2+j) == 'S')
						{
							shipArray[i]->shipMinusHealth();
							if(shipArray[i]->checkIfSunk())
							{
								m_numberOfShips--;
							}
						}
					}
				}
				else if(shotGrid[numberInput-2+k][colnum-2+j]=='H')
				{}
				else 
				{
					shotGrid[numberInput-2+k][colnum-2+j] = 'M';
					otherPlayer.shipGrid[numberInput-2+k][colnum-2+j] = 'M';		
				}
			}
		}
	}
	//player feedback
	if(fire>0)
	{
		std::cout << "Congrats you hit!\n";
	}
	else
	{
		std::cout << "Sorry you missed.\n";
	}
	charge = 0;//use up the charge
}