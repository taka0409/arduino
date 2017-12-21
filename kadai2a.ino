int x,y,z,R=3,G=5,B=6,flag=0;
void setup() {
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
}
void OFF (){
    digitalWrite(G,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(R,HIGH);
  }
void Red () {
    digitalWrite(G,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(R,LOW);
  }
void Green(){
    digitalWrite(G,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(R,HIGH);
  }
void Blue(){
    digitalWrite(G,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(R,HIGH);
}
void loop() {
  x=analogRead(5);
  y=analogRead(4);
  z=analogRead(3);
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.print(z);
  if(z>=390){
    if((x>=340 || y>=340)){
      switch(flag){
        case 1:
          OFF();
          break;
        case 2:
          Red();
          break;
        case 3:
            Green();
            break;
          case 4:
            Blue();
            break;
    }
  }
    else{
      OFF();
      flag=1;
    }
  }
  else if(y>=345){
  Red();
  flag=2;
  }
  else if(x>=345){
  Green();
  flag=3;
  }
  else if(y<=280){
  Blue();
  flag=4;
  }
      Serial.print(",");
    Serial.println(flag);
  delay(100);
}
