/*
 * Clarity Band - Sensor Test
 * Component: Seeed Studio Grove GSR Sensor
 * Wiring: Yellow Wire -> GPIO 5
 */

// Define the pin where the yellow wire is connected
const int gsrPin = 5;

void setup() {
  // Start the serial monitor
  Serial.begin(115200);
  
  // Tell the ESP32 that Pin 5 is an INPUT 
  pinMode(gsrPin, INPUT);
  
  Serial.println("--- Starting GSR Sensor Test ---");
  Serial.println("Relax your hand and watch the values.");
}

void loop() {
  // GSR sensors are very sensitive the values can jump around 
  // due to tiny movements or electrical noise.
  // To fix this, we take 10 quick snapshots and average them out.
  
  long sum = 0;
  for(int i=0; i<10; i++) {
    // Read the voltage coming from the Yellow Wire
    sum += analogRead(gsrPin); 
    
    // Wait a tiny bit (5ms) between reads to let the signal settle
    delay(5); 
  }
  
  // Calculate the average to get a smooth, stable number
  int averageValue = sum / 10;
  
  // Print the value to the Serial Monitor.
  // I'm using the format "Label:Value" so the Serial Plotter can draw a graph.
  // High Number usually means Lower Resistance (More Sweat/Stress).
  Serial.print("Skin_Response:");
  Serial.println(averageValue);
  
  // Wait a short moment before the next loop so we don't flood the screen
  delay(100); 
}