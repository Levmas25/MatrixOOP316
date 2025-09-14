#pragma once

#include "line.h"

class AppManager{
    private:
        int _consoleHeight;
        int _consoleWidth;
        int _lineSpeed;
        int _lineLength;
        bool _epilepsy;

        const char* invalidLineSpeedErrorMsg = "Line speed must be integer in range [1;30]";
        const char* invalidLineLengthErrorMsg = "Line length must be integer in range [1;30]";
        const char* invalidEpilepcyErrorMsg = "Epilepsy must be y or n";

    public:
        AppManager();
        AppManager(char* lineSpeed, char* lineLength, char* epilepcy);
        int* ValidateInput(char* lineSpeed, char* lineLength, char* epilepsy);
        void ConsoleInput();
        void GenerateLine();
        void SetUp();
};