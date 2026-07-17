#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht_nonblocking.h>

// defining the sensor type
#define DHT_SENSOR_TYPE DHT_TYPE_11 
static const int DHT_SENSOR_PIN = 2;

DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// LCD address 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DHT11 Test...");
}

//Reads sensor only every 3+ seconds 
static bool measure_environment(float *temperature, float *humidity) {
  static unsigned long measurement_timestamp = millis();

  if (millis() - measurement_timestamp > 3000ul) {
    if (dht_sensor.measure(temperature, humidity) == true) {
      measurement_timestamp = millis();
      return true;
    }
  }
  return false;
}

void loop() {
  float temperature;
  float humidity;

  if (measure_environment(&temperature, &humidity) == true) {

    // Valid reading, print to the serial monitor and LCD
    Serial.print("T = ");
    Serial.print(temperature, 1);
    Serial.print(" C, H = ");
    Serial.print(humidity, 1);
    Serial.println("%");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity, 1);
    lcd.print(" %");

  } else {
    // ERROR CASE — if sensor not responding
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.setCursor(0, 1);
    lcd.print("Check DHT11");
    
    Serial.println("ERROR: No sensor data");
    delay(500);  // small delay so LCD doesn't flicker too fast
  }
}
