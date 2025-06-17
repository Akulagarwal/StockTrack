
cmake_minimum_required(VERSION 3.10)
project(StockTrack)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json REQUIRED)
find_package(cpr REQUIRED)

include_directories(include)

add_executable(StockTrack 
    src/main.cpp
    src/portfolio.cpp
    src/api.cpp
)

target_link_libraries(StockTrack PRIVATE nlohmann_json::nlohmann_json cpr::cpr)

