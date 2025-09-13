#include<iostream>
#include "app_manager.h"
#include "console_manager.h"
#include "colors.h"

int main(int argc, char* argv[]){
    if (argc == 3)
        AppManager manager = AppManager(argv[1], argv[2], argv[3]);

    ConsoleManager console_manager = ConsoleManager();
    console_manager.ClearScreen(); 
    console_manager.SetColor(BRIGHT_CYAN);
    std::cout << "Hello"; 
    console_manager.SetColor(WHITE);
    getchar();
    return 0;
}