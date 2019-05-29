#include <iostream>
#include <sstream>
#include <fstream>
#include "list"
#include "string"

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
    std::string date, odometer, gas, cost;
    std::ifstream  data;
    std::ofstream data_output;
    data.open("Mileage_Log_for_Extreme_Bonus.csv");
    data_output.open("results.csv");
    
    //printing first line
    getline(data, date,',');
    getline(data, odometer,',');
    getline(data, gas,',');
    getline(data, cost,'\r');
    data_output << date << "," << odometer << "," << gas << "," << cost << ",This MPG,Total MPG,Rolling MPG" <<  "\n";
    
    
    //printing second line
    getline(data, date, ',');
    
    //grab first odometer reading
    getline(data, odometer, ',');
    //store first odometer reading
    car.Mpg_Log(stod(odometer));
    
    getline(data, gas,',');
    getline(data, cost, '\r');
    data_output << date << "," << odometer << "," << gas << "," << cost << "\n";
    
    //write every other line
    while(getline(data,date,','))
    {
        getline(data, odometer, ',');
        getline(data, gas, ',');
        getline(data, cost, '\r');
        car.buy_gas(stod(odometer),stod(gas));
        //write data onto "results" file
        data_output << date << "," << odometer << "," << gas << "," << cost << ",";
        data_output << car.get_current_mpg() << "," << car.get_total_mpg() << "," << car.get_rolling_mpg() << "\n";

    }
    data.close();
    data_output.close();
}
