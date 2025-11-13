In this page, we give a summary of how our group transformed DON, the primary goal of our project, and the core challenges to representing the vastness of space in Unreal.

## Summary: Before & After

Before our team's work, simulations in DON couldn’t load terrain data. There was only one slice of sculpted terrain for simulations. After our work, DON has the capability to display terrain for multiple celestial bodies and can smoothly transition between them in one simulation. The simulator is also equipped to smoothly transition between high-quality / high level of detail environments, such as an astronaut moving along the surface of Mars, to high-distance, lower quality use cases, such as travelling millions of miles between planets.

## The Objective

Before our team's work, DON was extremely limited in the scope of simulations it could handle. Presumably, a space simulation viewer should be able to visualize extraterrestrial travel between planets in the Solar System. But DON didn't even include the full terrain for a single planet. The tool only had the capability to use one slice of sculpted terrain on the Moon for simulations.

The goal of our project was to expand the capability of the simulation viewer to the scope of entire planets as well as enable the viewing of transportation between planets. Accurately handle distances on the scale of the Solar System in DON.

So, in short, our MVP objectives were to:

- Representing the Solar System at 1:1 scale
- Enable the full rendering of terrain for the following planetary objects: The Earth, Moon, and Mars
- Implement a system allowing movement from planet to planet (which requires that DON support distances beyond the 88 million km limit imposed by Unreal)
  - No need to support beyond 500 million km
- Create a set of sample missions for demonstration, with a craft moving from the Earth to Mars.
- Must be able to place and move objects across planetary surfaces, between planets

## The Problem

Now, we will describe in detail the challenges associated with representing the Solar System at 1:1 scale in Unreal and how we circumvented them with the system we created.

> _Space... is big._.

> **Caleb Brandt**, DON Engineer

Space is big. Due to the vastness of space, we run into two insane walls when trying to actually represent it in Unreal:

1. the limits of the engine
2. the limits of how computers even store numbers

### Floating point imprecision

First, we'll talk about the limits of how computers store numbers.

In short, the problem is: **floating point impression**. Basically, the further you get from 0, the less precision you get when representing positions. This is actually a huge issue when trying to show objects that are far away from the Sun: if we measured everything from the Sun, at the distances we’re working with you’d see things constantly jumping around when they move.

To solve this, DON has every single object’s position given relative to its “parent”. Instead of the rocket’s and the moon’s positions being absolute, relative to the sun, they’re stored relative to the Earth, and the Earth’s is relative to the Sun. So even though both the moon and the rocket are incredibly far from the sun,
by keeping the operant distances small, the rocket moves very smoothly away from the earth and towards the moon.

Now, this was actually already part of DON’s structure when we got to it, but the problem was figuring out how to represent this in an efficient manner for our overhauled placement system, because we have an even bigger problem: that being that we can’t actually place the planets where they "are."

### Unreal's coordinate system

See, Unreal’s coordinate system is really small. Ok well it isn’t - it stretches about halfway from the Earth to the Sun, which is absolutely ridiculously large for a normal game, but it’s no “entire Solar System." So we need to figure out how to represent the vastness of space in a tiny box.

We could “shrink” everything to fit in that space, but we need that detail: we need to be able to portray a buggy navigating the cracks and craters on the moon, or make sure we can watch our rocket hit smack-dab in the middle of FSU’s stadium.

But then we also need the distance, because we need to be able to travel from Earth to Mars!

### Handling two different use cases

So we have two completely different use-cases that DON needs to be equipped to support:

- **High detail, low distance**: When the user is viewing a planet's surface, we need to render the planet at a high-level of detail, such that every crater and crevice is perfectly in place. Planetary movement is at a relatively low distance but must be very precise.
- **Low detail, high distance**: When the user is viewing travel between planets, DON needs to be able to handle representing that astronomical distance, and this only requires a low level of detail for planets (and this is preferred for performance, i.e. don't need to render the full planet when it's over 88 million km away)

## Solution

So, we decided to split these into **two distinct rendering modes**: one for the planet, and one for outer space.

When we’re close enough to a planet, we render things somewhat normally. We render an incredibly high-detail planet using [Cesium](../close-range/cesium.md), and things in the simulation are placed relative to that planet - which works well with how we’re storing their positions in the first place. Also, in this mode, moving the camera actually moves the camera.

When we pass a certain predefined distance (about 1 million kilometers) from the nearest planet, we switch to a different rendering mode: [long-range rendering](../long-range/index.md). Here, everything’s placed relative to the viewer, and we use some neat tricks to make it look like you’re moving across vast distances, without ever actually having a chance of leaving Unreal’s coordinate system. Here, the camera is the origin and we don’t actually move the camera at all! Instead of moving it, we just change the reference frame: scaling far off objects as though it were moving closer to them, and moving everything relative to the camera’s “real” position.

We use billboarding, a technique that plays with perspective to make things look like they’re farther away from the viewer than they actually are. So for example, when we’re on the surface of the Earth and we look at the Sun, instead of a gigantic ball of fire that’s 93 million miles away, we have a teensy tiny ball of fire that’s only 1 million miles away. How we actually find that position is a really clever bit of math, discussed in the [Camera Rework](../camera-rework/index.md) section.

To handle these two placement modes, we abstract it a bit: each mode has its own actor placement algorithm, or **LocalPlacementManager**. When we move to the new mode, the new algorithm takes care of placing each actor according to the new coordinate system we use for the given planet.

Then we manage the actors themselves with the **GlobalPlacementManager**: this handles the transitions between levels, stores the actors, and gives the current object states to the current LPM so it can place the actors for the new simulation tick.

Simply by changing the way objects are placed in the world, we can completely change the movement system behind the scenes, and the user is none the wiser.

This architecture took a ton of work to implement, and required us to completely reimagine how objects should be placed in the world. But after circumventing the limitations of both the engine and computers themselves, we created a simulation experience that lets you seamlessly move both vast distances and one small step, with the user none the wiser.
