#include "main.h"

#define DEBUG

int main(int argc, char* argv[]) {

    bool silent = false;
    bool plotsIn3D = false;
    int cores = (int) cpu_cnt;
    bool noX = false;

    validateInput(argc, argv, cpu_cnt, N, SIZE, J_START, J_END, J_COUNT, T_START, T_END, T_COUNT, silent, cores, plotsIn3D, true, J1, J2, noX);

/////////////////////////////// calculate quantities ///////////////////////////////
#ifndef DEBUG

    if(plotsIn3D) {
        // 3D Plots of specific heat dependent on T and J
        plot3D::start_C(J_COUNT, J_START, J_END, T_COUNT, T_START, T_END, cores, N, SIZE);
        // 3D Plots of susceptibility dependent on T and J
        if (!noX) {
            plot3D::start_X(J_COUNT, J_START, J_END, T_COUNT, T_START, T_END, cores, N, SIZE);
        }
    } else {
        // excitation energy \Delta E(J) and specific heat C(J), T = const
        multi::start_DeltaE_CT_const(J_COUNT, J_START, J_END, cores, T, N, SIZE);
        // susceptibility \Chi(J), T = const
        if (!noX) {
            multi::start_XT_const(J_COUNT, J_START, J_END, cores, T, N, SIZE);
        }

        // spin gap E_{gap} (J)
        multi::start_SpinGap(J_COUNT, J_START, J_END, cores, N, SIZE);

        // specific heat C(T), J = const
        if (N % 4 == 0) {
            spinInversion::startSpecificHeat(J1, J2, N, SIZE, T_START, T_END, T_COUNT);
        } else {
            momentumStates::startSpecificHeat(J1, J2, N, SIZE, T_START, T_END, T_COUNT);
        }

        // susceptibility \Chi(T), J = const
        if (!noX) {
            magnetizationBlocks::startSusceptibility(J1, J2, N, SIZE, T_START, T_END, T_COUNT);
        }
//    if (N % 4 == 0) {
//        spinInversion::startSusceptibility(J1, J2, N, SIZE, T_START, T_END, T_COUNT);
//    } else {
//        magnetizationBlocks::startSusceptibility(J1, J2, N, SIZE, T_START, T_END, T_COUNT);
//    }

        // dispersion with fixed J
        momentumStates::startDispersionPlot(J1, J2, N, SIZE);
    }

#endif
/////////////////////////////// testing ///////////////////////////////
#ifdef DEBUG

    multi::start_SpinGap_with_index(J_COUNT, J_START, J_END, cores, N, SIZE);
    //multi::start_SpinGap(J_COUNT, J_START, J_END, cores, N, SIZE);

    //N = 8; SIZE = (int) std::pow(2,N); T_START = 0; T_END = 20; T_COUNT = 50; J_START = 0; J_END = 2; J_COUNT = 50;
    //multi::start_DeltaE_CT_const(J_COUNT, J_START, J_END, cores, T, N, SIZE);

    // susceptibilities
//    magnetizationBlocks::startSusceptibility(J1, J2, N, SIZE, T_START, T_END, T_COUNT);
//    momentumStates::startSusceptibility(J1, J2, N, SIZE, T_START, T_END, T_COUNT);
//    spinInversion::startSusceptibility(J1, J2, N, SIZE, T_START, T_END, T_COUNT);

    // individual methods
//    spinInversion::start(J1, J2, N, SIZE);
//    parityStates::start(J1, J2, N, SIZE);
//    momentumStates::start(J1, J2, N, SIZE);
//    magnetizationBlocks::start(J1, J2, N, SIZE);


    // speed test
//    for (int n = 0; n <= 16; n += 1) {
//        int size = (int) std::pow(2, 12);
//        std::cout << "N: " << n << ", size: " << size << "\n";
//        magnetizationBlocks::startSusceptibility(1.0, 1.0, n, size, 0, 5, 50000);
//        momentumStates::startSusceptibility(1.0, 1.0, n, size, 0, 5, 50000);
////        spinInversion::start(J1, J2, 12, size);
////        parityStates::start(J1, J2, 12, size);
//        std::cout << "\n";
//    }
#endif

    std::cout << std::endl;

    return 0;
}
