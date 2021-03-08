//Player.cpp

#include "Player.h"
#include <iostream>

Player::Player(int ships)
{
	m_ships = ships;
	shipArray = new Ship[ships];
	playerGrid = new char*[10];
	for(int i = 0; i < 10; i++){
		playerGrid[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			playerGrid[j][k] = '0';
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
		delete playerGrid[i];
		delete shotGrid[i];
	}
	delete[] playerGrid;
	delete[] shotGrid;

}

Player::Player()
{
	m_ships = 0;
	playerGrid = new char*[10];
	for(int i = 0; i < 10; i++){
		playerGrid[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			playerGrid[j][k] = '0';
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
		std::cout << "Vertical or Horizontal? (V / H): ";
		std::cin >> shipPlacement;
	}while(!std::cin.fail() && shipPlacement != "V" && shipPlacement != "v" && shipPlacement != "H" && shipPlacement != "h");


	std::cout << "\nWhere would you like to place the head of the ship? \n";
	do{
		std::cout << "Please input a valid column (A - J): ";
		std::cin >> shipStarterCol;
	}while(validateCol(shipStarterCol) == false);

	do{
		std::cout << "Please input a valid row (1 - 10): ";
		std::cin >> shipStarterRow;
	}while(validateRow(shipStarterRow) == false);


	while(validatePosition(shipStarterRow, shipStarterCol, shipPlacement, shipLength) != true)
	{
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
			std::cout << "Please input a valid row (1 - 10): ";
			std::cin >> shipStarterRow;
		}while(validateRow(shipStarterRow) == false);
	}

	//if(validatePosition(shipStarterRow, shipStarterCol, shipPlacement, shipLength) == true){
		//shipLocation = shipStarterCol + intToString(shipStarterRow);

		Ship newShip(shipStarterCol,shipStarterRow, shipPlacement, shipLength);


		shipArray[shipLength-1] = newShip;
	//}

	int startercolnum = colToInt(shipStarterCol);
	int arrayRow = shipStarterRow-1;
	int arrayCol = startercolnum-1;

	if(shipPlacement=="V" || shipPlacement=="v"){
		for(int i=0;i<shipLength;i++){
			playerGrid[arrayRow+i][arrayCol]='S';
		}
	}
	if(shipPlacement=="H" || shipPlacement=="h"){
		for(int i=0;i<shipLength;i++){
				playerGrid[arrayRow][arrayCol+i]='S';
				//std::cout << "playerGrid: " << arrayRow <<arrayCol+i << " = " << playerGrid[arrayRow][arrayCol+i] << "\n";
		}
	}
}

bool Player::validatePosition(int row, char col, std::string direction, int shipLength)
{
	bool isValid = false;
	//int temporaryRow = row;
	int colnum = colToInt(col);
	if(direction=="H" || direction == "h")
	{
		for(int i=0;i<shipLength;i++)
		{
			if((colnum)<=10 && playerGrid[row-1][colnum-1]=='0'){
				isValid = true;
			}
			else if(playerGrid[row-1][colnum-1]=='S')
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
			if(row <= 10 && playerGrid[row-1][colnum-1]=='0' ){
				isValid = true;
			}
			else if(playerGrid[row-1][colnum-1]=='S')
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

void Player::checkGrid(char letterInput, int numberInput, Player& otherPlayer){
	//char col = shipCoords.at(0);
	//char row= shipCoords.at(1);
	int colnum = colToInt(letterInput);
	//std::cout <<"colnum: " << colnum << "\n";
	//std::cout << "numberInput: " << numberInput << "\n";	
	
		if(otherPlayer.playerGrid[numberInput-1][colnum-1]== 'S')
		{
			//print hit notif. check isDestroyed(), change values in showWaters to whatever we're using for hits
			//check isWinner? or do that in Executive
			std::cout << "Congrats you hit!\n";
			shotGrid[numberInput-1][colnum-1] = 'H';
			otherPlayer.playerGrid[numberInput-1][colnum-1] = 'H';
			for(int i = 0; i < m_ships;i++)
			{
				 //std::cout << shipArray[i].getShipPlacementArray(numberInput-1,colnum-1)<< "\n";
				 //not sure why this is here^
				 if(shipArray[i].getShipPlacementArray(numberInput-1,colnum-1) == 'S')
				 {
					shipArray[i].shipMinusHealth();
				 	shipArray[i].checkIfSunk();
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
				otherPlayer.playerGrid[numberInput-1][colnum-1] = 'M';		
		}		
}

char Player::getShotGrid(char letter, int input)
{
	int colnum = colToInt(letter);
	//std:: cout << shotGrid[input-1][colnum-1]<<"\n";
	return shotGrid[input-1][colnum-1];
}

void Player::shipHit(Ship& ship)
{
	ship.shipMinusHealth();
	if(ship.getHealth() !=ship.getLength())
	{
		ship.checkIfSunk();
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


	
	std::cout << "+---------------------------------------------Player "+ turnPlayer+ "'s  Board----------------------------------------------+\n";
	std::cout << "|\t\t\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\t|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << playerGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << playerGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

bool Player::validateCol(char column){
	return (column >='a' && column <='j') || (column >='A' && column <='J');

	// bool isValid = false;
	// do{
	// 	if(column == 'A' || column == 'a'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'B' || column == 'b'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'C' || column == 'c'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'D' || column == 'd'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'E' || column == 'e'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'F' || column == 'f'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'G' || column == 'g'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'H' || column == 'h'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'I' || column == 'i'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else if(column == 'J' || column == 'j'){
	// 		isValid = true;
	// 		return(true);
	// 	}
	// 	else{
	// 		isValid = false;
	// 		return(false);
	// 	}
	// }while(isValid == false);
}

std::string Player::intToString(int num){
	std::string temp = std::to_string(num);
	return(temp);
}

bool Player::validateRow(int row){
	//bool isValid = false;
		if(row == 1){
			//isValid = true;
			return(true);
		}
		else if(row == 2){
			//isValid = true;
			return(true);
		}
		else if(row == 3){
			//isValid = true;
			return(true);
		}
		else if(row == 4){
			//isValid = true;
			return(true);
		}
		else if(row == 5){
			//isValid = true;
			return(true);
		}
		else if(row == 6){
			//isValid = true;
			return(true);
		}
		else if(row == 7){
			//isValid = true;
			return(true);
		}
		else if(row == 8){
			//isValid = true;
			return(true);
		}
		else if(row == 9){
			//isValid = true;
			return(true);
		}
		else if(row == 10){
			//isValid = true;
			return(true);
		}
		else{
			return(false);
		}

}





//int Player::shipsRemaining(){
	//  int cnt = m_ships;
	//  for(int i=0;i<m_ships;i++) {
	//  	if(shipArray[i].isDestroyed() ){
	//  		cnt--;
	//  	}
	//  }
	//  return(cnt);
//}
