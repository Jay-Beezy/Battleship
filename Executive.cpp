//Executive.cpp

#include "Executive.h"
#include <iostream>


Executive::Executive(){ //constructor
	playerOneGrid = new int*[10];
	playerTwoGrid = new int*[10];
	for(int i = 0; i < 10; i++){
		playerOneGrid[i] = new int[10];
		playerTwoGrid[i] = new int[10];
	}
	fillGrids();
}

Executive::~Executive() //deconstructor
{
	for(int i = 0; i < 10; i++)
	{
		delete playerOneGrid[i];
		delete playerTwoGrid[i];
	}
	delete[] playerOneGrid;
	delete[] playerTwoGrid;
}

void Executive::run() {  //runs the program
	
	std::string p1coords;
	std::string p2coords;
	
	std::cout << "+-+-+-+-+-+-+-BATTLESHIP-+-+-+-+-+-+-+\n";

	int shipAmount = 0;
	std::cout << "How many ships do you want to use?\n";
	std::cin >> shipAmount;

	while(shipAmount <= 0 || shipAmount > 6 || std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "How many ships do you want to use?\n";
		std::cin >> shipAmount;
	}
	//Creating Players
	playerOne = new Player(shipAmount);
	playerTwo = new Player(shipAmount); 
	
	std::cout << "\nPlayer One's turn to place their ships!\n\n";
	//Populating Player 1
	playerOne.showWaters();
	for(int i = 0; i < shipAmount; i++){
		playerOne.anchorShips(i+1);
	}
	std::cout<<"Player One, look away!\n";

	std::cout << "\nPlayer Two's turn to place their ships!\n\n";
	//Populating Player 2
	playerTwo.showWaters();
	for(int i = 0; i < shipAmount; i++){
		playerTwo.anchorShips(i+1);
	}
	std::cout<<"Player Two, look away!\n";

	//OG grid at beginning of program
	std::cout<<"Time to Begin!\n";
	while (isWinner()!=1 || isWinner()!=2){
		std::cout<<"Player One's Firing grid:\n";
		printPlayerOneGrid();
		std::cout<<"Player One's Ships:\n";
		playerOne.showWaters();
		std::cout<<"Player One, enter coordinates of the space you'd like to fire on.\n";
		std::cin>>p1coords;
		playerTwo.checkGrid(p1coords);
		std::cout<<"Player Two's Firing grid:\n";
		printPlayerTwoGrid();
		std::cout<<"Player Two's Ships:\n";
		playerTwo.showWaters();
		std::cout<<"Player Two, enter coordinates of the space you'd like to fire on.\n";
		std::cin>>p2coords;
		playerOne.checkGrid(p2coords);
	}
	
	delete playerOne;
	delete playerTwo;
		
}

void Executive::fillGrids(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			playerOneGrid[i][j] = 0;
			playerTwoGrid[i][j] = 0;
		}
	}
}

void Executive::printPlayerOneGrid(){
	std::cout << "+------------------------------------------Player One's Board-------------------------------------------+\n";
	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerOneGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << playerOneGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << playerOneGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

void Executive::printPlayerTwoGrid(){
	std::cout << "+------------------------------------------Player Two's Board-------------------------------------------+\n";
	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerTwoGrid[i][j] << "\t";
			}
			else if(j == 9){
				std::cout << playerTwoGrid[i][j] << "\t" << "|";
			}
			else{
				std::cout << playerTwoGrid[i][j] << "\t";
			}
		}
		std::cout << "\n";
	}
	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
}

int Executive::isWinner(){
	if(playerOne.shipsRemaining() == 0) {
		return(1);
	} else if(playerTwo.shipsRemaining() == 0) {
		return(2);
	} else {
		return(0);
	}
}

