int relay_pin = 7;
int relay_pin1 = 8;



void setup() {
  // put your setup code here, to run once:
   pinMode( relay_pin , OUTPUT);
   pinMode(relay_pin1 , OUTPUT);
   Serial.begin(9600);
}

void loop() {

 
   if (Serial.available())
  {
      int c = Serial.read() -48;  //gets one byte from serial buffer
      //makes the string readString=
    
    //Serial.println(readString);
    if (c==3){
     relayCoin();
    }
    if (c==4){
     relayBank();
    }
    if (c==5){
      stopRelay();
    }
  
  }
}

void relayCoin(){
  digitalWrite( relay_pin , HIGH);
  delay(1000);
//  digitalWrite(relay_pin1,LOW);
//  Serial.println('3');
}


void relayBank(){
  digitalWrite(relay_pin1, HIGH);
//  digitalWrite(relay_pin, LOW);
//  Serial.println('4');
}

void stopRelay(){
  digitalWrite(relay_pin,LOW);
  digitalWrite(relay_pin1,LOW);
}

