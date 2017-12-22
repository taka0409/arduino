int x;
void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  x=analogRead(0);
  Serial.println(x);
  analogWrite(3,random(20,50)+x);
  delay(300);
}
