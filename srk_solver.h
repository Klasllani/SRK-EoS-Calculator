// srk_solver.h
#ifndef SRK_SOLVER_H
#define SRK_SOLVER_H

#include <cmath>
#include <vector>

class SRKSolver {
private:
    const double R = 0.08314; // Gas constant in L·bar/(mol·K)
    
    // Helper functions
    double calculateA(double T, double Tc, double Pc, double omega) const;
    double calculateB(double T, double Tc, double Pc) const;
    std::vector<double> solvePolynomial(double T, double P, double Tc, double Pc, double omega) const;
    
public:
    SRKSolver() = default;
    
    // Main calculation functions
    double calculatePressure(double T, double V, double Tc, double Pc, double omega) const;
    double calculateVolume(double T, double P, double Tc, double Pc, double omega) const;
    double calculateCompressibilityFactor(double T, double P, double Tc, double Pc, double omega) const;
};

#endif // SRK_SOLVER_H