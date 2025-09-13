#pragma once 
#include<string>

class MySymbol{
    private:
        static std::string charset;
        int _x;
        int _y;
    public:
        char c;
        void PutSymbol();
        void DeleteSymbol();
        void SetPosition(int new_x, int new_y);
        int* GetPosition();
        void MoveForward(int next_row);
        MySymbol(int x, int y);
};