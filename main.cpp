#include<iostream>
#include <string>

#include "app_manager.h"
#include "console_manager.h"
#include "colors.h"
#include "symbol.h"
#include "line.h"
#include "random_engine.h"

int main(int argc, char* argv[]){

    if (argc == 2 and (std::string(argv[1]) == "-h" or std::string(argv[1]) == "--help")){
        AppManager::DisplayHelpText();
        return 0;
    }

    AppManager manager = (argc == 4)
    ? AppManager(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]))
    : AppManager();
    
    manager.Run();

    return 0;
}