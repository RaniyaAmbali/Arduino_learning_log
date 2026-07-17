# RGB LED – PWM Fade

First hands-on Arduino project on my own — wired an RGB LED and used PWM to fade smoothly between red, green and blue.

## What I Learned
- LED polarity: Anode (long leg) → Arduino pin, Cathode (short leg) → GND
- Resistors protect LEDs from excess current
- PWM-capable pins on Uno: 3, 5, 6, 9, 10, 11
- `analogWrite()` takes values 0–255 (0 = off, 255 = full brightness)
- How to build a smooth color-fade loop (RED→GREEN→BLUE→RED)

## Code
See [`rgb_fade.ino`](./rgb_fade.ino)
