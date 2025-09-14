#include<vector>
#include "symbol.h"

class Line{
    private:
        int _length;
        int _row; 
        // indicates whether we need to put a symbol on the next line
        // to create a zigzag
        int _nextLine;
        std::vector<MySymbol> _symbols;  
    
    public:
        void CrawlOut();
        void MoveToTheEnd();
        void ShiftLeft(int initialPosition, int curLength, int numberOfShifts);
        void CrawlIn();
        Line(int length, int row);
};