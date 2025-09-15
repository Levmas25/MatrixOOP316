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

        static const std::string _invalidLineSpeedErrorMsg;
        static const std::string _invalidLineLengthErrorMsg;
        static const std::string _invalidEpilepcyErrorMsg;

        static const std::string _lineSpeedInputMsg;
        static const std::string _lineLengthInputMsg;
        static const std::string _epilepcyModeInputMsg;

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