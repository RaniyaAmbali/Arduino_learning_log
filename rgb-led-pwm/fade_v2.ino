//  Pins (all PWM-capable on Uno)
#define RED 9
#define GREEN 10
#define BLUE 11

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

int redValue;
int greenValue;
int blueValue;

#define delayTime 10 // fading time between each colour step

void loop()
{
  redValue = 255;
  greenValue = 0;
  blueValue = 0;

  for (int i = 0; i < 255; i++) // fades red out, green in
  {
    redValue--;
    greenValue++;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(delayTime);
  }

  for (int i = 0; i < 255; i++) // fades green out, blue in
  {
    greenValue--;
    blueValue++;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  for (int i = 0; i < 255; i++) // fades blue out, red in
  {
    blueValue--;
    redValue++;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
  }
}
