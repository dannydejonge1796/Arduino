// Definieer de temperatuursensor
#define tempSen A0

void setup()
{
  // Start serial
  Serial.begin(9600);
  // Stel pinmode in voor de temperatuursensor
  pinMode(tempSen, INPUT);
}

void loop()
{
  // Verkrijg de waarde uit de temperatuursensor
  float value = analogRead(tempSen);
  // Verkrijg de graden celsius door de omreken functie aan te roepen
  int celsius = calcCelsius(value);
  // Print de graden celsius door de print functie aan te roepen
  printCelsius(celsius);
}

int calcCelsius(float value)
{
  // Reken de waarde uit de temperatuursensor om naar graden celsius
  float celsius = (value / 1023.0) * 500;
  // Rond de uitkomst af en return
  return round(celsius);
}

void printCelsius(int celsius)
{
  // Print de graden celsius uit
  Serial.print("Temperatuur in graden Celsius = ");
  Serial.print(celsius);
  Serial.println();
}