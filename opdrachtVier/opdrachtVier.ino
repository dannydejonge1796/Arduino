// Stop alle te gebruiken pinnen in een array
const int pinArray[] = {7, 8, 9, 10, 11, 12, 13};
// Sla het aantal pinnen op in var
const int amtOfPins = 7;
// Definieer de potentiometer
#define potentio A0

// Maak een var aan voor het bijhouden van de huidige waarde van de potentiometer
int currentPotentioRead = 0;

void setup()
{
  // Init serial
  Serial.begin(9600);
  
  // Roep functie aan om pinmodes van leds in te stellen
  initializeLEDs();
  // Stel de pinmode van de potentiometer in
  pinMode(potentio, INPUT);
  
  // Verkrijg de huidige waarde
  currentPotentioRead = analogRead(potentio);
  // Vorm de waarde om tot waardes van 0-6 door de mapPotentioValue functie aan te roepen
  currentPotentioRead = mapPotentiometerValue(currentPotentioRead);
  
  // Laat een led branden met de initiele waarde
  digitalWrite(pinArray[currentPotentioRead], HIGH);
}

void loop()
{
  // Verkrijg weer de waarde van de potentio en map deze naar 0-6
  int potentioRead = analogRead(potentio);
  potentioRead = mapPotentiometerValue(potentioRead);
  
  // Als deze waarde in de loep niet gelijk is aan de current betekend dit dat de waarde veranderd is
  if (potentioRead != currentPotentioRead) {
    // Schakel alle leds uit door de functie aan te roepen
    turnOffAllLEDs();
    // Zet juist led aan, vind deze met de waarde van de potentio als idx in de array
    digitalWrite(pinArray[potentioRead], HIGH);
    
    // Stel de nieuwe waarde van de potentio in als current
    currentPotentioRead = potentioRead;
  }
}

void initializeLEDs()
{
  // Stel de pinmode in voor alle pins uit de array
  for (int count = 0; count < amtOfPins; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void turnOffAllLEDs()
{
  // Schakel alle leds uit
  for (int count = 0; count < amtOfPins; count++) {
    digitalWrite(pinArray[count], LOW);
  }
}

int mapPotentiometerValue(int value)
{
  // Map de potentiometer waardes naar een range van 0 t/m 6
  return map(value, 0, 1023, 0, 6);
}
