// Arda Barak
// 300129340
// Exercise 2

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
#include <sstream>

class DataAnalysis {
private:
    std::vector<double> stockPrices;

public:
    void addPrice(double price) {stockPrices.push_back(price);}//adding stock prices

    std::vector<double> filterPrices(const std::function<bool(double)>& filterFunc) const { //filtering stock prices with lambda
        std::vector<double> filtered;
        for (double price : stockPrices) {
            if (filterFunc(price)) {
                filtered.push_back(price);
            }
        }
        return filtered;
    }

    class Average { //functor for average
    public:
        double operator()(const std::vector<double>& data) const {
            if (data.empty()) return 0.0;
            double sum = std::accumulate(data.begin(), data.end(), 0.0);
            return sum / data.size();
        }
    };

    class StandardDeviation { //functor for standard deviation
    public:
        double operator()(const std::vector<double>& data) const {
            if (data.size() < 2) return 0.0;
            Average avg;
            double mean = avg(data);
            double sqSum = std::accumulate(data.begin(), data.end(), 0.0,[mean](double acc, double x) { return acc + (x - mean) * (x - mean); });
            return std::sqrt(sqSum / (data.size() - 1));
        }
    };
    const std::vector<double>& getPrices() const {return stockPrices;}
};

int main() {
    DataAnalysis analysis;
    std::cout << "Enter stock prices separated by spaces: ";//input stock prices
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::istringstream stream(inputLine);

    double price;
    while (stream >> price) {analysis.addPrice(price);}
    auto filteredPrices = analysis.filterPrices([](double price) { return price > 100.0; });//filtering prices above 100
    std::cout << "Prices above 100:     ";//outputting filtered prices

    for (double p : filteredPrices) {std::cout << p << " ";}
    std::cout << "\n";
    DataAnalysis::Average avg;              //calculate average 
    DataAnalysis::StandardDeviation stdDev; //calc standard deviation
    double averagePrice = avg(analysis.getPrices());
    double standardDeviation = stdDev(analysis.getPrices());
    std::cout << "Average price:        " << averagePrice << "\n";
    std::cout << "Standard deviation of prices: " << standardDeviation << "\n";
    return 0;
}
