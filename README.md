# Relativity Time Dilation Explorer (WIP)

> Interactive real‑time sandbox for visualizing how gravitational and velocity (special relativistic) effects slow proper time relative to a distant coordinate clock. (Formerly "Gravitational Time Dilation Calculator").

## Current State (Interactive Prototype)
The program opens a raylib window and continuously simulates a single, non‑rotating mass. You can:

- Adjust mass (W/S keys) – scales the Schwarzschild radius Rs.
- Move radial position r (Q inward, E outward) – approaches or recedes from the horizon.
- Change velocity fraction f = v/c (A decrease, D increase) – adds special relativity time dilation.
- Observe live values: Rs, r, f, gravitational factor Tg, velocity factor Tv, combined factor T = Tg*Tv, accumulated coordinate time, accumulated proper time, frame dt.

The HUD updates every frame; proper time accumulates slower than coordinate time according to the combined factor.

### Why The Factors
- Tg = sqrt(1 - 2GM/(r c^2))   (static observer gravitational time dilation)
- Tv = sqrt(1 - f^2)           (special relativity; f = v/c)
- T  = Tg * Tv                  (independent contributions multiplied under current assumptions)

### Safety Constraints
- r is clamped to r >= (1 + ε) * Rs to keep the square root argument positive (ε = 1e-4).
- f is clamped to f <= f_max = 0.99 to avoid floating point overshoot beyond light speed.

## Build & Run

Assumes raylib is installed at `C:/raylib/raylib` (headers in `src`, libs built). Edit the Makefile if your path differs.

Build (VS Code task or manually):
```
mingw32-make
```

Run the produced executable (default name `time_dilation.exe`):
```
./time_dilation.exe
```

## Controls Summary
| Key | Action |
|-----|--------|
| W / S | Decrease / Increase mass |
| Q / E | Move radius inward / outward (scales proportionally) |
| A / D | Decrease / Increase velocity fraction f |
| ESC   | Quit |

## Code Structure
- `src/simulation.c` / `include/simulation.h` – Simulation state, input handling, physics update.
- `src/hud.c` / `include/hud.h` – On‑screen statistics panel.
- `src/DG.c` / `include/DG.h` – Gravitational factor Tg.
- `src/DC.c` / `include/DC.h` – Combined factor helper (not yet heavily used in loop).
- `src/constants.c` / `include/constants.h` – Physical constants (c, G).
- `src/mapping.c` – Placeholder for upcoming deformable spacetime mesh (WarpGrid scaffold).
- `src/main.c` – Orchestrates frame loop (input → physics → render).

## Planned Next Features
1. Replace `DrawGrid` with custom deformable mesh warped by (1 - Tg) or similar mapping.
2. Color mapping of dilation intensity.
3. Rings for notable radii (Rs, photon sphere, optional ISCO marker).
4. Orbit mode: auto set f to local circular orbital velocity.
5. Reset & preset hotkeys (Earth mass, Solar mass, Near‑horizon, etc.).
6. Display lost-time metric (coordinate time - proper time) and average dilation.
7. Performance cleanup (update mesh only when parameters change).

## Physics Scope & Limitations
Currently models only the Schwarzschild exterior solution (static, non‑rotating, uncharged mass). No frame dragging (Kerr), no lensing visuals, no tidal forces, no multiple masses. Visual warp (when added) will be an educational embedding diagram approximation, not a fully accurate spacetime rendering.

## Contributing / Extending
Ideas welcome: mesh shaders, color palettes, educational overlays (derivations, formula substitution). Keep modules focused (simulation vs rendering vs UI) for maintainability.

## License / Attribution
- Uses [raylib](https://www.raylib.com/).
- Standard GR/SR equations (public domain physics).

---
This README reflects the current interactive build; it will evolve as visualization features land.
