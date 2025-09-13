#include <random>

class RandomEngine{
    private:
        static std::mt19937 gen;
    
    public:
        void Init(){
            // creates random device
            static std::random_device rd;
            gen.seed(rd());
        }

        static int randInt(int a, int b){
            std::uniform_int_distribution<> dist(a, b);
            // uses generated seed rd with Mersenne Twister algorithm to generate preudo random number
            return dist(gen);
        }
};