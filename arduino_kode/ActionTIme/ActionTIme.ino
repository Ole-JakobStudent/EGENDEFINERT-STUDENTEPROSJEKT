
//pins in use
const int LED_Out {10};
const int Signal_inn {11};

//variables
int delayTime;
int delayMicro;
int ActionTime {0};



void setup() {
  // put your setup code here, to run once:
pinMode(LED_Out, OUTPUT);
pinMode(Signal_inn, INPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  timeBefore = 0;
  timeAfter  = 0;
  delayTime  = 100; // randomise this
  
  //delayMicro = 100 000; // randomise this 
  //delayMicroseconds(delayMicro);
  
  delay(delayTime);
  digitalWrite(LED_Out, HIGH);
  timeBefore = millis(); // micros() also availeble

  while(Signal_inn == HIGH){
  }

  timeAfter = millis(); // micros() also availeble

  ActionTime = timeAfter - timeBefore;

  Serial.println(ActionTime, DEC);

}
