#include "line.h"
#include "colors.h"
#include "console_manager.h"

#include<iostream>
#include<unistd.h>


void Line::CrawlOut(){
    int* console_size = ConsoleManager::GetConsoleSize();
    int rows = console_size[0];
    int cols = console_size[1];

    int base_row = this->_row;
    int base_col = cols - 1;

    int cur_length = 0;
    // indicatesn whether we need to put a symbol on the next line
    // to create a zigzag
    int next_line = 0;
    while (cur_length < this->_length)
    {
        for (int i = 0; i < cur_length; i++){
            this->_symbols[i].MoveForward(next_line);
            next_line = (next_line + 1) % 2;
            usleep(100000);
        }
        this->_symbols.push_back(MySymbol(base_col, base_row));
        cur_length++;
    }
}


Line::Line(int length, int row){
    this->_length = length;
    this->_row = row;
}