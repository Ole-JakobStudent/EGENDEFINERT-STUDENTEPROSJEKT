
//pins in use
const int LED_Out {13};
const int Signal_inn {12};

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Out, OUTPUT);
  pinMode(Signal_inn, INPUT);

  Serial.begin(115200);
//Serial.monitor(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //variables
  int min_sec {100};
  int max_sec {600};
  int delayTime {random(min_sec, max_sec)}; // random(min_sec, max_sec);
  int delayMicro;
  int ActionTime {0};
  int timeBefore = 0;
  int timeAfter  = 0;
  //delayTime  = 100; // randomise this
  
  //delayMicro = 100 000; // randomise this 
  //delayMicroseconds(delayMicro);

  digitalWrite(LED_Out, LOW);
  delay(delayTime);
  digitalWrite(LED_Out, HIGH);

  //delay(delayTime); // for feil søking
  // the measurement system
  timeBefore = millis(); // micros() also availeble

  // when signal is zero, do not pass // not working correct
  while(digitalRead(Signal_inn) == LOW){
    //Serial.print("hei");
  }
  
  timeAfter = millis(); // micros() also availeble
  ActionTime = timeAfter - timeBefore;
  Serial.println(delayTime);

}
