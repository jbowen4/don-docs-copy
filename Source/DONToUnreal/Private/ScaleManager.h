#pragma once
#include <iostream>
#include <cmath>

// Class for calculating how objects should be scaled and positioned relative to a camera in 3D space
class ScaleManager
{
private:

    //declairing the Max Distance From Origin
    static constexpr double MAX_DISTANCE = 88000000;  //alt num: 999999999999999.0;   //source4altnum: https://www.reddit.com/r/unrealengine/comments/1axhmhm/is_the_88_million_km_max_world_size_total_area_or/
    //  if the object is being rendered in corners of a squarely defined space and is
    //  not showing up as a full circle, attempt to fix this by adjusting this number,
    //  but it should be based off the idea the boarder is spherical with the maximum 
    //  radius being the maximum coordinate in any x-y-z direction. 

    //declairing private class variables
    double orbTrueDiameter;
    double orbTruePosition[3];
    double cameraTruePosition[3];
    bool debug;

public:

    //declairing public class variables
    double orbRenderedDiameter;
    double orbRenderedPositionSpherical[3];
    double orbRenderedPositionUE[3];

    // Constructor
    ScaleManager(double trueSize, double orbxpos, double orbypos, double orbzpos,
        double camxpos, double camypos, double camzpos);

    // Updates the true position and camera location, and recalculates rendering info
    int update(double neworbxpos, double neworbypos, double neworbzpos,
        double newcamxpos, double newcamypos, double newcamzpos);

private:
    // Performs the actual math to determine rendered diameter and position
    int calculateRenderedPositionAndDiameter();
};