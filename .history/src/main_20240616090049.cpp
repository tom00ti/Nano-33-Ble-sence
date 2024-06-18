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

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float x,y,z;

  if(IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(x,y,z);
  

  }

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}