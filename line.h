#include<vector>
#include "symbol.h"

class Line{
    private:
        int _length;
        int _row;   
        std::vector<MySymbol> _symbols;  
    
    public:
        void CrawlOut();
        void Move();
        void CrawlIn();
        Line(int length, int row);
};