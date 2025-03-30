# SRK Equation of State Calculator

The Soave-Redlich-Kwong (SRK) equation of state is a thermodynamic model used to predict the behavior of gases and liquids. This program has an interactive command-line interface and handles phase transitions using cubic equation solving. Users can input any two parameters such as temperature (K), pressure (bar), or molar volume (L/mol) to calculate an unknown third parameter. This helps engineers and scientists understand how substances behave under specific conditions in chemical processes.

## Prerequisites
- C++ compiler (g++, clang++)
- Build automation tools (make) - optional but recommended

<br>

## Running Instructions

### 1. Navigate to the project directory
```sh
cd [project-directory]
   ```

### 2. Verify all files are present
```sh
ls -la
   ```
You should see: main.cpp, chemicals.cpp, chemicals.h, srk_solver.cpp, srk_solver.h, and Makefile

### 3. Install required build tools (if not already installed)
```sh
sudo apt update
sudo apt install build-essential
   ```
### 4. Compiling the program
```sh
g++ -std=c++11 -Wall -Wextra main.cpp chemicals.cpp srk_solver.cpp -o srk_calculator
   ```
Alternatively, with the Makefile:
```sh
make
   ```
### 5. Running the program
```sh
./srk_calculator
   ```
