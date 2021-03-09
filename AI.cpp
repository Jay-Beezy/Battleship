#include "AI.h"

AI::AI(int difficulty){
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
        for(int j = 0; j < 10; i++){
            shotGrid[i][j] = '0';
            shipGrid[i][j] = '0';
        }
    }
}

AI::~AI(){
}

void AI::takeShot(char** oppGrid){
    int xCoord = '/0';
    int yCoord = '/0';
    if(m_difficulty == 1){
        srand((unsigned) time(0));
        xCoord = rand() % 10;
        srand((unsigned) time(0));
        yCoord = rand() % 10;
        oppGrid[yCoord][xCoord] = 'X';   
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
                if(oppGrid)[i][j] == 'S'){
                    oppGrid[i][j] = 'X';
                    //may need Ship object functions to display when AI has sunk a ship or to check win condition.
                    return;
                }
            }
        }
    }
    else{
        std::cerr << "ERROR: Invalid difficulty level.\n";
    }
}