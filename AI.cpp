#include "AI.h"

AI::AI(int difficulty, int ships){
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
    std::cout << "AI is firing on your ships!\n";
    do{

        if(m_difficulty == 1){
            srand((unsigned) time(0));
            xCoord = rand() % 10;
            srand((unsigned) time(0));
            yCoord = rand() % 10;
        }
        else if(m_difficulty == 2){
            takeShot2(opp);
			/*srand((unsigned) time(0));
            xCoord = rand() % 10;
            srand((unsigned) time(0));
            yCoord = rand() % 10;
            //recursive shot
			*/
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
    }while(checkGrid(xCoord + 1, yCoord + 1, opp));
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
			srand((unsigned) time(0));
            xCoord = rand() % 10;
            srand((unsigned) time(0));
            yCoord = rand() % 10;
			if(opp->shipGrid[xCoord][yCoord] == 'S')
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
			if(opp->shipGrid[nY][nX] == '0' || opp->shipGrid[nY][nX] == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->shipGrid[nY][nX] == 'M')
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
			if(opp->shipGrid[nY][nX] == '0' || opp->shipGrid[nY][nX] == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->shipGrid[nY][nX] == 'M')
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
			if(opp->shipGrid[nY][nX] == '0' || opp->shipGrid[nY][nX] == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->shipGrid[nY][nX] == 'M')
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
			if(opp->shipGrid[nY][nX] == '0' || opp->shipGrid[nY][nX] == 'S')
			{
				checkGrid(nX + 1, nY + 1, opp);
				return false;//signal to move on,
			}
			else if(opp->shipGrid[nY][nX] == 'M')
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
        srand((unsigned) time(0));
        if (rand() % 2 == 0){
        shipPlacement = "V";
        srand((unsigned) time(0));
        shipStarterCol = rand() % 10;
        srand((unsigned) time(0));
        shipStarterRow = rand() % (11-length);
        }
        else{
            shipPlacement = "H";
            srand((unsigned) time(0));
            shipStarterCol = rand() % (11-length);
            srand((unsigned) time(0));
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
    return(m_shipHealth);
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
		if(otherPlayer->shipGrid[numberInput-1][colnum-1]== 'S'){
			shotGrid[numberInput-1][colnum-1] = 'H';
			otherPlayer->shipGrid[numberInput-1][colnum-1] = 'H';
			m_shipHealth--;
		}
		else if(shotGrid[numberInput-1][colnum-1]=='H'){
            return(true);
		}
		else {
			shotGrid[numberInput-1][colnum-1] = 'M';
			otherPlayer->shipGrid[numberInput-1][colnum-1] = 'M';	
		}		
        return(false);
}

