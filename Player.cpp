//Player.cpp

#include "Player.h"
#include <iostream>

Player::Player(int ships)
{
	m_ships = ships;
	playerGrid = new char*[10];
	for(int i = 0; i < 10; i++){
		playerGrid[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			playerGrid[j][k] = 'O';
		}
	}
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
			playerGrid[j][k] = 'O';
		}
	}
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

bool Player::checkGrid(std::string shipCoords){
	char col = shipCoords.at(0);
	char row= shipCoords.at(1);
	int rownum = row - '0';
	int colnum = colToInt(col);
	for(int i=0;i<m_ships;i++){
		if(shipArray[i].isHit(rownum,col)==true)
		{
			//print hit notif. check isDestroyed(), change values in showWaters to whatever we're using for hits
			//check isWinner? or do that in Executive
			std::cout << "Congrats you hit!\n";
			playerGrid[rownum][colnum] = 'H';
			return true;
		}
		else{
			//print miss notif, change values in showWaters to misses
			if(playerGrid[rownum][colnum] == 'H') {
				std::cout << "You hit a spot already hit.\n";
			}else {
				std::cout << "Sorry you missed.\n";
				playerGrid[rownum][colnum] = 'M';
			}
			return false;
		}
	}

}

void Player::showWaters(){
	std::cout << "+---------------------------------------------Player Board----------------------------------------------+\n";
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
	bool isValid = false;
	do{
		if(column == 'A' || column == 'a'){
			isValid = true;
			return(true);
		}
		else if(column == 'B' || column == 'b'){
			isValid = true;
			return(true);
		}
		else if(column == 'C' || column == 'c'){
			isValid = true;
			return(true);
		}
		else if(column == 'D' || column == 'd'){
			isValid = true;
			return(true);
		}
		else if(column == 'E' || column == 'e'){
			isValid = true;
			return(true);
		}
		else if(column == 'F' || column == 'f'){
			isValid = true;
			return(true);
		}
		else if(column == 'G' || column == 'g'){
			isValid = true;
			return(true);
		}
		else if(column == 'H' || column == 'h'){
			isValid = true;
			return(true);
		}
		else if(column == 'I' || column == 'i'){
			isValid = true;
			return(true);
		}
		else if(column == 'J' || column == 'j'){
			isValid = true;
			return(true);
		}
		else{
			isValid = false;
			return(false);
		}
	}while(isValid == false);
}

std::string Player::intToString(int num){
	std::string temp = std::to_string(num);
	return(temp);
}

bool Player::validateRow(int row){
	bool isValid = false;
	do{
		if(row == 1){
			isValid = true;
			return(true);
		}
		else if(row == 2){
			isValid = true;
			return(true);
		}
		else if(row == 3){
			isValid = true;
			return(true);
		}
		else if(row == 4){
			isValid = true;
			return(true);
		}
		else if(row == 5){
			isValid = true;
			return(true);
		}
		else if(row == 6){
			isValid = true;
			return(true);
		}
		else if(row == 7){
			isValid = true;
			return(true);
		}
		else if(row == 8){
			isValid = true;
			return(true);
		}
		else if(row == 9){
			isValid = true;
			return(true);
		}
		else if(row == 10){
			isValid = true;
			return(true);
		}
		else{
			return(false);
		}
	}while(isValid == false);

}

void Player::anchorShips(int length){
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


	while(validatePosition(shipStarterRow, shipStarterCol, shipPlacement, shipLength) != true){
		std::cout << "\n\nInvalid Coordinates, try again.\n\n";
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

	if(validatePosition(shipStarterRow, shipStarterCol, shipPlacement, shipLength) == true){
		shipLocation = shipStarterCol + intToString(shipStarterRow);
		shipArray[shipLength] = Ship newShip(shipLocation, shipPlacement, shipLength);
	}

	if(shipPlacement=="V"){
		for(int i=0;i<shipLength;i++){
			playerGrid[shipStarterRow+i][shipStarterCol]='S';
		}
	}
	if(shipPlacement=="H"){
		for(int i=0;i<shipLength;i++){
				playerGrid[shipStarterRow][shipStarterCol+i]='S';
		}
	}
}

bool Player::validatePosition(int row, char col, std::string direction, int size){
	bool isValid = false;
	int colnum = colToInt(col);
	if(direction=="H"){
		for(int i=0;i<size;i++){
			if((colnum+i)<=10 && playerGrid[row][colnum+i]==0){
				isValid = true;
			}
			else{
				isValid = false;
			}
		}
	}

	//changed int i, to int j, cuz bug fixing. - andrew
	if(direction=="V"){
		for(int j=0;j<size;j++){
			if((row+j)<=10 && playerGrid[row+j][colnum]==0){
				isValid = true;
			}
			else{
				isValid = false;
			}
		}
	}
	return(isValid);
}

int Player::shipsRemaining(){
	int cnt = m_ships;
	for(int i=0;i<m_ships;i++) {
		if(shipArray[i].isDestroyed() ){
			cnt--;
		}
	}
	return(cnt);
}
