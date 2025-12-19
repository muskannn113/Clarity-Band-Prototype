#include <Wire.h>
#include <SparkFun_Bio_Sensor_Hub_Library.h>



// 1. The I2C Data Pins (From Qwiic Cable)
//    Blue Wire -> Pin 8
//    Yellow Wire -> Pin 18
const int sdaPin = 15;
const int sclPin = 16;

// 2. The Control Pins (The two extra wires)

const int resPin = 13;  
const int mfioPin = 14;  


// Create the sensor object
SparkFun_Bio_Sensor_Hub bioHub(resPin, mfioPin);
bioData body;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for Serial Monitor to open

  Serial.println("Initializing Pulse Oximeter...");

  // Start the I2C bus on specific pins
  Wire.begin(sdaPin, sclPin);

  // Initialize the Sensor
 
  int result = bioHub.begin();

  if (result == 0)  //
    Serial.println("Sensor Started Successfully!");
  else {
    Serial.println("Could not start sensor.");
    Serial.println("Check: 1. Are RST/MFIO pins correct?");
    Serial.println("       2. Are Blue/Yellow wires swapped?");
    while (1)
      ;  
  }

  // Configuring the sensor to give Heart Rate & Oxygen
  Serial.println("Configuring Sensor...");
  int error = bioHub.configBpm(MODE_ONE);  // MODE_ONE = Heart Rate & SpO2

  if (error == 0) {
    Serial.println("Sensor Configured. Put your finger on the sensor.");
  } else {
    Serial.println("Configuration Failed.");
  }
}

void loop() {
  // Only read data if the sensor has a new measurement ready
  // (This handles the timing automatically)
  body = bioHub.readBpm();

  // If the sensor detects a finger and valid data
  if (body.heartRate > 0) {
    Serial.print("Heart Rate: ");
    Serial.print(body.heartRate);
    Serial.print(" BPM  |  Oxygen (SpO2): ");
    Serial.print(body.oxygen);
    Serial.println(" %");
  } else {
    // If no finger is detected or it's still calculating
    Serial.println("Status: No finger / Calculating...");
  }

  delay(250);  
}