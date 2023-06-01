const int ledRood = 11;  // Definieer pin 11 als ledRood
const int ledGroen = 12;  // Definieer pin 12 als ledGroen

void setup()
{
  pinMode(ledRood, OUTPUT);  // Zet de pinmodus van ledRood naar OUTPUT
  pinMode(ledGroen, OUTPUT);  // Zet de pinmodus van ledGroen naar OUTPUT
}

void loop()
{
  blinkLeds();  // Roep de functie blinkLeds aan
}

void blinkLeds()
{
  digitalWrite(ledRood, HIGH);  // Zet ledRood aan (HIGH)
  delay(1000);  // Wacht 1000 milliseconden (1 seconde)
  digitalWrite(ledRood, LOW);  // Zet ledRood uit (LOW)
  digitalWrite(ledGroen, HIGH);  // Zet ledGroen aan (HIGH)
  delay(1000);  // Wacht 1000 milliseconden (1 seconde)
  digitalWrite(ledGroen, LOW);  // Zet ledGroen uit (LOW)
}

