#define encoder0PinA  2
#define encoder0PinB  3

void setup() {
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinA, INPUT);

  attachInterrupt(digitalPinToInterrupt(encoder0PinA), Change, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder0PinB), Change, CHANGE);

  SerialUSB.begin(9600);
  while (!SerialUSB) {    
    ;
  }  
  SerialUSB.println("Starting...");   
}

int OldCount = 0;
int counter = 0;
int lastA = 0;
int lastB = 0;

void loop() {
  if(OldCount != counter){
    OldCount = counter;
    SerialUSB.println(OldCount);         
  }
}

void Change(){
  int SensorA  = digitalRead(encoder0PinA);
  int SensorB  = digitalRead(encoder0PinB);

  // End of pulse
  if(SensorA == 0 && SensorB == 0){
    
    if(lastA == 0 && lastB == 1){
      counter++;  
    }
    else if(lastA == 1 && lastB == 0){
      counter--;  
    }
    
  }
 
  if(SensorA != lastA){
    lastA = SensorA;
  }
  if(SensorB != lastB){
    lastB = SensorB;
  }
 
}
