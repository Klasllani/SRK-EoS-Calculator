// srk_solver.cpp
#include "srk_solver.h"
#include <iostream>
#include <algorithm>

double SRKSolver::calculateA(double T, double Tc, double Pc, double omega) const {
    double Tr = T / Tc;
    double alpha = pow(1 + (0.48 + 1.574 * omega - 0.176 * omega * omega) * (1 - sqrt(Tr)), 2);
    return 0.42748 * alpha * pow(R * Tc, 2) / Pc;
}

double SRKSolver::calculateB(double T, double Tc, double Pc) const {
    return 0.08664 * R * Tc / Pc;
}

double SRKSolver::calculatePressure(double T, double V, double Tc, double Pc, double omega) const {
    double a = calculateA(T, Tc, Pc, omega);
    double b = calculateB(T, Tc, Pc);
    
    // SRK equation: P = RT/(V-b) - a/[V(V+b)]
    double P = R * T / (V - b) - a / (V * (V + b));
    return P;
}

std::vector<double> SRKSolver::solvePolynomial(double T, double P, double Tc, double Pc, double omega) const {
    double a = calculateA(T, Tc, Pc, omega);
    double b = calculateB(T, Tc, Pc);
    
    // Cubic equation coefficients in standard form: Z³ + pZ² + qZ + r = 0
    double p = -1.0;
    double q = a/(b*R*T) - b*P/(R*T) - 1;
    double r = -a*P/(b*R*T*R*T);
    
    // Convert to depressed cubic t³ + pt + q = 0 using Z = t - p/3
    double p_depressed = q - p*p/3;
    double q_depressed = r - p*q/3 + 2*p*p*p/27;
    
    // Calculate discriminant
    double discriminant = 4*p_depressed*p_depressed*p_depressed/27 + q_depressed*q_depressed;
    
    std::vector<double> roots;
    
    // For simplicity, we'll implement a basic method
    // In a production environment, a more robust cubic equation solver should be used
    
    if (discriminant < 0) {
        // Three real roots - using trigonometric method
        double phi = acos(-q_depressed/2 * sqrt(-27/(p_depressed*p_depressed*p_depressed)));
        double t1 = 2 * sqrt(-p_depressed/3) * cos(phi/3);
        double t2 = 2 * sqrt(-p_depressed/3) * cos((phi + 2*M_PI)/3);
        double t3 = 2 * sqrt(-p_depressed/3) * cos((phi + 4*M_PI)/3);
        
        roots.push_back(t1 - p/3);
        roots.push_back(t2 - p/3);
        roots.push_back(t3 - p/3);
    } else {
        // One real root and two complex conjugate roots
        // We'll only calculate the real root
        double u = cbrt(-q_depressed/2 + sqrt(discriminant)/2);
        double v = -p_depressed/(3*u);
        double t = u + v;
        
        roots.push_back(t - p/3);
    }
    
    // Filter out non-physical roots (Z < 0 or too small)
    std::vector<double> valid_roots;
    for (double root : roots) {
        if (root > 0.01) { // Small threshold to avoid numerical issues
            valid_roots.push_back(root);
        }
    }
    
    return valid_roots;
}

double SRKSolver::calculateVolume(double T, double P, double Tc, double Pc, double omega) const {
    // Solve for compressibility factor Z first
    auto z_values = solvePolynomial(T, P, Tc, Pc, omega);
    
    if (z_values.empty()) {
        std::cerr << "Error: No valid compressibility factor found.\n";
        return 0.0;
    }
    
    // If multiple real roots, the largest one represents vapor phase, smallest represents liquid
    double z;
    if (z_values.size() > 1) {
        // Sort in ascending order
        std::sort(z_values.begin(), z_values.end());
        
        // For simplicity, return the largest root (vapor phase)
        // In a more complete implementation, phase stability would be checked
        z = z_values.back();
    } else {
        z = z_values[0];
    }
    
    // Convert Z to molar volume: V = ZRT/P
    return z * R * T / P;
}

double SRKSolver::calculateCompressibilityFactor(double T, double P, double Tc, double Pc, double omega) const {
    auto z_values = solvePolynomial(T, P, Tc, Pc, omega);
    
    if (z_values.empty()) {
        std::cerr << "Error: No valid compressibility factor found.\n";
        return 0.0;
    }
    
    // If multiple real roots exist, select the appropriate one
    if (z_values.size() > 1) {
        // Sort in ascending order
        std::sort(z_values.begin(), z_values.end());
        
        // For simplicity, return the largest root (vapor phase)
        // A more complete implementation would check phase stability
        return z_values.back();
    }
    
    return z_values[0];
}