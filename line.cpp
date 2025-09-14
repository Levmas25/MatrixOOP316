#include "line.h"
#include "colors.h"
#include "console_manager.h"

#include<iostream>
#include<unistd.h>


void Line::CrawlOut(){
    int* console_size = ConsoleManager::GetConsoleSize();
    int cols = console_size[1];

    int baseCol = cols;

    int curLength = 0;

    while (curLength < _length)
    {
        ShiftLeft(0, curLength, 1);
        _symbols.push_back(MySymbol(baseCol, _row));
        curLength++;
    }
}

void Line::ShiftLeft(int initialPosition, int curLength, int numberOfShifts){
    for (int shiftNumber = 0; shiftNumber < numberOfShifts; shiftNumber++){
        for (int i = initialPosition; i < curLength; i++){
            MySymbol& curSymb = _symbols[i];
            if (curSymb.GetRow() == _row)
            _nextLine = 1;
            else
            _nextLine = -1;
            curSymb.MoveForward(_nextLine);
        }
        usleep(100000);
    }
}

void Line::MoveToTheEnd(){
    int numberOfShifts = _symbols[0].GetCol() - 1;
    ShiftLeft(0, _length, numberOfShifts);
}

void Line::CrawlIn(){
    int initialPosition = 0;

    while (initialPosition < _length){
        MySymbol& head = _symbols[initialPosition];
        head.DeleteSymbol();
        initialPosition++;
        ShiftLeft(initialPosition, _length, 1);
    }
}


Line::Line(int length, int row){
    _length = length;
    _row = row;
    _nextLine = 0;
}