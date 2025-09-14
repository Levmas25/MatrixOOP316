#pragma once 
#include<string>

class MySymbol{
    private:
        static std::string charset;
        int _x;
        int _y;
        char _c;
    public:
        void PutSymbol();
        void DeleteSymbol();
        void SetPosition(int new_x, int new_y);
        int* GetPosition();
        int GetRow();
        int GetCol();
        void MoveForward(int next_row);
        MySymbol(int x, int y);
};