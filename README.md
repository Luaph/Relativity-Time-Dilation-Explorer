# Gravitational Time Dilation Calculator

## Overview
This project is a **C program** that calculates gravitational time dilation, an effect predicted by Einstein’s theory of General Relativity. In strong gravitational fields, time passes more slowly compared to regions with weaker gravity.

Given:
- **r** → Distance from the center of the massive object (in meters)
- **M** → Mass of the object (in kilograms)
- **v** → (Optional) Velocity as a fraction of the speed of light (for combined gravitational and velocity time dilation)

**Output:**
- `1` = No distortion due to gravity (far from the mass)
- `0` = Boundary at the event horizon of a black hole (Schwarzschild radius)

## Equations

- **If you provide 2 arguments** (`r`, `M`):

  \[
  \Delta t' = \Delta t \sqrt{1 - \frac{2GM}{rc^2}}
  \]

- **If you provide 3 arguments** (`r`, `M`, `v`):

  \[
  \Delta t' = \Delta t \sqrt{1 - \frac{2GM}{rc^2}} \cdot \sqrt{1 - \frac{v^2}{c^2}}
  \]

Where:
- \( G \) = Gravitational constant (\(6.67430 \times 10^{-11}\) m³/kg/s²)
- \( c \) = Speed of light (\(299,792,458\) m/s)

## Usage

1. Compile the program with makefile
2. ./executable.out r M v
