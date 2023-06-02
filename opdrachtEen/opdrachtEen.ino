// De te gebruiken pinnen definiëren
const int ledRood = 11; 
const int ledGroen = 12; 

void setup()
{
  // Functie aanroepen om pinmodes in te stellen
  setupPinModes();
}

void loop()
{
  // Roep de functie blinkLeds aan
  blinkLeds();  
}

void setupPinModes()
{
  // Pinmodes instellen voor de hierboven gedefinieerde pinnen
  pinMode(ledRood, OUTPUT); 
  pinMode(ledGroen, OUTPUT);  
}

void blinkLeds()
{
  // Zet de rode led aan
  digitalWrite(ledRood, HIGH);  
  // Wacht 1 seconde
  delay(1000); 
  // Zet de rode led uit
  digitalWrite(ledRood, LOW);  
  // Zet de groene led aan
  digitalWrite(ledGroen, HIGH);  
  // Wacht 1 seconde
  delay(1000);
  // Zet de groene led uit  
  digitalWrite(ledGroen, LOW);  
}

