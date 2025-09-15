#pragma once

#include "line.h"
#include <string>

class AppManager{
    private:
        int _consoleHeight;
        int _consoleWidth;
        int _lineSpeed;
        int _lineLength;
        bool _epilepsy;

        const std::string _invalidLineSpeedErrorMsg = "\nLine speed must be integer in range [1;30]\n";
        const std::string _invalidLineLengthErrorMsg = "\nLine length must be integer in range [1;30]\n";
        const std::string _invalidEpilepcyErrorMsg = "\nEpilepsy must be y or n\n";

        const std::string _lineSpeedInputMsg = "Enter the line speed(integer in range 1-30): ";
        const std::string _lineLengthInputMsg = "Enter the line legth(integer in range 1-30): ";
        const std::string _epilepcyModeInputMsg = "Turn on epilepsy mode? [y\\N]: ";

    public:
        AppManager();
        AppManager(std::string lineSpeed, std::string lineLength, std::string epilepcy);
        int* ValidateInput(std::string lineSpeed, std::string lineLength, std::string epilepsy);
        int* ReadInputFromConsole();
        void GenerateLine();
        void SetUp();
        void Run();
        void ValidateDataLoop();
};