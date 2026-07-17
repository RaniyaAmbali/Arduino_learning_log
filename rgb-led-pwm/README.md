# RGB LED – Color Cycle → True PWM Fade

First hands-on Arduino project — wired an RGB LED and initially tried to fade smoothly between red, green, and blue.

## Attempt 1: Color Cycle (unexpected result)
Wired to pins 11 (RED), 12 (GREEN), 13 (BLUE) and used `analogWrite()` expecting a smooth fade.
Instead, only RED faded smoothly — GREEN and BLUE snapped abruptly on/off instead of dimming.

reason for this was the Arduino Uno only supports true PWM (`analogWrite()`) on pins 3, 5, 6, 9, 10, 11. Pins 12 and 13 don't have PWM hardware, so `analogWrite()` on those pins just acts like `digitalWrite()` — off below ~128, fully on at 128+, with no in-between brightness. This produced a color cycle (blinking) instead of a fade.

See [`color_cycle_v1.ino`](./color_cycle_v1.ino)

## Attempt 2: True PWM Fade (fixed)
Rewired to pins 9, 10, 11 (all PWM-capable) and re-ran the same logic.
Result: smooth, continuous fading between all three colors, as originally intended.

See [`fade_v2.ino`](./fade_v2.ino)

## What I Learned
- LED polarity: Anode (long leg) → Arduino pin, Cathode (short leg) → GND
- Resistors protect LEDs from excess current
- Not all Arduino pins support PWM — only 3, 5, 6, 9, 10, 11 on the Uno
- `analogWrite()` on non-PWM pins silently falls back to on/off behavior instead of erroring out, which made this bug tricky to catch at first
- How to build a smooth color-fade loop (RED→GREEN→BLUE→RED) using `analogWrite()`
