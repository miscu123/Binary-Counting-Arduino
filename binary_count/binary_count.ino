volatile char bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile char ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
volatile bool updateFlag = false;
volatile bool stopFlag = false; 

bool maximum_reached() {
  bool all = true;

  for (int i = 0; i < 8; i++) {
    if (bits[i] == 0) {
      all = false;
      break;
    }
  }

  return all;
}

void updateLeds() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], bits[i]);
  }
}

void incrementBits() { // led ON / OFF logic
  for (int i = 7; i >= 0; i--) {
    if (bits[i] == 0) {
      bits[i] = 1;
      break;
    } else {
      bits[i] = 0;
    }
  }
}

void initCounter() { // setup

  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  TCCR1B |= (1 << WGM12);             
  OCR1A = 15624 * 0.15;                    
  TCCR1B |= (1 << CS12) | (1 << CS10); 
  TIMSK1 |= (1 << OCIE1A);            
  interrupts();

}
 
void setup() { // initiate setup
  initCounter(); 
}

void loop() {
  if (updateFlag) {
    updateFlag = false;
    updateLeds();

    if (maximum_reached()) {
      stopFlag = true;
    }
  }
}

ISR(TIMER1_COMPA_vect) {
  if (!stopFlag) {
    incrementBits();
    updateFlag = true;
  }
}
