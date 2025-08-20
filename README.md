# Gravitational Time Dilation Calculator (WIP)

> Status: **Work In Progress** – Core equations are implemented. A real‑time interactive spacetime visualization layer is under active development. This README is intentionally minimal until the first visual MVP is complete.

## What This Project Will Become
An educational sandbox to explore General + Special Relativity time dilation effects around a single (non‑rotating) mass:
- Gravitational time dilation (Schwarzschild metric factor)
- Optional velocity (special relativity) time dilation combined in real time
- Planned: interactive controls to adjust mass, radius, velocity
- Planned: deformable spacetime grid (visual warp) + color mapping of local time rate
- Planned: orbit mode (auto circular velocity) vs manual velocity
- Planned: on‑screen display of formulas with live substituted values
- Planned: rings for notable radii (Schwarzschild radius, photon sphere, ISCO)

## Current Capabilities (Early)
- CLI computation of gravitational time dilation given `r` and `M`
- Optional inclusion of velocity factor when a third argument is passed
- Basic raylib window created (visual layer placeholder; not final)

## Inputs (Current CLI Mode)
- **r** – radial distance from mass center (meters)
- **M** – mass (kilograms)
- **v** – (optional) velocity (m/s) for SR factor (currently treated directly, not as a fraction; future UI will clarify)

## Output Meaning
- Value near **1.0** → negligible dilation (far from mass / low velocity)
- Value approaching **0** → extreme dilation (approaching Schwarzschild radius)

## Core Equations (Implemented)
If 2 arguments (`r`, `M`):
\[\Delta t' = \Delta t \sqrt{1 - \tfrac{2GM}{r c^2}}\]

If 3 arguments (`r`, `M`, `v`):
\[\Delta t' = \Delta t \sqrt{1 - \tfrac{2GM}{r c^2}} \cdot \sqrt{1 - \tfrac{v^2}{c^2}}\]

Constants:
- \( G = 6.67430 \times 10^{-11}\,\text{m}^3/\text{kg}/\text{s}^2 \)
- \( c = 299,792,458\,\text{m/s} \)

## Temporary Usage (Until Interactive Mode Exists)
1. Build with the provided Makefile (e.g. `mingw32-make game` or through VS Code task).
2. Run the produced executable with:
  - `program r M`  (gravitational only)
  - `program r M v` (gravitational + velocity)

Example (placeholder, adjust executable name):
```
game.exe 7000000 5.972e24
game.exe 7000000 5.972e24 1000
```

## Roadmap Snapshot
1. Document physics & visualization mapping
2. Replace helper grid with custom deformable mesh
3. Real-time parameter controls (mass, radius, velocity)
4. Proper time accumulation (local vs distant clock)
5. Visual rings & color gradient for dilation
6. Optimization & polish

## Accuracy & Scope Note
Initial version models only a static, non-rotating mass (Schwarzschild). No frame dragging, no multiple masses, no lensing—those may appear later. Visual warp is an educational approximation, not a literal embedding diagram.

## License / Attribution
Uses [raylib](https://www.raylib.com/) (Copyright Ramon Santamaria & contributors). Equations derived from standard GR/SR textbook forms (public domain physics).

---
WIP notice: This file will be expanded after the first interactive prototype. Frequent pushes may leave this README slightly behind code reality.
