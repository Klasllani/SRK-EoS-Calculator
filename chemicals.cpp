// chemicals.cpp
#include "chemicals.h"

Chemicals::Chemicals() {
    // Initialize the chemical database with 30 common chemicals
    // Data source: Various thermodynamic databases
    // Values: Tc (K), Pc (bar), omega (acentric factor)
    
    chemicalDB["Methane"] = {190.6, 46.0, 0.011};
    chemicalDB["Ethane"] = {305.4, 48.8, 0.099};
    chemicalDB["Propane"] = {369.8, 42.5, 0.152};
    chemicalDB["Butane"] = {425.2, 38.0, 0.199};
    chemicalDB["Pentane"] = {469.7, 33.7, 0.251};
    chemicalDB["Hexane"] = {507.5, 30.1, 0.299};
    chemicalDB["Heptane"] = {540.3, 27.4, 0.349};
    chemicalDB["Octane"] = {568.8, 24.9, 0.399};
    chemicalDB["Nonane"] = {594.6, 22.9, 0.445};
    chemicalDB["Decane"] = {617.7, 21.1, 0.490};
    chemicalDB["Ethylene"] = {282.4, 50.4, 0.087};
    chemicalDB["Propylene"] = {365.6, 46.2, 0.146};
    chemicalDB["Benzene"] = {562.1, 48.9, 0.210};
    chemicalDB["Toluene"] = {591.8, 41.0, 0.263};
    chemicalDB["Xylene"] = {617.1, 35.0, 0.310};
    chemicalDB["Nitrogen"] = {126.2, 33.9, 0.039};
    chemicalDB["Oxygen"] = {154.6, 50.4, 0.022};
    chemicalDB["CarbonDioxide"] = {304.2, 73.8, 0.228};
    chemicalDB["CarbonMonoxide"] = {132.9, 35.0, 0.066};
    chemicalDB["Hydrogen"] = {33.2, 13.0, -0.216};
    chemicalDB["Water"] = {647.1, 220.6, 0.344};
    chemicalDB["Ammonia"] = {405.7, 113.5, 0.253};
    chemicalDB["HydrogenSulfide"] = {373.5, 90.0, 0.094};
    chemicalDB["Methanol"] = {512.6, 80.9, 0.559};
    chemicalDB["Ethanol"] = {514.0, 61.4, 0.644};
    chemicalDB["Acetone"] = {508.1, 47.0, 0.307};
    chemicalDB["Chloroform"] = {536.4, 54.0, 0.218};
    chemicalDB["Refrigerant134a"] = {374.2, 40.6, 0.327};
    chemicalDB["Argon"] = {150.8, 48.7, 0.000};
    chemicalDB["Helium"] = {5.2, 2.3, -0.390};
}

bool Chemicals::isValidChemical(const std::string& name) const {
    return chemicalDB.find(name) != chemicalDB.end();
}

double Chemicals::getTc(const std::string& name) const {
    auto it = chemicalDB.find(name);
    if (it != chemicalDB.end()) {
        return it->second.Tc;
    }
    return 0.0; // Return 0 if not found
}

double Chemicals::getPc(const std::string& name) const {
    auto it = chemicalDB.find(name);
    if (it != chemicalDB.end()) {
        return it->second.Pc;
    }
    return 0.0; // Return 0 if not found
}

double Chemicals::getOmega(const std::string& name) const {
    auto it = chemicalDB.find(name);
    if (it != chemicalDB.end()) {
        return it->second.omega;
    }
    return 0.0; // Return 0 if not found
}

std::vector<std::string> Chemicals::getChemicalNames() const {
    std::vector<std::string> names;
    for (const auto& pair : chemicalDB) {
        names.push_back(pair.first);
    }
    return names;
}