// main.cpp
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "chemicals.h"
#include "srk_solver.h"

void displayMenu();
void displayChemicalList();

int main() {
    Chemicals chemDB;
    SRKSolver solver;
    
    std::string chemName;
    int option;
    double T, P, V, z;
    
    std::cout << "SRK Equation of State Calculator\n";
    std::cout << "================================\n\n";
    
    bool running = true;
    while (running) {
        displayMenu();
        std::cin >> option;
        
        switch (option) {
            case 1: // List chemicals
                displayChemicalList();
                break;
                
            case 2: // Select chemical
                std::cout << "Enter chemical name: ";
                std::cin >> chemName;
                if (chemDB.isValidChemical(chemName)) {
                    std::cout << "Selected: " << chemName << "\n";
                    std::cout << "Critical Temperature: " << chemDB.getTc(chemName) << " K\n";
                    std::cout << "Critical Pressure: " << chemDB.getPc(chemName) << " bar\n";
                    std::cout << "Acentric factor: " << chemDB.getOmega(chemName) << "\n";
                } else {
                    std::cout << "Chemical not found in database.\n";
                }
                break;
                
            case 3: // Calculate pressure
                std::cout << "Enter chemical name: ";
                std::cin >> chemName;
                if (!chemDB.isValidChemical(chemName)) {
                    std::cout << "Chemical not found in database.\n";
                    break;
                }
                
                std::cout << "Enter temperature (K): ";
                std::cin >> T;
                std::cout << "Enter molar volume (L/mol): ";
                std::cin >> V;
                
                P = solver.calculatePressure(T, V, 
                      chemDB.getTc(chemName), 
                      chemDB.getPc(chemName), 
                      chemDB.getOmega(chemName));
                
                std::cout << "Calculated pressure: " << P << " bar\n";
                break;
                
            case 4: // Calculate volume
                std::cout << "Enter chemical name: ";
                std::cin >> chemName;
                if (!chemDB.isValidChemical(chemName)) {
                    std::cout << "Chemical not found in database.\n";
                    break;
                }
                
                std::cout << "Enter temperature (K): ";
                std::cin >> T;
                std::cout << "Enter pressure (bar): ";
                std::cin >> P;
                
                V = solver.calculateVolume(T, P, 
                      chemDB.getTc(chemName), 
                      chemDB.getPc(chemName), 
                      chemDB.getOmega(chemName));
                
                std::cout << "Calculated molar volume: " << V << " L/mol\n";
                break;
                
            case 5: // Calculate compressibility factor
                std::cout << "Enter chemical name: ";
                std::cin >> chemName;
                if (!chemDB.isValidChemical(chemName)) {
                    std::cout << "Chemical not found in database.\n";
                    break;
                }
                
                std::cout << "Enter temperature (K): ";
                std::cin >> T;
                std::cout << "Enter pressure (bar): ";
                std::cin >> P;
                
                z = solver.calculateCompressibilityFactor(T, P, 
                      chemDB.getTc(chemName), 
                      chemDB.getPc(chemName), 
                      chemDB.getOmega(chemName));
                
                std::cout << "Calculated compressibility factor (Z): " << z << "\n";
                break;
                
            case 6: // Exit
                running = false;
                break;
                
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
        
        std::cout << "\n";
    }
    
    std::cout << "Thank you for using the SRK Equation of State Calculator!\n";
    return 0;
}

void displayMenu() {
    std::cout << "Options:\n";
    std::cout << "1. List available chemicals\n";
    std::cout << "2. Select chemical and view properties\n";
    std::cout << "3. Calculate pressure (given T and V)\n";
    std::cout << "4. Calculate volume (given T and P)\n";
    std::cout << "5. Calculate compressibility factor (given T and P)\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter option: ";
}

void displayChemicalList() {
    std::cout << "Available chemicals:\n";
    std::cout << "-------------------\n";
    std::cout << "Methane, Ethane, Propane, Butane, Pentane\n";
    std::cout << "Hexane, Heptane, Octane, Nonane, Decane\n";
    std::cout << "Ethylene, Propylene, Benzene, Toluene, Xylene\n";
    std::cout << "Nitrogen, Oxygen, CarbonDioxide, CarbonMonoxide, Hydrogen\n";
    std::cout << "Water, Ammonia, HydrogenSulfide, Methanol, Ethanol\n";
    std::cout << "Acetone, Chloroform, Refrigerant134a, Argon, Helium\n";
}