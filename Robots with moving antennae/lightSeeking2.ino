#include <Servo.h>

Servo myservo1;
Servo myservo2;

int pos = 90;

void setup() {

myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
myservo2.attach(10);
//Initialise pin modes and serial
pinMode(A0, INPUT);
pinMode(A1, INPUT);

pinMode(6,OUTPUT);  // left motor
pinMode(5,OUTPUT);    // right motor
Serial.begin(9600);
}

void loop() {

for(double x=-PI;x<PI;x+=(2*PI/100))
  {
    delay(1000/100);
    int outPWM1 = 75 + (sin(x-1.5*PI) + 1) * 20;   // range of outPWM1 is 75-115
    int outPWM2 = 75 + (sin(x-PI/2) + 1)*20;  // range of outPWM2 is 75-115, outPWM2 is PI/2 out of phase with outPWM1
    myservo1.write(outPWM1);
    myservo2.write(outPWM2);
  }

  for(double x=PI;x>-PI;x-=(2*PI/100))
  {
    delay(1000/100);
    int outPWM1 = 75 + (sin(x-1.5*PI) + 1) * 20;   // range of outPWM1 is 75-115
    int outPWM2 = 75 + (sin(x-PI/2) + 1)*20;  // range of outPWM2 is 75-115, outPWM2 is PI out of phase with outPWM1
    myservo1.write(outPWM1);
    myservo2.write(outPWM2);
  }
 
//Read both input voltages
int VA0 = analogRead(A0);
int VA1 = analogRead(A1);
//Write ADC values to serial
Serial.print(VA0);   // VA0(left) is between 0 and 1015
Serial.write(' ');
Serial.println(VA1);
if((VA0-VA1)>2)
{
  analogWrite(6,100);
  analogWrite(5,200);
}
else if((VA1-VA0)>2)
{
  analogWrite(5,100);//VA1*255/1023
  analogWrite(6,200);
}
else
{
  analogWrite(5,0);
  analogWrite(6,0);
}
//Pause before next calculation
delay(100);
}
