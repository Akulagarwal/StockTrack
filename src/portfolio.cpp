
#include "portfolio.h"
#include "api.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

void Portfolio::addStock(const std::string& symbol) {
    double price;
    std::cout << "Enter buying price: ";
    std::cin >> price;
    stocks[symbol] = {symbol, price, price};
}

void Portfolio::updatePrices() {
    for (auto& [symbol, stock] : stocks) {
        stock.currentPrice = fetchCurrentPrice(symbol);
    }
    std::cout << "Prices updated.\n";
}

void Portfolio::display() const {
    for (const auto& [symbol, stock] : stocks) {
        std::cout << symbol << ": Buy = $" << stock.buyPrice
                  << ", Current = $" << stock.currentPrice << "\n";
    }
}

void Portfolio::showGains() const {
    for (const auto& [symbol, stock] : stocks) {
        double gain = stock.currentPrice - stock.buyPrice;
        std::cout << symbol << ": Gain/Loss = $" << gain << "\n";
    }
}

void Portfolio::saveToFile(const std::string& filename) const {
    nlohmann::json j;
    for (const auto& [symbol, stock] : stocks) {
        j[symbol] = {stock.buyPrice, stock.currentPrice};
    }
    std::ofstream file(filename);
    file << j.dump(4);
    file.close();
}

void Portfolio::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;
    nlohmann::json j;
    file >> j;
    for (auto& el : j.items()) {
        stocks[el.key()] = {el.key(), el.value()[0], el.value()[1]};
    }
    file.close();
}
