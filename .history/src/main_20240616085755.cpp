#include <Arduino.h>
#include <Arduino_LSM9DS1.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if(!IMU.begin())
  {
    Serial.println("Failed to Initialize IMU!");
    while(1);
  }
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}