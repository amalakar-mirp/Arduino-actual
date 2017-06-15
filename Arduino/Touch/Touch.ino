int Y1=A0;
int X1=A1;
int Y2=A2;
int X2=A3;
int x;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
pinMode(Y1,INPUT);
pinMode(Y2,OUTPUT);
digitalWrite(Y2,LOW);
pinMode(X1,OUTPUT);
digitalWrite(X1,HIGH);
pinMode(X2,OUTPUT);
digitalWrite(X2,LOW);
x=analogRead(Y1);
Serial.println(x);
delay(1000);
}
