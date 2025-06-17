
#include "portfolio.h"
#include "api.h"
#include <iostream>

void showMenu() {
    std::cout << "\n--- StockTrack Portfolio Tracker ---\n";
    std::cout << "1. View Portfolio\n";
    std::cout << "2. Add Stock\n";
    std::cout << "3. Update Prices\n";
    std::cout << "4. Show Gains/Losses\n";
    std::cout << "5. Save Portfolio\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    Portfolio portfolio;
    portfolio.loadFromFile("data/portfolio.json");

    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;
        std::string symbol;

        switch (choice) {
            case 1:
                portfolio.display();
                break;
            case 2:
                std::cout << "Enter stock symbol: ";
                std::cin >> symbol;
                portfolio.addStock(symbol);
                break;
            case 3:
                portfolio.updatePrices();
                break;
            case 4:
                portfolio.showGains();
                break;
            case 5:
                portfolio.saveToFile("data/portfolio.json");
                break;
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
