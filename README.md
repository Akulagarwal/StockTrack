
# 📈 StockTrack - C++ Stock Portfolio Tracker

StockTrack is a command-line portfolio tracker built in modern C++ using REST API integration and JSON-based data storage. It allows users to manage a portfolio of stocks, track real-time prices using Alpha Vantage API, and view gains or losses.

---

## 🚀 Features

- Add stocks to your portfolio with buy price
- Fetch real-time stock prices via API (Alpha Vantage)
- Save/load portfolio in JSON format
- Display individual stock gains/losses
- Interactive CLI menu system

---

## 🛠️ Tech Stack & Libraries

- C++17
- [CPR](https://github.com/libcpr/cpr) — HTTP Client for REST API
- [nlohmann/json](https://github.com/nlohmann/json) — JSON parsing
- CMake — Build system
- vcpkg — C++ package manager

---

## 📦 Folder Structure

```
StockTrack/
├── CMakeLists.txt
├── include/
│   ├── api.h
│   └── portfolio.h
├── src/
│   ├── api.cpp
│   ├── portfolio.cpp
│   └── main.cpp
├── data/
│   └── portfolio.json
```

---

## 🧰 Prerequisites

- **CMake** (>= 3.10)
- **Visual Studio 2019+** or **g++** on Linux
- **Git**
- **vcpkg** (for installing libraries)

---

## ⚙️ Setup Guide

### 1. Clone the Repository

```bash
git clone https://github.com/yourname/StockTrack.git
cd StockTrack
```

### 2. Setup vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat       # Windows
# OR
./bootstrap-vcpkg.sh        # Linux/Mac

./vcpkg install cpr nlohmann-json
./vcpkg integrate install
```

> Replace paths in next step accordingly.

---

## 🔧 Build the Project

### On Windows using CMake (from Developer Command Prompt):

```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build .
```

### On Linux/Mac:

```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
make
```

---

## ▶️ Run the Project

```bash
# From build directory (Windows)
.\StockTrack.exe

# Or Linux
./StockTrack
```

---

## 🌐 API Used

This project uses the [Alpha Vantage](https://www.alphavantage.co/) API (free). Get your API key:

1. Sign up at: https://www.alphavantage.co/support/#api-key
2. Replace the API key in `src/api.cpp`:
```cpp
const std::string API_KEY = "your_key_here";
```

---

## 📂 Save/Load Portfolio

The portfolio data is saved in:
```
data/portfolio.json
```

You can edit this file manually or add stocks using the CLI.

---

## ✅ Example CLI Menu

```
--- StockTrack Portfolio Tracker ---
1. View Portfolio
2. Add Stock
3. Update Prices
4. Show Gains/Losses
5. Save Portfolio
6. Exit
```

---

## 🧑‍💻 Author

Developed by **Harsh Thakur**  
GitHub: [your-github-link]  
Project: For Resume + Real-Time API Project Showcase 💼

---

## 📜 License

This project is open source under the MIT License.
