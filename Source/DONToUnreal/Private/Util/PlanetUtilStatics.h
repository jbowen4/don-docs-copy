#pragma once

struct PlanetUtilStatics
{
	/**
	 * Calculate the diameter a sphere *appears* to have at a given distance.
	 * 
	 * Equation: 2*arcsin(2*r/dist)
	 * @param Radius The radius of the sphere
	 * @param Distance The distance from the observer to the sphere
	 */
	inline static double GetAngularDiameter_Sphere(const double Radius, const double Distance)
	{
		return 2*FMath::FastAsin(2 * Radius / Distance);
	}
};
