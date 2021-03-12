#include "AI.h"

AI::AI(int difficulty, int ships){
    while(difficulty < 1 || difficulty > 3)
    {
        std::cerr << "ERROR: Invalid difficulty input. Please enter a valid on the bound [1,3]: ";
        std::cin >> difficulty;
    }
    m_difficulty = difficulty;
    shotGrid = new char*[10];
    shipGrid = new char*[10];
    for(int i = 0; i < 10; i++){
        shotGrid[i] = new char[10];
        shipGrid[i] = new char[10];
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            shotGrid[i][j] = '0';
            shipGrid[i][j] = '0';
        }
    }
    shipArray = new Ship*[ships];
    m_numberOfShips = ships;
}

AI::~AI(){
    for(int i = 0; i < 10; i++)
	{
		delete shipGrid[i];
		delete shotGrid[i];
	}
	delete[] shipGrid;
	delete[] shotGrid;
}

void AI::takeShot(Parent* opp){
    int xCoord = 0;//these were '\0' before so i changed them to 0
    int yCoord = 0;
    do{

        if(m_difficulty == 1){
            srand((unsigned) time(0));
            xCoord = rand() % 10;
            srand((unsigned) time(0));
            yCoord = rand() % 10;
        }
        else if(m_difficulty == 2){
            srand((unsigned) time(0));
            xCoord = rand() % 10;
            srand((unsigned) time(0));
            yCoord = rand() % 10;
            //recursive shot
        }
        else if(m_difficulty == 3){
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(opp->shipGrid[i][j] == 'S'){
                        xCoord = j;
                        yCoord = i;
                    }
                }
            }
        }
        else{
            std::cerr << "ERROR: Invalid difficulty level.\n";
        }
    }while(checkGrid(yCoord, xCoord, opp));
}

void AI::placeShips(int length){
	int shipStarterCol;
	int shipStarterRow = 0;
	int shipLength = length;
	std::string shipLocation;
	std::string shipPlacement;

    do{
        srand((unsigned) time(0));
        if (rand() % 2 == 0){
        shipPlacement = "V";
    }
    else{
        shipPlacement = "H";
    }
        srand((unsigned) time(0));
        shipStarterCol = rand() % (11-length);
        srand((unsigned) time(0));
        shipStarterRow = rand() % (11-length);
    }while((validatePosition(shipStarterRow, shipStarterCol, shipPlacement, shipLength)) == false);
    if(shipPlacement == "V"){
            for(int i = 0; i < length; i++){
                shipGrid[shipStarterRow + i][shipStarterCol] = 'S';
            }
    }
    else{
        for(int i = 0; i < length; i++){
            shipGrid[shipStarterRow][shipStarterCol + i] = 'S';
        }
    }
    shipArray[shipLength-1] = new Ship(shipStarterCol, shipStarterRow, shipPlacement, shipLength);
}

const int AI::shipsRemaining(){
    return(m_numberOfShips);
}

bool AI::validatePosition(int row, int colnum, std::string direction, int shipLength)
{
	bool isValid = false;
	if(direction=="H" || direction == "h")
	{
		for(int i=0;i<shipLength;i++)
		{
			if((colnum)<=10 && shipGrid[row-1][colnum-1]=='0'){
				isValid = true;
			}
			else if(shipGrid[row-1][colnum-1]=='S')
			{
				return(false);
			}
			else
			{
				isValid = false;
			}
			colnum++;
		}
	}

	if(direction=="V" || direction == "v"){
		for(int j=0;j<shipLength;j++){
			if(row <= 10 && shipGrid[row-1][colnum-1]=='0' ){
				isValid = true;
			}
			else if(row>10)
			{
				return(false);
			}
			else if(shipGrid[row-1][colnum-1]=='S')
	 		{
				return(false);
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

bool AI::checkGrid(int numberInput, int colnum, Parent* otherPlayer){
		if(otherPlayer->shipGrid[numberInput][colnum]== 'S')
		{
			shotGrid[numberInput][colnum] = 'H';
			otherPlayer->shipGrid[numberInput][colnum] = 'H';
			for(int i = 0; i < m_ships;i++)
			{
				 if(shipArray[i]->getShipPlacementArray(numberInput,colnum) == 'S')
				{
					shipArray[i]->shipMinusHealth();
				 	if(shipArray[i]->checkIfSunk())
					{
						m_numberOfShips--;
						otherPlayer->charge = 1;
					}
				}
			}
		}
		else if(shotGrid[numberInput][colnum]=='H')
		{
			return(true);
		}
		else 
		{
			shotGrid[numberInput][colnum] = 'M';
			otherPlayer->shipGrid[numberInput][colnum] = 'M';	
		}		
        return(false);
}