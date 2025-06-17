#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include <unordered_map>

struct Stock {
    std::string symbol;
    double buyPrice;
    double currentPrice;
};

class Portfolio {
private:
    std::unordered_map<std::string, Stock> stocks;
public:
    void addStock(const std::string& symbol);
    void updatePrices();
    void display() const;
    void showGains() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
