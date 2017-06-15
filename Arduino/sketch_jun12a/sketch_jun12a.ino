int RXLED=17;
void setup() {
  // put your setup code here, to run once:
pinMode(RXLED,OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:
digitalWrite(RXLED,HIGH);
TXLED1;
delay(1000);
digitalWrite(RXLED,LOW);
TXLED0;
delay(1000);
}


