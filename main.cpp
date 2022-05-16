#include "main.h"

int main(int argc, char* argv[]) {

    bool silent = false;
    int cores = (int) cpu_cnt;

    validateInput(argc, argv, N, SIZE, J_START, J_END, J_COUNT, cpu_cnt, silent, cores, J1, J2, true);

    // syncing T and J ranges
    T_START = J_START;
    T_END = J_END;
    T_COUNT = J_COUNT;

/////////////////////////////// calculate quantities ///////////////////////////////

    multi::start_DeltaE_CT_const(J_COUNT, J_START, J_END, cpu_cnt, cores, T, N, SIZE);
    multi::start_XT_const(J_COUNT, J_START, J_END, cpu_cnt, cores, T, N, SIZE);

    momentumStates::startSpecificHeat(J1, J2, N, SIZE, T_START, T_END, T_COUNT, cores);
    magnetizationBlocks::startSusceptibility(J1, J2, N, SIZE, T_START, T_END, T_COUNT, cores);
    momentumStates::startDispersionPlot(J1, J2, N, SIZE);

//    spinInversion::start(J1, J2, N, SIZE);
//    parityStates::start(J1, J2, N, SIZE);
//    momentumStates::start(J1, J2, N, SIZE);
//    magnetizationBlocks::start(J1, J2, N, SIZE);


//    for (int n = 8; n <= 16; n += 4) {
//        int size = (int) std::pow(2, n);
//        std::cout << "N: " << n << ", size: " << size << "\n";
//        spinInversion::start(J1, J2, n, size);
//        parityStates::start(J1, J2, n, size);
////        momentumStates::start(J1, J2, n, size);
//        std::cout << "\n";
//    }


    std::cout << "\n";

    return 0;
}
