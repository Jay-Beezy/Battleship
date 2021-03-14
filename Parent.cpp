#include "Parent.h"
#include <iostream>

void Parent::showFiringBoard(std::string turnPlayer){
}

void Parent::showShipPlacement(std::string turnPlayer){
}

void Parent::placeShips(int length){
}

void Parent::takeShot(Parent* opp){
}

void Parent::shipHit(Ship& ship)
{
}

const int Parent::shipsRemaining()
{
	return 0;
}

void Parent::showShipPlacement(){
	std::cout << "+------------------------------------------AI's  Board------------------------------------------+\n";
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

void Parent::setCharge(){

}

void Parent::setShipGrid(int x, int y, char set){

}

char Parent::getShipGrid(int x, int y){
	return('\0');
}

std::string Parent::returnID(){
	return("PARENT");
}