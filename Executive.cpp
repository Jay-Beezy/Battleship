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
	//for(int i = 0; i < 10; i++)
	//{
	//	delete playerOneGrid[i];
	//	delete playerTwoGrid[i];
	//}
	//delete[] playerOneGrid;
	//delete[] playerTwoGrid;
}

void Executive::run() 
{  //runs the program

	char p1coords = '\0';
	char p2coords = '\0';
	int p1Number = 0;
	int p2Number = 0;
	int difficulty = 1;
	int choice = 0;
	std::cout << "\e[8;50;105t";

	std::cout << "+-+-+-+-+-+-+-BATTLESHIP-+-+-+-+-+-+-+\n";

	int shipAmount = 0;
	std::cout <<"Play with Human(1) or AI(2): ";
	std::cin >> choice;

	if(choice == 2){
		std::cout <<"What Difficulty? (1 for easy, 2 for medium, 3 for hard): ";
		std::cin >> difficulty;
	}
	std::cout << "How many ships do you want to use?\n";
	std::cin >> shipAmount;

	AI robot(difficulty, shipAmount);
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
	//Creating Players
	Player playerOne(shipAmount);
	Player playerTwo(shipAmount);
	std::cout << "\nPlayer One's turn to place their ships!\n\n";
	//Populating Player 1
	playerOne.showFiringBoard("One");
	for(int i = 0; i < shipAmount; i++){
		playerOne.placeShips(i+1);
	}
	std::cout<<"Player One, look away!\n";
	//changeTurns();

	if(choice == 1)
	{
		std::cout << "\nPlayer Two's turn to place their ships!\n\n";
		//Populating Player 2
		playerTwo.showFiringBoard("Two");	
	
		for(int i = 0; i < shipAmount; i++)
		{
			playerTwo.placeShips(i+1);
			//std::cout<<"Player Two, look away!\n";
		}
	}
	else if(choice == 2)
	{
		std::cout << "\nAI is placing their ship.\n\n";
		//Populating Player 2
		robot.showFiringBoard("Two");	
	
		for(int i = 0; i < shipAmount; i++)
		{
			robot.placeShips(i+1);
		}
		robot.showShipPlacement("Robot");
	}
	//changeTurns();

	//OG grid at beginning of program
	std::cout<<"Time to Begin!\n";
	std::string tempS = "\0";//temporary storage string
	int shotType = 0; //used to determine if power shot has been requested
	while (1)
	{
			std::cout<<"Player One's Firing grid:\n";
			playerOne.showFiringBoard("One");
			//printPlayerOneGrid();//These are the firing grids
			std::cout<<"Player One's Ships:\n";
			playerOne.showShipPlacement("One");// These are your ship placements
			//code for choosing power shot
			if(playerOne.charge == 1)
			{
				do{
					std::cout<<"You have a Power Shot! Would you like to use it?(Y/N): ";
					std::cin>>tempS;
				}while(!(tempS == "Y" || tempS == "y" || tempS == "N" || tempS == "n"));
				if(tempS == "Y" || tempS == "y")
				{
					shotType = 1;
				}
				else
				{
					shotType = 0;
				}
			}
			std::cout<<"Player One, enter coordinates of the space you'd like to fire on.\n";
			do
			{
				std::cout<<"Player One, enter letter of the space you'd like to fire on: ";
				std::cin>>p1coords;
				if(!charIsValid(p1coords))
				{
					std::cout << "ERROR: Please enter an character within the bounds [A, J].\n";
				}
			}while(!charIsValid(p1coords));
			do
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout<<"Player One, enter number of the space you'd like to fire on: ";
				std::cin>>p1Number;
				if(std::cin.fail())
				{
					std::cout << "ERROR: Please enter an integer.\n";
				}
				else if(p1Number < 1 || p1Number > 10)
				{
					std::cout << "ERROR: Please enter an integer within the bounds [1, 10].\n";
				}
			}while(std::cin.fail() || p1Number < 1 || p1Number > 10);
			std::cout << "\n";
			
		if(playerOne.getShotGrid(p1coords,p1Number) == '0')
		{
			if(choice ==1)
			{
				if(shotType == 1)
				{
					playerOne.checkPower(p1coords,p1Number,playerTwo);
				}	
				else
				{
					playerOne.checkGrid(p1coords,p1Number,playerTwo);
				}
			}
			else if(choice == 2)
			{
				if(shotType == 1)
				{
					playerOne.checkGrid(p1coords,p1Number,robot);
				}	
				else
				{
					playerOne.checkGrid(p1coords,p1Number,robot);
				}
			}
			std::cout << "\n";
		}
		else if (playerOne.getShotGrid(p1coords,p1Number)=='H' || playerOne.getShotGrid(p1coords,p1Number)=='M')
		{	
			while(1)
			{
				std::cout <<"Shot already hit, please try again\n\n";
				std::cout<<"Player One, enter coordinates of the space you'd like to fire on.\n";
				do
				{
					std::cout<<"Player One, enter letter of the space you'd like to fire on: ";
					std::cin>>p1coords;
					if(!charIsValid(p1coords))
					{
					std::cout << "ERROR: Please enter an character within the bounds [A, J].\n";
					}
				}while(!charIsValid(p1coords));
				do
				{
					std::cin.clear();
					std::cin.ignore(100, '\n');
					std::cout<<"Player One, enter number of the space you'd like to fire on: ";
					std::cin>>p1Number;
					if(std::cin.fail()){
						std::cout << "ERROR: Please enter an integer.\n";
					}
					else if(p1Number < 1 || p1Number > 10){
						std::cout << "ERROR: Please enter an integer within the bounds [1, 10].\n";
					}
				}while(std::cin.fail() || p1Number < 1 || p1Number > 10);
				std::cout << "\n";
				if(playerOne.getShotGrid(p1coords,p1Number)=='0')
				{
				//playerOne.checkGrid(p1coords,p1Number, playerTwo);
							//I noticed this didn't have provesions for the ai options so I thought id add them,
							//im leaving this spaced weird so its easy to find, if you dont see any problems go 
							//ahead and delete this commit
							if(choice ==1)
							{
								if(shotType == 1)
								{
									playerOne.checkPower(p1coords,p1Number,playerTwo);
								}	
								else
								{
									playerOne.checkGrid(p1coords,p1Number,playerTwo);
								}
							}
							else if(choice == 2)
							{
								if(shotType == 1)
								{
									playerOne.checkGrid(p1coords,p1Number,robot);
								}	
								else
								{
									playerOne.checkGrid(p1coords,p1Number,robot);
								}
							}
										
				std::cout << "\n";
				break;
				}
			}
		}

		if(choice == 1)
			{
				isWinner(playerOne,playerTwo);
				//changeTurns();
				std::cout<<"Player Two's Firing grid:\n";
				playerTwo.showFiringBoard("Two");
				//printPlayerTwoGrid();//These are the firing grids
				std::cout<<"Player Two's Ships:\n";
				playerTwo.showShipPlacement("Two");// These are your ship placements
				//code for player two select power shot
				if(playerTwo.charge == 1)
				{
					do{
						std::cout<<"You have a Power Shot! Would you like to use it?(Y/N): ";
						std::cin>>tempS;
					}while(!(tempS == "Y" || tempS == "y" || tempS == "N" || tempS == "n"));
					if(tempS == "Y" || tempS == "y")
					{
						shotType = 1;
					}
					else
					{
						shotType = 0;
					}
				}
				std::cout<<"Player Two, enter coordinates of the space you'd like to fire on.\n";
				do
				{
					std::cout<<"Player Two, enter letter of the space you'd like to fire on: ";
					std::cin>>p2coords;
					if(!charIsValid(p2coords))
					{
						std::cout << "ERROR: Please enter an character within the bounds [A, J].\n";
					}
				}while(!charIsValid(p2coords));
				do
				{
					std::cin.clear();
					std::cin.ignore(100, '\n');
					std::cout<<"Player Two, enter number of the space you'd like to fire on: ";
					std::cin>>p2Number;
					if(std::cin.fail())
					{
						std::cout << "ERROR: Please enter an integer.\n";
					}
					else if(p2Number < 1 || p2Number > 10)
					{
						std::cout << "ERROR: Please enter an integer within the bounds [1, 10].\n";
					}
				}while(std::cin.fail() || p2Number < 1 || p2Number > 10);
				std::cout << "\n";

				if(playerTwo.getShotGrid(p2coords,p2Number) == '0')
				{
					if(shotType == 1)
					{
						playerTwo.checkPower(p2coords,p2Number,playerOne);
					}	
					else
					{
						playerTwo.checkGrid(p2coords,p2Number,playerOne);
					}
					std::cout << "\n";
				}
				else if (playerTwo.getShotGrid(p2coords,p2Number)=='H' || playerTwo.getShotGrid(p2coords,p2Number)=='M')
				{
					while(1)
					{
						std::cout <<"Shot already hit, please try again\n\n";
						std::cout<<"Player Two, enter coordinates of the space you'd like to fire on.\n";
						do
						{
							std::cout<<"Player Two, enter letter of the space you'd like to fire on: ";
							std::cin>>p2coords;
							if(!charIsValid(p2coords))
							{
								std::cout << "ERROR: Please enter an character within the bounds [A, J].\n";
							}
						}while(!charIsValid(p2coords));
						do
						{
							std::cin.clear();
							std::cin.ignore(100, '\n');
							std::cout<<"Player Two, enter number of the space you'd like to fire on: ";
							std::cin>>p2Number;
							if(std::cin.fail())
							{
								std::cout << "ERROR: Please enter an integer.\n";
							}
							else if(p2Number < 1 || p2Number > 10)
							{
								std::cout << "ERROR: Please enter an integer within the bounds [1, 10].\n";
							}
						}while(std::cin.fail() || p2Number < 1 || p2Number > 10);
						std::cout << "\n";
						if(playerTwo.getShotGrid(p2coords,p2Number)=='0')
						{
							if(shotType == 1)
							{
								playerTwo.checkPower(p2coords,p2Number,playerOne);
							}	
							else
							{
								playerTwo.checkGrid(p2coords,p2Number,playerOne);
							}
							std::cout << "\n";
							break;
						}
					}	
				}
				//changeTurns();
				isWinner(playerOne,playerTwo);
			}
			else if(choice == 2)
			{
				isWinner(playerOne,robot);
				//changeTurns();
				std::cout<<"Robot's Firing grid:\n";
				robot.showFiringBoard("robot");
				std::cout<<"Robot's Ships:\n";
				robot.showShipPlacement("robot");// These are your ship placements
				
				//changeTurns();
				isWinner(playerOne,robot);
			}
	}
	

}

void Executive::takeTurn(Parent& player){
	//print player map
	//player takes shot
	//shot feedback
}

bool Executive::charIsValid(char coord){
	return(coord == 'a' || coord == 'A' || coord == 'b' || coord == 'B' || coord == 'c' || coord == 'C' || coord == 'd' || coord == 'D' || coord == 'e' || coord == 'E' || coord == 'f' || coord == 'F' || coord == 'g' || coord == 'G' || coord == 'h' || coord == 'H' || coord == 'i' || coord == 'I' || coord == 'j' || coord == 'J');
}

// void Executive::fillGrids(){
// 	for(int i = 0; i < 10; i++){
// 		for(int j = 0; j < 10; j++){
// 			playerOneGrid[i][j] = 0;
// 			playerTwoGrid[i][j] = 0;
// 		}
// 	}
// }

// void Executive::printPlayerOneGrid(){
// 	std::cout << "+------------------------------------------Player One's Board-------------------------------------------+\n";
// 	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
// 	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
// 	for(int i = 0; i < 10; i++){
// 		for(int j = 0; j < 10; j++){
// 			if(j == 0){
// 				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerOneGrid[i][j] << "\t";
// 			}
// 			else if(j == 9){
// 				std::cout << playerOneGrid[i][j] << "\t" << "|";
// 			}
// 			else{
// 				std::cout << playerOneGrid[i][j] << "\t";
// 			}
// 		}
// 		std::cout << "\n";
// 	}
// 	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
// }

// void Executive::printPlayerTwoGrid(){
// 	std::cout << "+------------------------------------------Player Two's Board-------------------------------------------+\n";
// 	std::cout << "|			A	B	C	D	E	F	G	H	I	J	|\n";
// 	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
// 	for(int i = 0; i < 10; i++){
// 		for(int j = 0; j < 10; j++){
// 			if(j == 0){
// 				std::cout << "|" << "\t" << i+1 << "\t" << "|" << "\t" << playerTwoGrid[i][j] << "\t";
// 			}
// 			else if(j == 9){
// 				std::cout << playerTwoGrid[i][j] << "\t" << "|";
// 			}
// 			else{
// 				std::cout << playerTwoGrid[i][j] << "\t";
// 			}
// 		}
// 		std::cout << "\n";
// 	}
// 	std::cout << "+---------------+---------------------------------------------------------------------------------------+\n";
// }

 bool Executive::isWinner(Player playerOne, Parent playerTwo){
 	if(playerOne.shipsRemaining() == 0) {
		 std::cout <<"\n\n\nPlayer One Wins\n\n\n";
		 exit(1);
 		return(true);
 	} else if(playerTwo.shipsRemaining() == 0) {
		std::cout <<"\n\n\nPlayer Two Wins\n\n\n";
		exit(1);
 		return(true);
 	} else {
 		return(false);
 	}
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
