#include "symbol.h"
#include "console_manager.h"
#include <iostream>
#include "random_engine.h"


std::string MySymbol::charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void MySymbol::PutSymbol(){
    ConsoleManager::GotoXY(this->_x, this->_y);
    putchar(this->c);

}

void MySymbol::DeleteSymbol(){
    ConsoleManager::GotoXY(this->_x, this->_y);
    putchar(' ');
}

void MySymbol::SetPosition(int new_x, int new_y){
    this->_x = new_x;
    this->_y = new_y; 
    this->PutSymbol();
}

void MySymbol::MoveForward(int next_row){
    DeleteSymbol();
    this->_x--;
    this->_y += next_row;
    PutSymbol();
}

MySymbol::MySymbol(int x, int y){
    this->_x = x;
    this->_y = y;

    int pos = RandomEngine::randInt(0, MySymbol::charset.size() - 1);
    this->c = MySymbol::charset[pos];

    this->PutSymbol();
}