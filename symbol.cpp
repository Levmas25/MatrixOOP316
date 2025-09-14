#include "symbol.h"
#include "console_manager.h"
#include <iostream>
#include "random_engine.h"


std::string MySymbol::charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void MySymbol::PutSymbol(){
    ConsoleManager::GotoXY(_x, _y);
    std::cout << _c;

}

void MySymbol::DeleteSymbol(){
    ConsoleManager::GotoXY(_x, _y);
    std::cout << ' ';
}

void MySymbol::SetPosition(int new_x, int new_y){
    DeleteSymbol();
    _x = new_x;
    _y = new_y; 
    PutSymbol();
}

void MySymbol::MoveForward(int next_row){
    DeleteSymbol();
    _x--;
    _y += next_row;
    PutSymbol();
}

int MySymbol::GetCol(){
    return _x;
}

int MySymbol::GetRow(){
    return _y;
}

MySymbol::MySymbol(int x, int y){
    _x = x;
    _y = y;

    int pos = RandomEngine::randInt(0, MySymbol::charset.size() - 1);
    _c = MySymbol::charset[pos];

    PutSymbol();
}