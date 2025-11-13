#include "ScaleManager.h"


// Constructor
ScaleManager::ScaleManager(double trueSize, double orbxpos, double orbypos, double orbzpos,
    double camxpos, double camypos, double camzpos)
    : orbTrueDiameter(trueSize),
    orbTruePosition{ orbxpos, orbypos, orbzpos },
    cameraTruePosition{ camxpos, camypos, camzpos }
{
    debug = false; //change this to true to see some debug statements
    //calculate calculated values
    calculateRenderedPositionAndDiameter();
}

// Updates the true position and camera location, and recalculates rendering info
//INPUT: new orb position, new camera position
//OUTPUT: int output of calculateRenderedPositionAndDiameter()
int ScaleManager::update(double neworbxpos, double neworbypos, double neworbzpos,
    double newcamxpos, double newcamypos, double newcamzpos)
{
    //setting new true location of the orb to render
    orbTruePosition[0] = neworbxpos;
    orbTruePosition[1] = neworbypos;
    orbTruePosition[2] = neworbzpos;

    //setting the position of the camera a.k.a. the player view
    cameraTruePosition[0] = newcamxpos;
    cameraTruePosition[1] = newcamypos;
    cameraTruePosition[2] = newcamzpos;

    //returning indicator for how calculating position and diam. went
    return calculateRenderedPositionAndDiameter();
}

/* calculateRenderedPositionAndDiameter
* INPUT: n/a
* OUTPUT: error code (int) (0 if the orb should be billboarded, 1 if it is
*         within renderable space, and 2 if the camera is inside the orb)
*
*   This function calculates the position to render the orb at is calculated using
* basic right triangle trig and a little bit of 3D vector math to translate it to
* the correct coordinates. Imagine the triangle below is the one we are working with:
*
*                                    R
*                          t .    :  |
*                  .  r :  |         |
*        .    :       |    |         |
*       P-------------c----b---------C
*
*   P = Player/Camera Position
*   C = True Location of the Center of the Orb
*   c = Rendered Location of the Center of the Orb
*   R = Top 'Surface' of the Orb as Implied by Given Diameter
*   r = Top 'Surface' of the Orb as Implied by Calculated Diameter
*   b = Boarder of Rendered Space
*   t = Where the Top Surface of the Orb Would be if Rendered at the Boarder
*
*   This function calculates length PC (given position of P and C) to calculate angle
* RPC (given PC, and CR), which is then used to calculate length of bt (given Pb and
* angle RPC.) Since we cannot render the whole orb at the boarder of renderable space
* we calculate the position of c being the length bt away from the boarder (3D vector
* math), which is the position that becomes the orbRenderedPosition.) Then finally we
* calculate what the rendered radius, cr, at that position should be, which when
* doubled becomes the orbRenderedDiameter.
*                                   //TODO: verify this is correct given UE's coord. sys.
*             Z                   P = Player/Camera Position
*             |     C             p = Tip of the projection of vector PC onto the XY-plane
*             |    /:             C = True Location of the Center of the Orb
*             |   / :             c = Rendered Location of the Center of the Orb
*             |  c  :             X = X-axis
*             | /   :             Y = Y-axis
*             |/    :             Z = Z-axis
*             P_____:________Y
*            / \    :               Then, after that, we calculate the position of the
*           /   \   :           rendered planets center in spherical coordinates centered
*          /     \  :           at P's position. To do this we calculate angle cPZ (given
*         /       \ :           the X-components and Y-components of P and C) and angle
*        /         \:           pPX (given Z-components of P and C, and the length PC.)
*       X           p           Lastly, we calculate the distance Pc using the ratio
*                               between the radii cr and CR from the previous diagram and
* multiplying that quotient by the length of PC. These three numbers are the alpha, beta
* and Z positional values of orbRenderedPosition.
*
* Please note that the steps above are done out of order below but the comments will note
* what in the diagrams they are calculating
*/

int ScaleManager::calculateRenderedPositionAndDiameter() //TODO: optimize this for accuracy given how remainders are handled in code
{
    int r;

    double dx = orbTruePosition[0] - cameraTruePosition[0];
    double dy = orbTruePosition[1] - cameraTruePosition[1];
    double dz = orbTruePosition[2] - cameraTruePosition[2];

    double distanceBetweenOriginAndCenterOfOrb = sqrt(dx * dx + dy * dy + dz * dz);

    if (debug) std::cout << "distance: " << distanceBetweenOriginAndCenterOfOrb << std::endl;

    if (distanceBetweenOriginAndCenterOfOrb < orbTrueDiameter) 
    {
        if (debug) std::cout << "2! " << distanceBetweenOriginAndCenterOfOrb << std::endl;
        return 2;
    }

    //calculating the (acute) angle of the right triangle (RPC in diagram)
    double triangle_angle_radians = atan((orbTrueDiameter / 2) / distanceBetweenOriginAndCenterOfOrb);




    //The below if statement helps figure out if the orb actually needs to be billboarded or not

    //declaring distance component of spherical coords.
    double z_length;

    if (distanceBetweenOriginAndCenterOfOrb > (MAX_DISTANCE - orbTrueDiameter))
    {
        //calculating approximate radius (bt in diagram)
        double roughRadius = tan(triangle_angle_radians) * MAX_DISTANCE;

        if (debug) std::cout << "rr! " << roughRadius << std::endl;

        //calculating orbRenderedDiameter (2 * cr in diagram)
        orbRenderedDiameter = (tan(triangle_angle_radians) * (MAX_DISTANCE - roughRadius)) * 2;

        //calculating the z length in spherical coordinates (Pc in diagram)
        z_length = distanceBetweenOriginAndCenterOfOrb * (orbRenderedDiameter / orbTrueDiameter);

        r = 0;

        if (debug) std::cout << "0! " << distanceBetweenOriginAndCenterOfOrb << std::endl;

    }
    else //aka this object doesn't need to be 'billboarded'
    {
        //setting rendered diam. to true diam.
        orbRenderedDiameter = orbTrueDiameter;

        //setting distance component to distance between camera and orb
        z_length = distanceBetweenOriginAndCenterOfOrb;

        r = 1;

        if (debug) std::cout << "1! " << distanceBetweenOriginAndCenterOfOrb << std::endl;
    }



    //calculating the alpha angle in spherical coordinates (cPZ in diagram)
    double alpha_angle_radians = atan2(dx, dy); //TODO: assure this is correct with unreal engine coords

    //calculating the beta angle in spherical coordinates (pPX in diagram)
    double ratio = dz / distanceBetweenOriginAndCenterOfOrb;
    if (ratio > 1.0) ratio = 1.0;
    if (ratio < -1.0) ratio = -1.0;
    double beta_angle_radians = acos(ratio);



    //assigning value to class variable and converting from radians to degrees
    //in form (radius, pitch, yaw)
    orbRenderedPositionSpherical[0] = z_length;                              //radius
    orbRenderedPositionSpherical[1] = alpha_angle_radians * (180 / PI);    //pitch
    orbRenderedPositionSpherical[2] = beta_angle_radians * (180 / PI);     //yaw

    //converting spherical to Unreal coord system (Left-Handed (X, Y, Z))
    orbRenderedPositionUE[0] = orbRenderedPositionSpherical[0] * (std::sin(beta_angle_radians)) * (std::cos(alpha_angle_radians));
    orbRenderedPositionUE[0] = orbRenderedPositionSpherical[0] * (std::sin(beta_angle_radians)) * (std::sin(alpha_angle_radians));
    orbRenderedPositionUE[0] = orbRenderedPositionSpherical[0] * (std::cos(beta_angle_radians));


    return r;
}