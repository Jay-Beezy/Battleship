//Executive.cpp

#include "Executive.h"
#include "AI.h"
#include <iostream>



Executive::Executive(){ //constructor
	//playerOneGrid = new int*[10];
	//playerTwoGrid = new int*[10];
	//for(int i = 0; i < 10; i++){
		//playerOneGrid[i] = new int[10];
		//playerTwoGrid[i] = new int[10];
	//}
	//fillGrids();
}

Executive::~Executive() //deconstructor
{
	
}

void Executive::run() 
{  //runs the program
	int turn = 1;
	int difficulty = 1;
	int choice = 0;
	std::cout << "\e[8;50;105t";

	std::cout << "+-+-+-+-+-+-+-BATTLESHIP-+-+-+-+-+-+-+\n";

	int shipAmount = 0;
	std::cout <<"Play with Human(1) or AI(2): ";
	std::cin >> choice;

	if(choice == 2){
		std::cout <<"What AI Difficulty? (1 for easy, 2 for medium, 3 for hard): ";
		std::cin >> difficulty;
	}
	std::cout << "How many ships do you want to use?: ";
	std::cin >> shipAmount;

	while(shipAmount <= 0 || shipAmount > 6 || std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "How many ships do you want to use?\n";
		std::cin >> shipAmount;
		if(std::cin.fail()){
			std::cout << "ERROR: Please enter an integer.\n";
		}
		else if(shipAmount <= 0 || shipAmount > 6){
			std::cout << "ERROR: Please enter an integer within the bounds [1, 6].\n";
		}
		std::cout << std::endl;
	}

	Player* playerOne = new Player(shipAmount, "One");
	Parent* playerTwo;

	std::cout << "\nPlayer One's turn to place their ships!\n\n";
	//Populating Player 1
	playerOne->showFiringBoard("One");
	for(int i = 0; i < shipAmount; i++){
		playerOne->placeShips(i+1);
	}
	if(choice == 1)
	{
		playerTwo = new Player(shipAmount, "Two");
		std::cout << "\nPlayer Two's turn to place their ships!\n\n";
		changeTurns();
		//Populating Player 2
		playerTwo->showFiringBoard("Two");	
		for(int i = 0; i < shipAmount; i++)
		{
			playerTwo->placeShips(i+1);
		}
	}
	else
	{
		playerTwo = new AI(difficulty, shipAmount);
		std::cout << "\nAI is placing their ships.\n\n";
		for(int i = 0; i < shipAmount; i++)
		{
			playerTwo->placeShips(i+1);
		}
		playerTwo->showShipPlacement();
	}
	std::cout << "\nPlayer One's turn to fire!\n\n";
	//changeTurns();
	do{
		if(turn == 1){
			takeTurn(playerOne, playerTwo, "One");
			turn++;
		}
		else{
			takeTurn(playerTwo, playerOne, "Two");
			turn--;
		}
		if(!isWinner(playerOne, playerTwo)){
		changeTurns();
		}
	}while(!isWinner(playerOne, playerTwo));
}

void Executive::takeTurn(Parent* player, Parent* opp, std::string id){
	player->showFiringBoard(id);
	player->showShipPlacement(id);
	player->takeShot(opp);
}

bool Executive::charIsValid(char coord){
	return(coord == 'a' || coord == 'A' || coord == 'b' || coord == 'B' || coord == 'c' || coord == 'C' || coord == 'd' || coord == 'D' || coord == 'e' || coord == 'E' || coord == 'f' || coord == 'F' || coord == 'g' || coord == 'G' || coord == 'h' || coord == 'H' || coord == 'i' || coord == 'I' || coord == 'j' || coord == 'J');
}

bool Executive::isWinner(Player* playerOne, Parent* playerTwo){
 	if(playerOne->shipsRemaining() == 0) {
		std::cout <<"\n\n\nPlayer One Wins\n\n\n";
		exit(1);
 		return(true);
 	}
	if(playerTwo->shipsRemaining() == 0) {
		std::cout <<"\n\n\nPlayer Two Wins\n\n\n";
		exit(1);
 		return(true);
 	}
 	return(false);
 }
 
  void Executive::changeTurns(){
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	system("clear");
	std::cout << "Switching turns in: 3\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	system("clear");
	std::cout << "Switching turns in: 2\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	system("clear");
	std::cout << "Switching turns in: 1\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	system("clear");
 }