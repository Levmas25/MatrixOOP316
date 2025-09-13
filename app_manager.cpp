#include "app_manager.h"
#include<stdexcept>
#include<cstdlib>

#include<iostream>


int* AppManager::ValidateInput(char* lineSpeed, char* lineLength, char* epilepsy){

    int _lineSpeed = std::atoi(lineSpeed);
    int _lineLength = std::atoi(lineLength);

    if (_lineSpeed == 0)
        throw std::invalid_argument(this->invalidLineSpeedErrorMsg);

    if (_lineLength == 0)
        throw std::invalid_argument(this->invalidLineLengthErrorMsg);
    
    int _epilepsy;
    if (epilepsy[0] == 'Y' || epilepsy[0] == 'y') _epilepsy = 1;
    else if(epilepsy[0] == 'N' || epilepsy[0] == 'n') _epilepsy = 0;
    else throw std::invalid_argument(this->invalidEpilepcyErrorMsg);

    if (_lineSpeed > 30 || _lineSpeed < 1){
        throw std::invalid_argument(this->invalidLineSpeedErrorMsg);
    }
    
    if (_lineLength > 30 || _lineLength < 1){
        throw std::invalid_argument(this->invalidLineLengthErrorMsg);
    }

    return new int[3] {_lineSpeed, _lineLength, _epilepsy};
}

AppManager::AppManager(char* lineSpeed, char* lineLength, char* epilepsy){
    int* validatedData = AppManager::ValidateInput(lineSpeed, lineLength, epilepsy);
    this->lineSpeed = validatedData[0];
    this->lineLength = validatedData[1];
    this->epilepsy = validatedData[2];

    std::cout << this->lineSpeed;
    std::cout << this->lineLength;
    std::cout << this->epilepsy;
}