// Definieer pinnen die gebruikt moeten worden
const int ledRed = 11;
const int button = 8;

// Houdt bij of de button op indrukken gecheckt moet worden
bool checkBtnPress = true;

void setup() {
  // Init serial
  Serial.begin(9600);
  // Init pins functie aanroepen
  initializePins();
}

void loop() {
  // Check voorkomt dat condition meerdere malen wordt uitgevoerd
  if (checkBtnPress) {
    // Functie aanroepen die teruggeeft of button ingedrukt is
    if (isButtonPressed()) {
      // Functie aanroepen die teruggeeft of led aan is
      if (isLedOn()) {
        // Functie aanroepen die led uitschakeld
        turnLedOff();
      } else {
        // Functie aanroepen die led inschakelt 
        turnLedOn();
      }

      // Na 1 keer moet de condition niet nogmaals worden uitgevoerd, status check button press naar false
      checkBtnPress = false;
    }
  } else {
    // Functie aanroepen die teruggeeft of knop is losgelaten
    if (isButtonReleased()) {
      // Er mag weer gecheckt worden op nieuwe indruk van de knop
      checkBtnPress = true;
    }
  }
}

void initializePins() {
  // Pinmodes instellen van te gebruiken pinnen
  pinMode(ledRed, OUTPUT);
  pinMode(button, INPUT);
}

bool isButtonPressed() {
  // Als button status LOW is (is ingedrukt) return true
  return (digitalRead(button) == LOW);
}

bool isLedOn() {
  // Als led al aan is return true
  return (digitalRead(ledRed) == HIGH);
}

void turnLedOff() {
  // Schakel led uit
  Serial.println("LED off");
  digitalWrite(ledRed, LOW);
}

void turnLedOn() {
  // Schakel led in
  Serial.println("LED on");
  digitalWrite(ledRed, HIGH);
}

bool isButtonReleased() {
  // Als knop na indrukken wordt losgelaten return true
  return (digitalRead(button) == HIGH);
}
