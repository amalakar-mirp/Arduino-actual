//libraries
#include <Servo.h>
#include <TouchScreen.h>
#include <PID_v1.h>

int yServoPin=2;
int xServoPin=3;
Servo ServoX,ServoY;
int min1=70, max1=110;

double inputX, outputX;
double inputY, outputY;
double setpointX=512, setpointY=560;
double Kp=0.1, Ki=0.04, Kd=0.04;
PID myPID1(&inputX,&outputX,&setpointX,Kp,Ki,Kd,REVERSE);
PID myPID2(&inputY,&outputY,&setpointY,Kp,Ki,Kd,REVERSE);


int Y1=A0;
int X1=A1;
int Y2=A2;
int X2=A3;
TouchScreen ts=TouchScreen(X1,Y1,X2,Y2,711);


void setup() {
 
//Serial.begin(9600); 
  
  
  // put your setup code here, to run once:
ServoX.attach(xServoPin);
ServoY.attach(yServoPin);
ServoX.write(90);
ServoY.write(90);
myPID1.SetOutputLimits(min1,max1);
myPID1.SetMode(AUTOMATIC);
myPID1.SetSampleTime(15);
myPID2.SetOutputLimits(min1,max1);
myPID2.SetMode(AUTOMATIC);
myPID2.SetSampleTime(15);

}

void loop() {
  // put your main code here, to run repeatedly:
TSPoint p=ts.getPoint();
int x=(p.x);
int y=(p.y);
inputX=x;
inputY=y;
/*Serial.print(x);
Serial.print(", ");
Serial.print(y);
Serial.println();*/
if (p.z>ts.pressureThreshhold) {
  myPID1.Compute();
  myPID2.Compute();
  ServoX.write(outputX);
  ServoY.write(outputY);

}
//delay(3000);
}
