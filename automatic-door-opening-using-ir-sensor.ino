#include <Servo.h>

Servo tap_servo;

int sensor_pin = 0;
int tap_servo_pin =10;
int led_pin = 5;
int val;

void setup()
{
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(sensor_pin);
  Serial.println(val);
  if (val==0)
  {
    tap_servo.write(0);
    digitalWrite(led_pin, HIGH);
    delay(5000);
    tap_servo.write(90);
    digitalWrite(led_pin, LOW);
  }
}