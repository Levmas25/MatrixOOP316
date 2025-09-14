#pragma once

#include<vector>
#include "symbol.h"

class Line{
    private:
        int _length;
        int _row; 
        int _speed;
        // indicates whether we need to put a symbol on the next line
        // to create a zigzag
        int _nextLine;

        std::vector<MySymbol> _symbols;
        int* _headPosition;
        int* _tailPosition;
        
        void _CrawlOut();
        void _MoveToTheEnd();
        void _ShiftLeft(int curLength, int numberOfShifts);
        void _DeleteFromTail(int times);
        void _CrawlIn();

    public:
        void Move();
        Line(int length, int row, int speed);
};