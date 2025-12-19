/*
 * MPU 6050 Basic Readings
 * * This reads the accelerometer and gyroscope data from
 * the MPU 6050 and prints it to the Serial Monitor.
 */

#include <Wire.h>              // For I2C communication
#include <Adafruit_MPU6050.h>  // The sensor library
#include <Adafruit_Sensor.h>   // A dependency library

// Define your custom I2C pins
#define I2C_SDA_PIN 15
#define I2C_SCL_PIN 16

// Create an MPU 6050 sensor object
Adafruit_MPU6050 mpu;

void setup() {
  // Start the Serial Monitor (the text output window)
  Serial.begin(115200);
  while (!Serial) {
    delay(10);  // Wait for serial console to open
  }

  Serial.println("MPU 6050 Test - Custom I2C Pins");

  // 1. Initialize the I2C bus with your custom SDA and SCL pins
  
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  // 2. Initialize the MPU 6050 sensor
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip. Check wiring!");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  // Optional: Set sensor ranges (good practice)
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  Serial.println("Reading data...");
  Serial.println("---------------------------------");
}

void loop() {
  // Create variables to store the sensor data
  sensors_event_t a, g, temp;

  // Get new data from the sensor
  mpu.getEvent(&a, &g, &temp);

  //Print Accelerometer Data (for movement) 
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(" m/s^2\t");  // \t adds a tab for spacing

  Serial.print("Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(" m/s^2\t");

  Serial.print("Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  // Print Gyroscope Data (for rotation)
  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(" rad/s\t");

  Serial.print("Y: ");
  Serial.print(g.gyro.y);
  Serial.print(" rad/s\t");

  Serial.print("Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  // Add a blank line for readability
  Serial.println("");

  // Wait 500 milliseconds (half a second) before reading again
  delay(500);
}