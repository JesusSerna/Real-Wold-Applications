#include "iostream"
#include "list"

class Mpg_log
{
private:
    double last_odometer;
    double this_odometer;
    double this_gas;
    double first_odometer;
    double total_gas;
    std::list<double> gas_sum;
    std::list<double> odometer_difference;
public:
    void Mpg_Log(double starting_odometer)
    {
        this_odometer = starting_odometer;
        first_odometer = starting_odometer;
    }
    void buy_gas(double odometer, double gas)
    {
        last_odometer = this_odometer;
        this_odometer = odometer;
        this_gas = gas;
        total_gas += gas;
    // Rolling average lists
        if (odometer_difference.size() >= 5)
        {
            odometer_difference.push_back(this_odometer - last_odometer);
            odometer_difference.pop_front();
            gas_sum.push_back(gas);
            gas_sum.pop_front();
        }
        else
        {
            odometer_difference.push_back(this_odometer - last_odometer);
            gas_sum.push_back(gas);
        }
    }
    double get_current_mpg()
    {
        return (this_odometer - last_odometer)/this_gas;
    };
    double get_total_mpg()
    {
        return (this_odometer - first_odometer) / total_gas;
    }
    //////needs work
    double get_rolling_mpg()
    {
        double sum_gas = 0;
        for(std::list<double>::iterator it = gas_sum.begin(); it != gas_sum.end(); ++it)
        {
            sum_gas += *it;
        }
        double sum_differences;
        for(std::list<double>::iterator it = odometer_difference.begin(); it != odometer_difference.end(); ++it)
        {
            sum_differences += *it;
        }
        
       return sum_differences/sum_gas;
    }
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
        std::cout << "This MPG: " << car.get_current_mpg() << " MPG\n";
        std::cout << "Total MPG: " << car.get_total_mpg() << " MPG\n";
        std::cout << "The rolling MPG: "<<car.get_rolling_mpg() << " MPG\n";
        std::cout << "continue? [Y/N]\n";
        std::cin >> continue_;
        if (continue_ == 'n' || continue_ == 'N')
            break;
    }
    
}
