#include <iostream>
#include "ScaleManager.h"

int main() {
    //test input
    ScaleManager sm(5.0, 0.0, 0.0, 1.0e15, 0.0, 0.0, 0.0);

    //outputting results
    std::cout << "Rendered diameter: " << sm.orbRenderedDiameter << std::endl;
    std::cout << "Rendered position (spherical): "
        << sm.orbRenderedPositionSpherical[0] << ", "
        << sm.orbRenderedPositionSpherical[1] << ", "
        << sm.orbRenderedPositionSpherical[2] << std::endl;
    std::cout << "Rendered position (UE): "
        << sm.orbRenderedPositionUE[0] << ", "
        << sm.orbRenderedPositionUE[1] << ", "
        << sm.orbRenderedPositionUE[2] << std::endl;
    return 0;
}