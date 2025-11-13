A way to represent faraway objects
Distant planets should look far away, but actually be relatively close
Find camera-planet distance, scale down the planet
We call these shrunk-down planets billboards
A billboard management system
Encapsulates the functionality of resizing planets
Maintains apparent distance/size

For planetary bodies that are closer (within 88 million kilometers), we will utilize high-detail Unreal models featuring real terrain, using Cesium. For more distant planets, we will use billboards, which are low-resolution 3D models at a fixed distance from the camera but are scaled to ensure they appear the correct size in the sky. As the user gets closer to a planet, the system will seamlessly transition from the billboard to the full model rendering, and it will do the opposite when moving away. This strategy allows us to overcome Unreal’s constraints on world size while still providing believable visuals over vast distances.

On leaving the aforementioned distance threshold, the planetary object is unloaded as a Cesium asset and replaced with a billboard model in the distance. This means that a low-quality version of the object is placed at a fixed distance from the player, with a scaled size and position lining up with its expected position, as if it were in the ‘real’ world. The origin of the UE5 plane becomes the player’s position. To track the ‘true’ positions of all planetary objects, therefore, a secondary coordinate plane is needed.

Both modes return to the same task: calculating the placement of distant objects for billboarding. Billboarded objects are then loaded using the rendering manager system, which simply takes asset references, positions, and scale factors as inputs.

## Scale Distances Manager

The solar positions are then utilized by the Scaled Distances Manager (Figure 7). This subsystem runs after the solar position manager, and uses the positions of all planetary objects on the sun-relative plane to determine where on the Unreal plane the planetary objects should lie. This means determining where on the ‘billboarding dome’ each planetary object should lie, and at what size each planetary object should be. This is achieved by first calculating the angles (alpha and beta) each planetary object is at relative to the player camera (Figure 8). As it takes the radius of the billboarding dome as an input, it also calculates the scale at which the planetary object must be rendered to maintain the same ‘apparent’ size. If the scale is 10, then the object must be drawn at ten times its actual size to maintain apparent scale. The alpha and beta angles are then translated to positions on the billboarding dome in x,y,z position on the Unreal Engine plane. This operation is performed for every planetary object, and these outputs are stored in a vector of arrays, where each array stores x/y/z position and scale.
