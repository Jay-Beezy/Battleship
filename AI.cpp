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

void AI:takeShot(){

}

int AI::retRow(){
    if(m_difficulty == 1){
        
    }
    else if(m_difficulty == 2){
        
    }
    else if(m_difficulty == 3){

    }
    else{
        std::cerr << "ERROR: Invalid difficulty level.\n";
    }
}

int AI::retCol(){
    if(m_difficulty == 1){
        
    }
    else if(m_difficulty == 2){
        
    }
    else if(m_difficulty == 3){

    }
    else{
        std::cerr << "ERROR: Invalid difficulty level.\n";
    }
}