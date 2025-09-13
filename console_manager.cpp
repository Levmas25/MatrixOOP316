#include "console_manager.h"
#include "colors.h"
#include<iostream>

void ConsoleManager::ClearScreen(){
    std::cout << "\033[2J";
    this->GotoXY(1, 1);
}

void ConsoleManager::GotoXY(int col, int row){
    std::cout << "\033[" << row  << ';' << col << 'H';
}

void ConsoleManager::SetColor(int foreground=WHITE){
    std::cout << "\033[0;" << foreground << 'm';
}