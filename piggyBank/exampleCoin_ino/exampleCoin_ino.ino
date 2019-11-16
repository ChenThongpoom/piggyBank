int countone = 0;
int counttwo = 0;
int countfive = 0;
int countten = 0;
int val = 1;
String readString;

void setup() {

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:

void loop() {
  
  //while(!S
  if (digitalRead(13) == 0){
    while(!digitalRead(13)){}
       countone+=1;
        //Serial.println(countone);
    } 
  
    if (digitalRead(12) == 0){
          while(!digitalRead(12)){}

      counttwo+=2;
             //Serial.println(counttwo);
      }
      
  
    if(digitalRead(11) == 0){
    while(!digitalRead(11)){}

      countfive+=5;
             //Serial.println(countfive);
          
    }
  
    if(digitalRead(10) == 0){
      while(!digitalRead(10)){}

      countten+=10;
             //Serial.println(countten);
          
    }
    //delay(51);
//}
  // serial read section
  if (Serial.available())
  {
      int c = Serial.read() -48;  //gets one byte from serial buffer
      //makes the string readString=
    
    //Serial.println(readString);
    if (c==1){
     sensor();
    }
    if (c==2){
     sendResult();
    }
  
  }
  
}
void sensor(){
  countone = 0;
  counttwo = 0;
  countfive = 0;
  countten = 0;
}

void sendResult(){
  char buffer [12];
  sprintf(buffer, "%d,%d,%d,%d", countone, counttwo, countfive, countten);
   //Serial.print(countone);
   //Serial.print(counttwo);
   //Serial.print(countfive);
   //Serial.print(countten);
   Serial.print(buffer);
}

