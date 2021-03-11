#include "Parent.h"
#include <iostream>







bool Parent::validatePosition(int row, int colnum, std::string direction, int shipLength)
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


int Parent::colToInt(char column){
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

void Parent::checkGrid(char letterInput, int numberInput, Parent& otherPlayer){
	//char col = shipCoords.at(0);
	//char row= shipCoords.at(1);
	int colnum = colToInt(letterInput);
	//std::cout <<"colnum: " << colnum << "\n";
	//std::cout << "numberInput: " << numberInput << "\n";	
	
		if(otherPlayer.shipGrid[numberInput-1][colnum-1]== 'S')
		{
			//print hit notif. check isDestroyed(), change values in showWaters to whatever we're using for hits
			//check isWinner? or do that in Executive
			std::cout << "Congrats you hit!\n";
			shotGrid[numberInput-1][colnum-1] = 'H';
			otherPlayer.shipGrid[numberInput-1][colnum-1] = 'H';
			for(int i = 0; i < m_ships;i++)
			{
				 //std::cout << shipArray[i].getShipPlacementArray(numberInput-1,colnum-1)<< "\n";
				 //not sure why this is here^
				 if(shipArray[i].getShipPlacementArray(numberInput-1,colnum-1) == 'S')
				 {
					shipArray[i].shipMinusHealth();
				 	if(shipArray[i].checkIfSunk())
					 {
						 numberOfShips--;
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
				otherPlayer.shipGrid[numberInput-1][colnum-1] = 'M';		
		}		
}

char Parent::getShotGrid(char letter, int input)
{
	int colnum = colToInt(letter);
	//std:: cout << shotGrid[input-1][colnum-1]<<"\n";
	return shotGrid[input-1][colnum-1];
}

void Parent::shipHit(Ship& ship)
{
	ship.shipMinusHealth();
	if(ship.getHealth() !=ship.getLength())
	{
		ship.checkIfSunk();
	}
	
}

void Parent::showFiringBoard(std::string turnPlayer)
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

void Parent::showShipPlacement(std::string turnPlayer){


	
	std::cout << "+---------------------------------------------Player "+ turnPlayer+ "'s  Board----------------------------------------------+\n";
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

bool Parent::validateCol(char column){
	return (column >='a' && column <='j') || (column >='A' && column <='J');
}

std::string Parent::intToString(int num){
	std::string temp = std::to_string(num);
	return(temp);
}

bool Parent::validateRow(int row){
	return (row >= 1 && row <= 10);
}

int Parent::shipsRemaining()
{
	return numberOfShips;
}