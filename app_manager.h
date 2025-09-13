class AppManager{
    private:
        int consoleHeight;
        int consoleWidth;
        int lineSpeed;
        int lineLength;
        bool epilepsy;

        const char* invalidLineSpeedErrorMsg = "Line speed must be integer in range [1;30]";
        const char* invalidLineLengthErrorMsg = "Line length must be integer in range [1;30]";
        const char* invalidEpilepcyErrorMsg = "Epilepsy must be y or n";

    public:
        AppManager();
        AppManager(char* lineSpeed, char* lineLength, char* epilepcy);
        int* ValidateInput(char* lineSpeed, char* lineLength, char* epilepsy);
};