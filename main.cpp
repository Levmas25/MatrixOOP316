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

    RandomEngine::Init();

    std::cout << std::unitbuf;
    
    char* length = new char[2];
    char* epilepsy = new char[1];
    char* speed = new char[2];

    std::cin >> length;
    std::cin >> epilepsy;
    std::cin >> speed;

    AppManager man = AppManager(speed, length, epilepsy);
    man.SetUp();

    std::cout << '\n';
    getchar();
    ConsoleManager::SetColor(WHITE);

    return 0;
}