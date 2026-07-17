# DHT11 + I2C LCD — Temperature & Humidity Display

**Status: Unresolved — pending professor follow-up**

## Goal
Build a live temperature/humidity display by combining a DHT11 sensor with an I2C LCD screen.

## What Happened
On first setup, the LCD displayed "Sensor Error" instead of live readings. I debugged systematically:

- Rechecked every wire connection between the DHT11, LCD, and Arduino
- Disconnected the LCD entirely to isolate and test the DHT11 sensor on its own via Serial Monitor
- Removed the breadboard altogether and wired the DHT11 directly to the Arduino, to rule out breadboard/contact issues
- Confirmed correct pin identification (middle pin = VCC on this DHT11 module — pin order isn't standardized across manufacturers, so I verified through research rather than guessing)
- Verified the Arduino board itself was fully healthy (tested separately with a Blink sketch)
- Added a safety resistor in series on the VCC line to protect against further risk while testing

Despite all of this, the sensor consistently failed to return valid readings, printing `"Failed to read from DHT sensor!"` every time.



## Likely Cause
Root cause unconfirmed — two possibilities:
1. An earlier VCC/GND wiring mix-up (from incorrect pin identification) may have silently damaged the sensor's internal circuitry, even without visible heat.
2. The sensor unit itself may have simply been faulty out of the box.

Testing against a known-good replacement DHT11 (or with a multimeter) would be needed to confirm which.

## Wiring Used

**DHT11 (3-pin module):**
| DHT11 pin | Arduino |
|---|---|
| VCC (middle) | 5V |
| OUT (signal) | Digital Pin 2 |
| GND | GND |

**I2C LCD:**
| LCD pin | Arduino |
|---|---|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

## Code
See [`dht11_lcd.ino`](./dht11_lcd.ino) — last version tested before pausing this component.

## Next Steps
- Follow up with professor for diagnosis with access to a multimeter and a spare DHT11 unit
- Test DHT11 in isolation against known-good hardware to confirm whether the sensor itself is dead
- will Update this README once resolved


- Follow up with professor for diagnosis with access to a multimeter and a spare DHT11 unit
- Test DHT11 in isolation against known-good hardware to confirm whether the sensor itself is dead
- Update this README once resolved
