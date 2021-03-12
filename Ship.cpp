//Ship.cpp

#include "Ship.h"
#include <iostream>


Ship::Ship(){};

Ship::Ship(int shipHead_xCoordinate, int shipHead_yCoordinate, std::string shipOrientation, int length){ //constructor
	m_shipLength = length;
	m_shipHealth = length;
	m_shipHead_XCoordinate = shipHead_xCoordinate;
	m_shipHead_YCoordinate = shipHead_yCoordinate;
	m_shipDirection = shipOrientation;

	individualShipPlacements = new char*[10];
	for(int i = 0; i < 10; i++){
		individualShipPlacements[i] = new char[10];
	}
	for(int j = 0; j < 10; j++){
		for(int k = 0; k < 10; k++){
			individualShipPlacements[j][k] = '0';
		}
	}


  createArray();
}

	Ship::~Ship(){
		//Having deletes here makes the getShipPlacementArray segfault
		/*
		for(int i = 0; i < 10; i++){
		delete[] individualShipPlacements[i];
		}
		delete[] individualShipPlacements;
		*/
	}

char Ship::capitalize(char column){
	if(column == 'A' || column == 'a'){
		return('A');
	}
	else if(column == 'B' || column == 'b'){
		return('B');
	}
	else if(column == 'C' || column == 'c'){
		return('C');
	}
	else if(column == 'D' || column == 'd'){
		return('D');
	}
	else if(column == 'E' || column == 'e'){
		return('E');
	}
	else if(column == 'F' || column == 'f'){
		return('F');
	}
	else if(column == 'G' || column == 'g'){
		return('G');
	}
	else if(column == 'H' || column == 'h'){
		return('H');
	}
	else if(column == 'I' || column == 'i'){
		return('I');
	}
	else if(column == 'J' || column == 'j'){
		return('J');
	}
	return('0');
}

std::string Ship::numToString(int num){
	std::string temp = std::to_string(num);
	return(temp);
}

void Ship::createArray()
{
	 int head_XCoordinate = m_shipHead_XCoordinate;
	 int head_YCoordinate= m_shipHead_YCoordinate;
	 //int hrow = headrow - '0';
	 //std::string colstring(1,head_X_Coordinate);

	 if(m_shipDirection=="V"||m_shipDirection=="v"){
	 for(int i=0;i<m_shipLength;i++){
	 		individualShipPlacements[head_YCoordinate+i-1][head_XCoordinate-1]= 'S';
	 	}

	 }
	 if(m_shipDirection=="H"||m_shipDirection=="h"){
	 for(int i=0;i<m_shipLength;i++){
	 	individualShipPlacements[head_YCoordinate-1][head_XCoordinate+i-1]= 'S';

	 	}
	 }

	 	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			//std::cout << individualShipPlacements[i][j] << "     ";
		}
		std::cout << "\n";
	}
}

int Ship::getShipPlacementArray(int i, int j)
{
	 return individualShipPlacements[i][j];
}

void Ship::shipMinusHealth()
{
	m_shipHealth--;
	std::cout << "Ship Health: " << m_shipHealth << "\n";

}

bool Ship::checkIfSunk()
{
	if(m_shipHealth == 0)
	{
		std::cout <<"Size " << m_shipLength << " ship has been sunk\n";
		return(true);
	}
	else
	{
		return(false);
	}
}

int Ship::getHealth()
{
	return m_shipHealth;
}

int Ship::getLength()
{
	return m_shipLength;
}

// std::string* Ship::getArray(){
// 	std::string* arrayptr = m_shipArray;
// 	return(arrayptr);
// }


// bool Ship::isDestroyed(){
// 	if(m_hullIntegrity == 0){
// 		return(true);
// 	}
// 	else{
// 		return(false);
// 	}
// }

// bool Ship::isHit(int row, char col){
// 	bool Hit=false;
// 	std::string hitcoords;
// 	char capCol= capitalize(col);
// 	std::string hitcol(1,capCol);
// 	hitcoords = hitcol + numToString(row);
// 	for(int i=0; i<6; i++){
// 		if(m_shipArray[i]==hitcoords){
// 			Hit=true;
// 			m_hullIntegrity--;
// 			//isDestroyed();?
// 		}
// 	}
// 	return(Hit);
// }


// void Ship::shipDocks(){
// 	std::cout << "\nThe head of this ship is located at : " << m_shipHead << "\n";
// 	std::cout << "The orientation of this ship is : " << m_shipDirection << "\n";
// 	std::cout << "The length of this ship is :" << m_shipLength << "\n";

// 	//
// 	for(int i = 0; i < m_shipLength; i++){

// 	}


// }
