#include "iostream"

class Mpg_log
{
    private:
        double last_odometer;
        double this_odometer;
        double this_gas;
    public:
        void Mpg_Log(double starting_odometer)
        {
            this_odometer = starting_odometer;
        }
        void buy_gas(double odometer, double gas)
        {
            last_odometer = this_odometer;
            this_odometer = odometer;
            this_gas = gas;
        }
        double get_current_mpg()
        {
            double mpg;
            mpg = (this_odometer - last_odometer)/this_gas;
            return mpg;
        };
};

int main()
{
    Mpg_log car;
    double starting_odometer;
    double odometer, gas;
    char continue_;
    std::cout << "What is the initial odometer reading?\n";
    std::cin >> starting_odometer;
    car.Mpg_Log(starting_odometer);
    
    while (true)
    {
        std::cout << "What is the next odometer reading?\n";
        std::cin >> odometer;
        std::cout << "What are the associated gallons purchased?\n";
        std::cin >> gas;
        car.buy_gas(odometer,gas);
        std::cout << car.get_current_mpg() << " MPG\n";
        std::cout << "continue? [Y/N]";
        std::cin >> continue_;
        if (continue_ == 'n' || continue_ == 'N')
            break;
    }
    
}
