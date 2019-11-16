int countone = 0;
int counttwo = 0;
int countfive = 0;
int countten = 0;


void setup() {

  // initialize serial communication at 9600 bits per second:

  Serial.begin(9600);
  if (Serial.read()==1){
    sensor();
  }
}

// the loop routine runs over and over again forever:

void loop() {

    
//    Serial.println(countone);
//    Serial.println(counttwo);
//    Serial.println(countfive);
//    Serial.println(countten);
  
  
//  Serial.write(countone);
    
  //if (Serial.read()=='1'){
//    sensor();
    
  //}
}

void sensor(){
  int i = 0;
  while (true){
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
    
    if ()
    delay(70);
    
  }
  int coin[4];
  
    coin[0] = countone  
    coin[1] = counttwo;
    coin[2] = countfive*5;  
    coin[3] = countten*10;
//    byte *p = (byte*)coin;
//    for(byte i = 0; i<sizeof(coin);i++){
       Serial.write(coin);
//    }
  
}

