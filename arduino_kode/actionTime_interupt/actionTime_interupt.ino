//pin brukt i esp32s
//Board: her brukt esp32 Dev Module 
const int reactiomaller{14};
const int ledReaktion {13};

// verdier trengt for å gjør ting.
int randomTime{0};
int startTime {0};
int endTime{0};
int ActionTime{0};
int minWaitingTime {400};
int maxWaitingTime {2601};

void setup() {
  // Serial Monitor; 115200 
  Serial.begin(115200);  

  //Forteller koden hva pinsene skal gjøre
  pinMode(reactiomaller, INPUT);
  pinMode(ledReaktion, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin), ISR, RISING)
}

void loop() {
   randomTime = random(minWaitingTime, maxWaitingTime);

   digitalWrite(ledReaktion, HIGH);
   startTime = millis();

  unsigned long waitStart = millis();
  while (millis() - waitStart < randomTime) {
    delay(1);
  }

//  digitalWrite(ledReaktion, LOW);
//  while(1==1){
//    }
  
  interrupts();
  
  endTime = millis();// måler når man har klikket inn.  
  digitalWrite(ledReaktion, LOW);
  ActionTime = endTime - startTime; 
  Serial.println(ActionTime);
}
