/*
 * Goldo'Home
 * 
 * - Centralized lights
 * 
 */

boolean DEBUG = true;

int LED_SALON = 4;
int LED_WC = 5;
int LED_SALLEBAIN = 6;
int LED_CHAMBRE1 = 7;
int LED_CHAMBRE2 = 8;
int LED_GARAGE = 9;

int LEDS[] = {LED_SALON, LED_WC, LED_SALLEBAIN, LED_CHAMBRE1, LED_CHAMBRE2, LED_GARAGE};
  
void setup() {

  // Debug ?
  if(DEBUG){
     Serial.begin(9600); 
  }
  
  // Declare all LED as OUTPUT
  for (int current = 0; current < sizeof(LEDS); current++) {
    pinMode(current, OUTPUT);
  }  
}

void loop() {
  powerOnLed(LED_SALON);
  delay(2000);
  powerOffLed(LED_SALON);
}



/**
 * powerOnLed()
 * @param int id
 */
void powerOnLed(int id){
  char message[50];
  sprintf(message, "Power on Led %d was send", id);
  Serial.println(message);

  digitalWrite(id, HIGH);
}

/**
 * powerOffLed()
 * @param int id
 */
void powerOffLed(int id){
  char message[50];
  sprintf(message, "Power off Led %d was send", id);
  Serial.println(message);

  digitalWrite(id, LOW);
}
