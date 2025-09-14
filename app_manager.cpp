#include "app_manager.h"
#include "console_manager.h"
#include "colors.h"
#include "random_engine.h"
#include "line.h"
#include<stdexcept>
#include<cstdlib>

#include<iostream>


int* AppManager::ValidateInput(char* lineSpeed, char* lineLength, char* epilepsy){

    int _lineSpeed = std::atoi(lineSpeed);
    int _lineLength = std::atoi(lineLength);

    if (_lineSpeed == 0)
        throw std::invalid_argument(invalidLineSpeedErrorMsg);

    if (_lineLength == 0)
        throw std::invalid_argument(invalidLineLengthErrorMsg);
    
    int _epilepsy;
    if (epilepsy[0] == 'Y' || epilepsy[0] == 'y') _epilepsy = 1;
    else if(epilepsy[0] == 'N' || epilepsy[0] == 'n') _epilepsy = 0;
    else throw std::invalid_argument(invalidEpilepcyErrorMsg);

    if (_lineSpeed > 30 || _lineSpeed < 1){
        throw std::invalid_argument(invalidLineSpeedErrorMsg);
    }
    
    if (_lineLength > 30 || _lineLength < 1){
        throw std::invalid_argument(invalidLineLengthErrorMsg);
    }

    return new int[3] {_lineSpeed, _lineLength, _epilepsy};
}

AppManager::AppManager(char* lineSpeed, char* lineLength, char* epilepsy){
    int* validatedData = ValidateInput(lineSpeed, lineLength, epilepsy);
    _lineSpeed = validatedData[0];
    _lineLength = validatedData[1];
    _epilepsy = validatedData[2];

    delete lineSpeed;
    delete lineLength;
    delete epilepsy;
}

void AppManager::SetUp(){
    ConsoleManager::ClearScreen();
    ConsoleManager::SetColor(WHITE);
    if (_epilepsy) ConsoleManager::SetColor(GREEN);
    this->GenerateLine();
}


void AppManager::GenerateLine(){
    int* consoleSize = ConsoleManager::GetConsoleSize();
    int randomRow = RandomEngine::randInt(0, consoleSize[0]);

    // We cant launch our line on the last row
    while (randomRow == consoleSize[0]){
        randomRow = RandomEngine::randInt(0, consoleSize[0]);
    }

    Line line = Line(_lineLength, randomRow, _lineSpeed);
    line.Move();
}