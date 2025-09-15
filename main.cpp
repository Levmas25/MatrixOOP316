#include<iostream>
#include <string>
#include <sys/ioctl.h>
#include "app_manager.h"
#include "console_manager.h"
#include "colors.h"
#include "symbol.h"
#include "line.h"
#include "random_engine.h"

int main(int argc, char* argv[]){

    AppManager manager = (argc == 4)
    ? AppManager(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]))
    : AppManager();
        
    manager.Run();

    std::cout << '\n';
    getchar();
    ConsoleManager::SetColor(WHITE);

    return 0;
}