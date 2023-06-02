// Definieer leds
#define ledRed 11
#define ledGreen 10
#define ledBlue 9

void setup()
{
  // Start serial
  Serial.begin(9600);
  // Roep functie aan om pin modes in te stellen
  setupLeds();
}

void loop() 
{
  // Roep functie aan om door alle mogelijke kleuren heen te loopen
  loopThroughColors();
}

void setupLeds()
{
  // Stel alle pinmodes in 
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loopThroughColors()
{
  // Loop door alle rode kleuren
  for(int redCount = 0; redCount <= 255; redCount++) {
    // Loop na elke verandering aan rood door alle groene kleuren
    for(int greenCount = 0; greenCount <= 255; greenCount++) { 
      // Loop na elke verandering aan groen door alle blauwe kleuren
      for(int blueCount = 0; blueCount <= 255; blueCount++) {
        // Stel de rode led in
        Serial.print("Red: ");
        Serial.print(redCount);
        analogWrite(ledRed, redCount);

        // Stel de groene led in
        Serial.print(" Green: ");
        Serial.print(greenCount);
        analogWrite(ledGreen, greenCount);

        // Stel de blauwe led in
        Serial.print(" Blue: ");
        Serial.print(blueCount);
        analogWrite(ledBlue, blueCount);

        Serial.println();
      }
    }
  }
}
