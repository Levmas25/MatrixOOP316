#include "line.h"
#include "colors.h"
#include "console_manager.h"

#include<iostream>
#include<unistd.h>


void Line::_CrawlOut(){
    int* console_size = ConsoleManager::GetConsoleSize();
    int cols = console_size[1];

    int baseCol = cols;

    int curLength = 0;
    
    MySymbol head = MySymbol(baseCol, _row);
    _headPosition = head.GetPosition();
    _ShiftLeft(1, _length);
}

void Line::_ShiftLeft(int curLength, int numberOfShifts){
    for (int shiftNumber = 0; shiftNumber < numberOfShifts; shiftNumber++){

        if (_headPosition[1] == _row) _nextLine = 1;
        else _nextLine = -1;

        MySymbol new_head = MySymbol(_headPosition[0] - 1, _headPosition[1] + _nextLine);
        _headPosition = new_head.GetPosition();

        usleep(1000000 / _speed);

        if (curLength == _length)
            _DeleteFromTail(1);
        else{
            _tailPosition = ConsoleManager::GetConsoleSize();
            _tailPosition[0] = _row;
        }
            
    }
}

void Line::_DeleteFromTail(int times){
    for (int i = 0; i < times; i++){
        ConsoleManager::DestroySymbol(_tailPosition[1], _tailPosition[0]);
            if (_tailPosition[0] != _row)
                _tailPosition[0] = _row;
            else
                _tailPosition[0] = _row + 1;
        
        _tailPosition[1] -= 1;
        usleep(1000000 / _speed);
        
    }
}

void Line::_MoveToTheEnd(){
    int numberOfShifts = _headPosition[0] - 1;
    _ShiftLeft(_length, numberOfShifts);
}

void Line::_CrawlIn(){
    _DeleteFromTail(_length);
}

void Line::Move(){
    _CrawlOut();
    _MoveToTheEnd();
    _CrawlIn();
}

Line::Line(int length, int row, int speed){
    _length = length;
    _row = row;
    _speed = speed;
    _nextLine = 0;
}