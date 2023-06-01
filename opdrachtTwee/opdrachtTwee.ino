// Maak een array van alle te gebruiken pinnen
const int pinArray[] = {13, 12, 11, 10, 9, 8, 7, 6};
// Sla op hoeveel pinnen gebruikt gaan worden
const int amtOfPins = 8;

void setup()
{
  // Functie aanroepen om pinmodes in te stellen
  setupPinModes();
}

void loop()
{
  // Roep de backAndForth functie aan
  backAndForth();
}

void setupPinModes()
{
  // Stel de pinmodes in voor alle pinnen in de hierboven gemaakte array
  for (int count = 0; count < amtOfPins; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void backAndForth()
{
  // Maak een loop die 8 keer loopt (0 t/m 7)
  for (int count = 0; count < amtOfPins; count++) {
    // Roep blinkLed aan en geef de loop count mee
    blinkLed(count);
  }
  
  // Maak een aflopende loop die 6 keer loopt (6 t/m 1)
  for (int count = amtOfPins -2; count > 0; count--) {
    // Roep blinkLed aan en geef de loop count mee
    blinkLed(count);
  }
}

void blinkLed(int count)
{
  // Zet de pin van de meegegeven count op aan
  digitalWrite(pinArray[count], HIGH);
  // Wacht 50 ms
  delay(50);
  // Zet de pin van de meegegeven count op uit
  digitalWrite(pinArray[count], LOW);
  // Wacht 50 ms
  delay(50);
}