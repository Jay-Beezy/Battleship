#include "AI.h"

AI::AI(int difficulty, int ships){
	srand((unsigned) time(0));
	mode = 0; // memory variable for diff 2 recursive function
	mX = 0; //memory variables for recursion
	mY = 0;
	nX = 0;
	nY = 0;
    while(difficulty < 1 || difficulty > 3)
    {
        std::cerr << "ERROR: Invalid difficulty input. Please enter a valid on the bound [1,3]: ";
        std::cin >> difficulty;
    }
    m_difficulty = difficulty;
    shipArray = new Ship*[ships];
    m_ships = ships;
    m_shipHealth = 0;
    for(int i = 1; i <= m_ships; i++){
        m_shipHealth = m_shipHealth + i;
    }
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
}

AI::~AI(){
    for(int i = 0; i < 10; i++)
	{
		delete shipGrid[i];
		delete shotGrid[i];
	}
	for(int i = 0; i < m_ships; i++)
	{
		delete shipArray[i];
	}
	delete[] shipGrid;
	delete[] shotGrid;
	delete[] shipArray;
}

void AI::takeShot(Parent* opp){
    int xCoord = 0;//these were '\0' before so i changed them to 0
    int yCoord = 0;
    srand((unsigned) time(0));
    std::cout << "AI is firing on your ships!\n\n";
    if(m_difficulty == 1){
        do{
        xCoord = rand() % 10;
        yCoord = rand() % 10;
        }while(opp->getShipGrid(yCoord, xCoord) == 'H' || opp->getShipGrid(yCoord, xCoord) == 'M');
        checkGrid(xCoord + 1, yCoord + 1, opp);
    }
    else if(m_difficulty == 2){
        takeShot2(opp);
    }
    else if(m_difficulty == 3){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(opp->getShipGrid(i, j) == 'S'){
                    xCoord = j;
                    yCoord = i;
                    checkGrid(xCoord + 1, yCoord + 1, opp);
                    return;
                }
            }
        }
    }
}

void AI::takeShot2(Parent* opp){
	int xCoord = 0;
    int yCoord = 0;
	if(mode == 1)//currently working on a shot
	{
		if(takeShotR(opp, 0))
		{
			if(takeShotR(opp,1))
			{
				if(takeShotR(opp,2))
				{
					if(takeShotR(opp,3))
					{
						//if this is true it has tried every place around the first hit
						mode = 0;
					}
				}
			}
		}
	}
	if(mode == 0)//need to find a ship
	{
		do{//generate a shot, set it up for recursion if it is a ship, then send it.
            xCoord = rand() % 10;
            yCoord = rand() % 10;
			if(opp->getShipGrid(xCoord, yCoord) == 'S')
			{
				//change mode and save hit
				mX = xCoord;
				mY = yCoord;
				mode = 1;
			}
			
		}while(checkGrid(xCoord + 1, yCoord + 1, opp));
	}
}

bool AI::takeShotR(Parent* opp, int direction){
	//return true when I hit the end of this chain
	//ship grid can be 0 M H or S
	//by nature this function is centered on a H,
	//if im looking up, I pass H and if I see an S or 0 I shoot, if I see an M the chain is over
	nX = mX;
	nY = mY;
	do{
		// i need to try and shoot the next block, if its an empty and it fails chain is over.
		if(direction == 0)//up
		{
			nY = nY - 1;
			if(nY < 0)
			{
				return true;//signal i cant go any further
			}
			//check if it is a hit or miss
			if(opp->getShipGrid(nY, nX) == '0' || opp->getShipGrid(nY, nX) == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->getShipGrid(nY, nX) == 'M')
			{
				return true;//signal chain is over
			}
		}
		else if(direction == 1)//right
		{
			nX = nX + 1;
			if(nX > 9)
			{
				return true;//signal i cant go any further
			}
			//check if it is a hit or miss
			if(opp->getShipGrid(nY, nX) == '0' || opp->getShipGrid(nY, nX) == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->getShipGrid(nY, nX) == 'M')
			{
				return true;//signal chain is over
			}
		}
		else if(direction == 2)//down
		{
			nY = nY + 1;
			if(nY > 9)
			{
				return true;//signal i cant go any further
			}
			//check if it is a hit or miss
			if(opp->getShipGrid(nY, nX) == '0' || opp->getShipGrid(nY, nX) == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->getShipGrid(nY, nX) == 'M')
			{
				return true;//signal chain is over
			}
		}
		else if(direction == 3)//left
		{
			nX = nX - 1;
			if(nX < 0)
			{
				return true;//signal i cant go any further
			}
			//check if it is a hit or miss
			if(opp->getShipGrid(nY, nX) == '0' || opp->getShipGrid(nY, nX) == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->getShipGrid(nY, nX) == 'M')
			{
				return true;//signal chain is over
			}
		}
	}while(1);//while(checkGrid(nX + 1, nY + 1, opp))
}

void AI::placeShips(int length){
	int shipStarterCol;
	int shipStarterRow = 0;
	int shipLength = length;
	std::string shipLocation;
	std::string shipPlacement;

    do{
        if (rand() % 2 == 0){
        shipPlacement = "V";
        shipStarterCol = rand() % 10;
        shipStarterRow = rand() % (11-length);
        }
        else{
            shipPlacement = "H";
            shipStarterCol = rand() % (11-length);
            shipStarterRow = rand() % 10;	
        }
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
    shipArray[shipLength-1] = new Ship(shipStarterCol+1, shipStarterRow+1, shipPlacement, shipLength);
}

const int AI::shipsRemaining(){
    int retShipCount = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(shipGrid[i][j] == 'S'){
				retShipCount++;
			}
		}
	}
	return(retShipCount);
}

bool AI::validatePosition(int row, int colnum, std::string direction, int shipLength)
{
	bool isValid = false;
	if(direction=="H" || direction == "h")
	{
		for(int i=0;i<shipLength;i++)
		{
			if((colnum)<=10 && shipGrid[row][colnum]=='0'){
				isValid = true;
			}
			else if(shipGrid[row][colnum]=='S')
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
			if(row <= 10 && shipGrid[row][colnum]=='0' ){
				isValid = true;
			}
			else if(row>10)
			{
				return(false);
			}
			else if(shipGrid[row][colnum]=='S')
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

bool AI::checkGrid(int colnum, int numberInput, Parent* otherPlayer){
		if(otherPlayer->getShipGrid(numberInput-1, colnum-1) == 'S'){
			shotGrid[numberInput-1][colnum-1] = 'H';
			otherPlayer->setShipGrid(numberInput-1, colnum-1,  'H');
			m_shipHealth--;
            for(int i = 0; i < m_ships;i++)
			{
				if(otherPlayer->shipArray[i]->getShipPlacementArray(numberInput-1,colnum-1) == 'S')
				 {
					std::cout << "The AI hit your size "<< otherPlayer->shipArray[i]->getLength();
					std::cout << " ship at "<< intToCol(colnum - 1) << numberInput <<"!\n";
					std::this_thread::sleep_for(std::chrono::milliseconds(1500));
					otherPlayer->shipArray[i]->shipMinusHealth();
				 	if(otherPlayer->shipArray[i]->checkIfSunk())
					{
						m_numberOfShips--;
						otherPlayer->setCharge();
					}
				 }
			}
		}
		else if(shotGrid[numberInput-1][colnum-1]=='0'){
			std::cout << "The AI missed your ships.\n";
            shotGrid[numberInput-1][colnum-1] = 'M';
			otherPlayer->setShipGrid(numberInput-1, colnum-1, 'M');
		}
		else { //'M' and 'H' cases - require re-do
			return(true);
		}		
		return(false);
}

void AI::setShipGrid(int x, int y, char set){
	shipGrid[x][y] = set;
}

char AI::getShipGrid(int x, int y){
	return(shipGrid[x][y]);
}

std::string AI::returnID(){
	return("AI");
}

const char AI::intToCol(int num){
	if(num == 0){
		return 'A';
	} else if(num == 1){
		return 'B';
	} else if(num == 2){
		return 'C';
	} else if(num == 3){
		return 'D';
	} else if(num == 4){
		return 'E';
	} else if(num == 5){
		return 'F';
	} else if(num == 6){
		return 'G';
	} else if(num == 7){
		return 'H';
	} else if(num == 8){
		return 'I';
	} else if(num == 9){
		return 'J';
	} else{
		return '\0';
	}
}