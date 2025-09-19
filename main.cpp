#include<iostream>
#include <string>

#include "app_manager.h"

int main(int argc, char* argv[]){

    if (argc != 2 && argc != 4 && argc != 1){
        AppManager::DisplayInvaidArgumentCountMsg();
        return 0;
    }

    if (argc == 2 and (std::string(argv[1]) == "-h" or std::string(argv[1]) == "--help")){
        AppManager::DisplayHelpText();
        return 0;
    }
    else if (argc == 2){
        AppManager::DisplayInvaidArgumentCountMsg();
        return 0;
    }

    AppManager manager = (argc == 4)
    ? AppManager(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]))
    : AppManager();
    
    manager.Run();

    return 0;
}