//Player.cpp

#include "Player.h"
#include <iostream>

Player::Player(int ships, std::string id)
{
	m_id = id;
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
	std::string colInput;
	int shipStarterRow = 0;
	int shipLength = length;
	std::string shipLocation;
	std::string shipPlacement;

	system("clear");
	std::cout << "\nPlayer "<< m_id<< " is placing their ships!\n\n";
	showShipPlacement(m_id);
	
	do{
		if(shipLength != 1){
			do{
				std::cout << "\nWhat orientation would you like the size " << shipLength << " ship to be placed in?\n";
				std::cout << "Vertical or Horizontal? (V / H): ";
				std::cin >> shipPlacement;
			}while(!std::cin.fail() && shipPlacement != "V" && shipPlacement != "v" && shipPlacement != "H" && shipPlacement != "h");
		} else {
			shipPlacement = "V";
		}
		std::cout << "\nWhere would you like to place the head of the size " << shipLength << " ship? \n";
		do{
			std::cout << "Please input a valid column (A - J): ";
			std::cin >> colInput;
			shipStarterCol = colInput.at(0);
		}while(colInput.length() > 1 || !(shipStarterCol >= 'a' || shipStarterCol <= 'j' || shipStarterCol >= 'A' || shipStarterCol <= 'J'));

		do{
			while(1){
			if (std::cin.fail())
			{
				std::cin.clear(); // clear the error flags
    			std::cin.ignore(INT8_MAX, '\n'); // discard the row
			}
			else 
				break;
			}
			std::cout << "Please input a valid row (1 - 10): ";
			std::cin >> shipStarterRow;
		}while(shipStarterRow < 1 || shipStarterRow > 10);
		
	}while(validatePosition(shipStarterRow, colToInt(shipStarterCol), shipPlacement, shipLength) == false);


	//if(validatePosition(shipStarterRow, shipStarterCol, shipPlacement, shipLength) == true){
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

void Player::showFiringBoard(std::string turnPlayer)
{
	std::cout << "+------------------------------------------Player " + turnPlayer + "'s Board-------------------------------------------+\n";
	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << shotGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << shotGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << shotGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

void Player::showShipPlacement(std::string turnPlayer){
	std::cout << "+------------------------------------------Player "+ turnPlayer+ "'s  Board------------------------------------------+\n";
	std::cout << "|\t\t\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\t|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << shipGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << shipGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << shipGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

bool Player::validatePosition(int row, int colnum, std::string direction, int shipLength)
{
	bool isValid = false;
	//int temporaryRow = row;
	if(direction=="H" || direction == "h")
	{
		for(int i=0;i<shipLength;i++)
		{
			if((colnum)<=10 && shipGrid[row-1][colnum-1]=='0'){
				isValid = true;
			}
			else if(shipGrid[row-1][colnum-1]=='S')
			{
					std::cout <<"Ships overlapping horizontally, please try again\n";
					return(false);
					//isValid = false;
					//return(isValid);
			}
			else
			{
				isValid = false;
				std::cout << "\n\nInvalid Coordinates, try again.\n\n";
			}
			colnum++;
		}
	}

	//changed int i, to int j, cuz bug fixing. - andrews
	if(direction=="V" || direction == "v"){
		for(int j=0;j<shipLength;j++){
			if(row <= 10 && shipGrid[row-1][colnum-1]=='0' ){
				isValid = true;
			}
			else if(row>10)
			{
				std::cout << "\n\nInvalid Coordinates, try again.\n\n";
				return(false);
			}
			else if(shipGrid[row-1][colnum-1]=='S')
	 		{
	 				std::cout <<"Ships overlapping Vertically, please try again\n";
					 return(false);
	 				//isValid = false;
	 		}
			else
			{
				isValid = false;
			}
			row++;
		}
	}
	return(isValid);
}

int Player::colToInt(char column){
	if(column == 'A' || column == 'a'){
		return(1);
	}
	else if(column == 'B' || column == 'b'){
		return(2);
	}
	else if(column == 'C' || column == 'c'){
		return(3);
	}
	else if(column == 'D' || column == 'd'){
		return(4);
	}
	else if(column == 'E' || column == 'e'){
		return(5);
	}
	else if(column == 'F' || column == 'f'){
		return(6);
	}
	else if(column == 'G' || column == 'g'){
		return(7);
	}
	else if(column == 'H' || column == 'h'){
		return(8);
	}
	else if(column == 'I' || column == 'i'){
		return(9);
	}
	else if(column == 'J' || column == 'j'){
		return(10);
	}
	return(0);
}

const int Player::shipsRemaining()
{
	int retShipCount = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(shipGrid[i][j] == 'S'){
				retShipCount++;
			}
		}
	}
	return(retShipCount);
}

void Player::takeShot(Parent* opp){
	int yCoord = 0;
	char xCoord = '\0';
	char powerShotChoice = '\0';
	int shotType = 0;
	bool repeat = false;
	if(charge == 1){
		do{
			std::cout<<"You have a Power Shot! Would you like to use it?(Y/N): ";
			std::cin >> powerShotChoice;
		}while(!(powerShotChoice == 'Y' || powerShotChoice == 'y' || powerShotChoice == 'N' || powerShotChoice == 'n'));
		if(powerShotChoice == 'Y' || powerShotChoice == 'y')
		{
			shotType = 1;
		}
		else
		{
			shotType = 0;
		}
	}
	do{
		repeat = false;
		std::cout<<"Player "<< m_id << ", enter coordinates of the space you'd like to fire on.\n";
		do
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout<<"Player "<< m_id << ", enter letter of the space you'd like to fire on: ";
			std::cin>> xCoord;
			if(!((xCoord >= 'a' && xCoord <= 'j') || (xCoord >= 'A' && xCoord <= 'J')))
			{
				std::cout << "ERROR: Please enter an character within the bounds [A, J].\n";
			}
		}while(std::cin.fail() || !((xCoord >= 'a' && xCoord <= 'j') || (xCoord >= 'A' && xCoord <= 'J')));
		do
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout<<"Player "<< m_id << ", enter number of the space you'd like to fire on: ";
			std::cin>>yCoord;
			if(std::cin.fail())
			{
				std::cout << "ERROR: Please enter an integer.\n";
			}
			else if(yCoord < 1 || yCoord > 10)
			{
				std::cout << "ERROR: Please enter an integer within the bounds [1, 10].\n";
			}
		}while(std::cin.fail() || yCoord < 1 || yCoord > 10);
		std::cout << "\n";
		if(shotGrid[yCoord-1][colToInt(xCoord)-1] =='0'){
			if(shotType == 1){
				checkPower(xCoord, yCoord, opp);
			}	
			else{
				checkGrid(xCoord, yCoord, opp);
			}
			std::cout << "\n";
		}					
		else if (shotGrid[yCoord-1][colToInt(xCoord)-1] == 'H' || shotGrid[yCoord-1][colToInt(xCoord)-1] == 'M')
		{
			std::cout <<"Shot already hit, please try again\n\n";
			repeat = true;
		}
	}while(repeat == true);
}

void Player::checkGrid(char letterInput, int numberInput, Parent* otherPlayer){
	int colnum = colToInt(letterInput);	
	
		if(otherPlayer->getShipGrid(numberInput-1, colnum-1) == 'S')
		{
			//print hit notif. check isDestroyed(), change values in showWaters to whatever we're using for hits
			//check isWinner? or do that in Executive
			std::cout << "Congrats you hit!\n";
			shotGrid[numberInput-1][colnum-1] = 'H';
			otherPlayer->setShipGrid(numberInput-1, colnum-1, 'H');
			for(int i = 0; i < m_ships;i++)
			{
				if(otherPlayer->shipArray[i]->getShipPlacementArray(numberInput-1,colnum-1) == 'S')
				 {
					otherPlayer->shipArray[i]->shipMinusHealth();
				 	if(otherPlayer->shipArray[i]->checkIfSunk())
					{
						m_numberOfShips--;
						otherPlayer->setCharge();
					}
				 }
			}
		}
		else if(shotGrid[numberInput-1][colnum-1]=='H')
		{
			std::cout << "Already hit\n";
		}
		else 
		{
			std::cout << "Sorry you missed.\n";
			shotGrid[numberInput-1][colnum-1] = 'M';
			otherPlayer->setShipGrid(numberInput-1, colnum-1, 'M');	
		}		
}

void Player::setCharge(){
	charge = 1;
}

void Player::checkPower(char letterInput, int numberInput, Parent* otherPlayer){
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
				if(otherPlayer->getShipGrid(numberInput-2+k, colnum-2+j) == 'S')
				{	
					fire = 1;
					//print hit notif. check isDestroyed(), change values in showWaters to whatever we're using for hits
					//check isWinner? or do that in Executive
					shotGrid[numberInput-2+k][colnum-2+j] = 'H';
					otherPlayer->setShipGrid(numberInput-2+k, colnum-2+j, 'H');
					for(int i = 0; i < m_ships;i++)
					{
						if(otherPlayer->shipArray[i]->getShipPlacementArray(numberInput-2+k,colnum-2+j) == 'S')
						{
							otherPlayer->shipArray[i]->shipMinusHealth();
							if(otherPlayer->shipArray[i]->checkIfSunk())
							{
								m_numberOfShips--;
								otherPlayer->setCharge();
							}
						}
					}
				}
				else if(shotGrid[numberInput-2+k][colnum-2+j]=='H')
				{}
				else 
				{
					shotGrid[numberInput-2+k][colnum-2+j] = 'M';
					otherPlayer->setShipGrid(numberInput-2+k, colnum-2+j, 'M');		
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

void Player::setShipGrid(int x, int y, char set){
	shipGrid[x][y] = set;
}

char Player::getShipGrid(int x, int y){
	return(shipGrid[x][y]);
}

std::string Player::returnID(){
	return("Player "+ m_id);
}