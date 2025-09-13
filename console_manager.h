class ConsoleManager{
    public:
        static void GotoXY(int col, int row);
        static void ClearScreen();
        static void SetColor(int foreground);
        static int* GetConsoleSize();
};