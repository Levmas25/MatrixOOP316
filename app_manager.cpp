#include<stdexcept>
#include<cstdlib>
#include <string> 
#include<iostream>

#include "app_manager.h"
#include "console_manager.h"
#include "colors.h"
#include "random_engine.h"
#include "line.h"


const std::string AppManager::_invalidLineSpeedErrorMsg = "\nLine speed must be integer in range [1;30]\n\n";
const std::string AppManager::_invalidLineLengthErrorMsg = "\nLine length must be integer in range [1;30]\n\n";
const std::string AppManager::_invalidEpilepcyErrorMsg = "\nEpilepsy must be y or n\n\n";
const std::string AppManager::_invalidArgumentCountMsg = "Error! Must provide 3 or 0 arguments.\n"
"To see help message run program with -h(--help) flag\n";

const std::string AppManager::_lineSpeedInputMsg = "Enter the line speed(integer in range 1-30): ";
const std::string AppManager::_lineLengthInputMsg = "Enter the line legth(integer in range 1-30): ";
const std::string AppManager::_epilepcyModeInputMsg = "Turn on epilepsy mode? [y\\N]: ";

const std::string AppManager::_helpMsg = "This is the console matrix program.\n"
"To run the program you need to provie line speed(integer 1-30), line length(integer 1-30) "
"and the epilepsy mode flag.\n"; 


int* AppManager::ValidateInput(std::string lineSpeed, std::string lineLength, std::string epilepsy){

    int _lineSpeed = std::stoi(lineSpeed);
    int _lineLength = std::stoi(lineLength);

    if (_lineSpeed == 0)
        throw std::invalid_argument(_invalidLineSpeedErrorMsg);

    if (_lineLength == 0)
        throw std::invalid_argument(_invalidLineLengthErrorMsg);
    
    int _epilepsy;
    if (epilepsy[0] == 'Y' || epilepsy[0] == 'y') _epilepsy = 1;
    else if(epilepsy[0] == 'N' || epilepsy[0] == 'n') _epilepsy = 0;
    else throw std::invalid_argument(_invalidEpilepcyErrorMsg);

    if (_lineSpeed > 30 || _lineSpeed < 1){
        throw std::invalid_argument(_invalidLineSpeedErrorMsg);
    }
    
    if (_lineLength > 30 || _lineLength < 1){
        throw std::invalid_argument(_invalidLineLengthErrorMsg);
    }

    return new int[3] {_lineSpeed, _lineLength, _epilepsy};
}

AppManager::AppManager(std::string lineSpeed, std::string lineLength, std::string epilepsy){
    bool errors = false;

    try {
        int* validatedData = ValidateInput(lineSpeed, lineLength, epilepsy);
        _lineSpeed = validatedData[0];
        _lineLength = validatedData[1];
        _epilepsy = validatedData[2];

        delete[] validatedData;
    }
    catch (const std::invalid_argument& e){
        std::cout << e.what();
        ValidateDataLoop();
    }

    SetUp();
}

void AppManager::DisplayInvaidArgumentCountMsg(){
    std::cout << _invalidArgumentCountMsg;
}

void AppManager::ValidateDataLoop(){
    bool errors = false;

    do {
        try {
            int* validatedData = ReadInputFromConsole();
            _lineSpeed = validatedData[0];
            _lineLength = validatedData[1];
            _epilepsy = validatedData[2];
            errors = false;

            delete[] validatedData;
        }
        catch (const std::invalid_argument& e){
            std::cout << e.what();
            errors = true;
        }
    }
    while (errors);
}

void AppManager::SetUp(){
    std::cout << std::unitbuf;
    RandomEngine::Init();
    ConsoleManager::ClearScreen();
    ConsoleManager::SetConsoleColor(WHITE);
}

int* AppManager::ReadInputFromConsole(){
    std::string lineSpeed;
    std::string lineLength;
    std::string epilepcy;

    std::cout << _lineSpeedInputMsg;
    std::cin >> lineSpeed;

    std::cout << _lineLengthInputMsg;
    std::cin >> lineLength;

    std::cout << _epilepcyModeInputMsg;
    std::cin >> epilepcy;

    return ValidateInput(lineSpeed, lineLength, epilepcy);
}

AppManager::AppManager(){
    ValidateDataLoop();

    SetUp();
}

void AppManager::Run(){
    while (true){
        GenerateLine();
    }
}

void AppManager::DisplayHelpText(){
    std::cout << _helpMsg;
}


void AppManager::GenerateLine(){
    int* consoleSize = ConsoleManager::GetConsoleSize();
    int randomRow = RandomEngine::RandInt(0, consoleSize[0]);

    // We cant launch our line on the last row
    while (randomRow == consoleSize[0] || randomRow == 0){
        randomRow = RandomEngine::RandInt(0, consoleSize[0]);
    }

    int color;
    if (_epilepsy) {
        color = RandomEngine::RandInt(BLACK, WHITE+8);
        // Offset of bright colors
        if (color > WHITE) color = color - 8 + 60;
    }
    else color = WHITE;

    Line line = Line(_lineLength, randomRow, _lineSpeed, color);
    line.Move();
}