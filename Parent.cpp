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