// Definieer pinnen die gebruikt moeten worden
const int ledRed = 11;
const int button = 8;
// Houdt bij of de button op indrukken gecheckt moet worden
bool checkBtnPress = true;

void setup() {
  // Init serial
  Serial.begin(9600);
  // Pinmodes instellen van te gebruiken pinnen
  pinMode(ledRed, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // Check voorkomt dat condition meerdere malen wordt uitgevoerd
  if (checkBtnPress) {  
    // Als button status LOW is (is ingedrukt)
    if (digitalRead(button) == LOW) {
      // Als led al aan is
      if (digitalRead(ledRed)== HIGH) {
        // Schakel led uit
        Serial.println("LED off");
        digitalWrite(ledRed, LOW);
      } else {
        // Anders led inschakelen
        Serial.println("LED on");
        digitalWrite(ledRed, HIGH);
      }
    }
    
    // Na 1 keer moet de condition niet nogmaals worden uitgevoerd, status check button press naar false
    checkBtnPress = false;
  } else {
    // Als knop na indrukken wordt losgelaten
  	if (digitalRead(button) == HIGH) {
      // Mag er weer gecheckt worden op nieuwe indruk van de knop
      checkBtnPress = true;
    }
  }
}

