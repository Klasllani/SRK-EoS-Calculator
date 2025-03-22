// chemicals.h
#ifndef CHEMICALS_H
#define CHEMICALS_H

#include <string>
#include <map>
#include <vector>

struct ChemicalProperties {
    double Tc;     // Critical temperature (K)
    double Pc;     // Critical pressure (bar)
    double omega;  // Acentric factor
};

class Chemicals {
private:
    std::map<std::string, ChemicalProperties> chemicalDB;
    
public:
    Chemicals();
    
    bool isValidChemical(const std::string& name) const;
    double getTc(const std::string& name) const;
    double getPc(const std::string& name) const;
    double getOmega(const std::string& name) const;
    std::vector<std::string> getChemicalNames() const;
};

#endif // CHEMICALS_H