
#include "api.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>

const std::string API_KEY = "demo"; // Replace with your Alpha Vantage API key

double fetchCurrentPrice(const std::string& symbol) {
    std::string url = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + symbol + "&apikey=" + API_KEY;
    auto response = cpr::Get(cpr::Url{url});
    auto json = nlohmann::json::parse(response.text);
    try {
        return std::stod(json["Global Quote"]["05. price"].get<std::string>());
    } catch (...) {
        std::cerr << "Error fetching price for " << symbol << "\n";
        return 0.0;
    }
}
