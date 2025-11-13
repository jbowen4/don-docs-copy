

# File PlanetUtilStatics.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Private**](dir_2c3ab2caebe6f83b4fac8c870e601c85.md) **>** [**Util**](dir_3a690fa77d5963354acc6a5ac4ebb1d1.md) **>** [**PlanetUtilStatics.h**](_planet_util_statics_8h.md)

[Go to the documentation of this file](_planet_util_statics_8h.md)


```C++
#pragma once

struct PlanetUtilStatics
{
    inline static double GetAngularDiameter_Sphere(const double Radius, const double Distance)
    {
        return 2*FMath::FastAsin(2 * Radius / Distance);
    }
};
```


