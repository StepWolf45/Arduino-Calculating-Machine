int pinID=0;
void setup() {
   Serial.begin(9600);
   for(int i=2;i<=13;i++){
      pinMode(i, OUTPUT);
   }
  for(int i=2;i<=13;i++){
       digitalWrite(i,HIGH);
       delay(90);
  }
  for(int i=13;i>=2;i--){
       digitalWrite(i,0);
       delay(90);
  }
}
void loop() {
  int number = Serial.parseInt();
  int index;
  if(number>0 && number <=4095){ 
      pinID = 13;
      for(int i=2;i<=13;++i)
        digitalWrite(i,0);
      while(number){
        index = number%2;
        digitalWrite(pinID,index);
        number/=2;
        Serial.print(index);
        pinID--;
      }
  }
}