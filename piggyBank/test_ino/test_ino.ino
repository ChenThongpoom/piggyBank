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
  
  //while(!Serial.available()) {
    if (digitalRead(13) == 0){
      countone+=1;
      }
  
    if (digitalRead(12) == 0){
      counttwo += 2;
      }
  
    if(digitalRead(11) == 0){
      countfive += 5;
    }
  
    if(digitalRead(10) == 0){
      countten += 10;
    }
    delay(60);
  //}
  // serial read section
  //while (Serial.available())
  //{
    if (Serial.available() >0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    }
  //}
  
  if (readString.length() >0)
  {
    //Serial.println(readString);
    if (readString=="1"){
     sensor();
    }
    if (readString=="2"){
     sendResult();
    }
   readString = ""; 
  }
}

void sensor(){
  countone = 0;
  counttwo = 0;
countfive = 0;
countten = 0;
}

void sendResult(){
   Serial.println(countone);
   Serial.println(counttwo);
   Serial.println(countfive);
   Serial.println(countten);
}

