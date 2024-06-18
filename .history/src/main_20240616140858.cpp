#include <Arduino.h>
#include <Arduino_LSM9DS1.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

// blink test
  pinMode(LED_BUILTIN,OUTPUT);

//Serial setting  
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");
  if(!IMU.begin())
  {
    Serial.println("Failed to Initialize IMU!");
    while(1);
  }

// pirnt gyro setting
  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("GyroX\tGyroY\tGyroZ");

// print Acceleration setting
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("AccX\tAccY\tAccZ");

// print Magnetic field setting
  Serial.print("Magnetic field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("MagX\tMagY\tMagZ");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float GyroX,GyroY,GyroZ;
  float AccX,AccY,AccZ;
  float MagX,MagY,MagZ;

  if(IMU.gyroscopeAvailable())
  {
    IMU.readGyroscope(GyroX,GyroY,GyroZ);
    
/*  //serial print
    Serial.print(GyroX);
    Serial.print('\t');
    Serial.print(GyroY);
    Serial.print('\t');
    Serial.println(GyroZ);
 */

    // for teleplot setting
    Serial.print(">GyroX:");
    Serial.println(GyroX);
    Serial.print(">GyroY:");
    Serial.println(GyroY);
    Serial.print(">GyroZ:");
    Serial.println(GyroZ);

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(AccX, AccY, AccZ);

    Serial.print(">AccX:");
    Serial.println(AccX);
    Serial.print(">AccY:");
    Serial.println(AccY);
    Serial.print(">AccZ:");
    Serial.println(AccZ);
  }
  
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(MagX, MagY, MagZ);

    Serial.print(">MagX:");
    Serial.println(MagX);
    Serial.print(">MagY:");
    Serial.println(MagY);
    Serial.print(">MagZ:");
    Serial.println(MagZ);
  }
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);

  }

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}