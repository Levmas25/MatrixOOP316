#include<iostream>
#include <sys/ioctl.h>
#include "app_manager.h"
#include "console_manager.h"
#include "colors.h"
#include "symbol.h"
#include "line.h"
#include "random_engine.h"

int main(int argc, char* argv[]){
    if (argc == 3)
        AppManager manager = AppManager(argv[1], argv[2], argv[3]);

    ConsoleManager console_manager = ConsoleManager();
    console_manager.ClearScreen(); 
    console_manager.SetColor(BRIGHT_CYAN);
    RandomEngine::Init();

    std::cout << std::unitbuf;
    
    int length;
    int row;

    std::cin >> length;
    std::cin >> row;

    Line line = Line(length, row);
    line.CrawlOut();
    line.MoveToTheEnd();
    line.CrawlIn();

    std::cout << '\n';
    getchar();
    console_manager.SetColor(WHITE);

    return 0;
}