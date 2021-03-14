/**
 * Program: PGandE.cpp
 * Written by: Timothy Diliberto
 * Takes starting meter readings for gas and electric then determines the
 *     price using a baseline for usage - below baseline is one price and
 *     usage above baseline is another.
 * Last modified: 3/9/2021
 */

#include <iostream>

const double GAS_BASE = 31.0,     // therms
             GAS_UNDER = 0.504,
             GAS_OVER = 0.824,
             ELEC_BASE = 238.7,   // kilowatt hours
             ELEC_UNDER = 0.094,
             ELEC_OVER = 0.133;

//Function prototypes
void calcCharges(double, double, double, double, double);

int main() {
    double startGas,
           endGas,
           startElec,
           endElec;

    std::cout << "Enter starting and ending readings for gas meter\n"
              << "Starting Gas: ";
    std::cin >> startGas;
    std::cout << "Ending Gas: ";
    std::cin >> endGas;
    calcCharges(startGas, endGas, GAS_BASE, GAS_UNDER, GAS_OVER);

    std::cout << "\nEnter starting and ending readings for electric meter\n"
              << "Starting Electric: ";
    std::cin >> startElec;
    std::cout << "Ending Electric: ";
    std::cin >> endElec;
    calcCharges(startElec, endElec, ELEC_BASE, ELEC_UNDER, ELEC_OVER);

    return 0;
}

void calcCharges(double start, double end, double base,
                 double underBase, double overBase) {
    double usage = end - start,
           cost;

    if (usage <= base) cost = usage * underBase;
    else cost = (base * underBase) + ((usage - base) * overBase);

    std::cout << "Total Charges: " << cost << '\n';
}
