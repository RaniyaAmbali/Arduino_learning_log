# Ultrasonic Distance Measurement System

A standalone Arduino sketch using an HC-SR04 ultrasonic sensor to measure 
distance in real time, display it on a 16x2 I2C LCD, and trigger an LED + 
warning message when an object comes within 6 cm.

This was built as a foundational practice project — understanding how 
ultrasonic sensing, LCD output, and threshold-based alerts work.


## Hardware

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD with I2C module
- LED
- Jumper wires

## Wiring

| Component | Arduino Pin |
|---|---|
| HC-SR04 TRIG | 9 |
| HC-SR04 ECHO | 10 |
| LED | 7 |
| LCD SDA | A4 |
| LCD SCL | A5 |

## How it works

The HC-SR04 doesn't measure distance directly — it measures time. The 
Arduino sends a 10 µs trigger pulse, the sensor emits a 40 kHz ultrasonic 
pulse, and the ECHO pin stays HIGH for exactly as long as it takes the 
sound to travel to an object and bounce back.

Distance is calculated as:
distance (cm) = (echo duration × 0.034) / 2

The result is divided by 2 because the measured time covers the sound's 
full round trip (sensor → object → sensor), not just the one-way distance.

If the measured distance is 6 cm or less, the system enters warning mode: 
the LCD displays "Object Too Close" and the LED blinks. Otherwise, the LCD 
shows the live distance reading.
