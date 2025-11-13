

# Struct PlanetUtilStatics



[**ClassList**](annotated.md) **>** [**PlanetUtilStatics**](struct_planet_util_statics.md)












































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  double | [**GetAngularDiameter\_Sphere**](#function-getangulardiameter_sphere) (const double Radius, const double Distance) <br> |


























## Public Static Functions Documentation




### function GetAngularDiameter\_Sphere 

```C++
static inline double PlanetUtilStatics::GetAngularDiameter_Sphere (
    const double Radius,
    const double Distance
) 
```



Calculate the diameter a sphere _appears_ to have at a given distance.


Equation: 2\*arcsin(2\*r/dist) 

**Parameters:**


* `Radius` The radius of the sphere 
* `Distance` The distance from the observer to the sphere 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Private/Util/PlanetUtilStatics.h`

