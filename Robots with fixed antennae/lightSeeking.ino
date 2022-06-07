void setup() {
//Initialise pin modes and serial
pinMode(A0, INPUT);
pinMode(A1, INPUT);

pinMode(6,OUTPUT);  // left motor
pinMode(5,OUTPUT);    // right motor
Serial.begin(9600);
}

void loop() {
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
