#include <SoftwareSerial.h>

// Set up SoftwareSerial for HC-05 Bluetooth module
SoftwareSerial bluetooth(10, 11); // RX = 10, TX = 11

// Define LED pins
int led1 = 5;
int led2 = 6;
int led3 = 7;

// Track when LEDs were turned on
unsigned long led1OnTime = 0;
unsigned long led2OnTime = 0;
unsigned long led3OnTime = 0;

// Define the duration for the LEDs to stay on (20 seconds = 20000 milliseconds)
const unsigned long ledDuration = 20000;

void setup() {
  // Initialize the LEDs as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Start serial communication for debugging
  Serial.begin(9600);

  // Start serial communication with the Bluetooth module
  bluetooth.begin(9600);

  // Initial state of LEDs (all off)
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  // Check if data is available from the Bluetooth module
  if (bluetooth.available()) {
    // Read the incoming data
    char receivedChar = bluetooth.read();

    // Print received data for debugging purposes
    Serial.println(receivedChar);

    // Control LEDs based on the received character
    switch(receivedChar) {
      case '5': // Turn on 1st LED
        digitalWrite(led1, HIGH);
        led1OnTime = millis();  // Record the time when the 1st LED was turned on
        bluetooth.println("1st light ON");
        break;
      case '1': // Turn off 1st LED
        digitalWrite(led1, LOW);
        bluetooth.println("1st light OFF");
        break;
      case '6': // Turn on 2nd LED
        digitalWrite(led2, HIGH);
        led2OnTime = millis();  // Record the time when the 2nd LED was turned on
        bluetooth.println("2nd light ON");
        break;
      case '2': // Turn off 2nd LED
        digitalWrite(led2, LOW);
        bluetooth.println("2nd light OFF");
        break;
      case '7': // Turn on 3rd LED
        digitalWrite(led3, HIGH);
        led3OnTime = millis();  // Record the time when the 3rd LED was turned on
        bluetooth.println("3rd light ON");
        break;
      case '3': // Turn off 3rd LED
        digitalWrite(led3, LOW);
        bluetooth.println("3rd light OFF");
        break;
      case '9': // Turn on all LEDs
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        led1OnTime = millis();  // Record the time when all LEDs were turned on
        led2OnTime = millis();
        led3OnTime = millis();
        bluetooth.println("All lights ON");
        break;
      case '0': // Turn off all LEDs
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        bluetooth.println("All lights OFF");
        break;
      default:
        bluetooth.println("Invalid command");
        break;
    }
  }

  // Automatically turn off LEDs after 20 seconds if they are on
  if (digitalRead(led1) == HIGH && (millis() - led1OnTime >= ledDuration)) {
    digitalWrite(led1, LOW);
    bluetooth.println("1st light OFF (auto)");
  }
  
  if (digitalRead(led2) == HIGH && (millis() - led2OnTime >= ledDuration)) {
    digitalWrite(led2, LOW);
    bluetooth.println("2nd light OFF (auto)");
  }
  
  if (digitalRead(led3) == HIGH && (millis() - led3OnTime >= ledDuration)) {
    digitalWrite(led3, LOW);
    bluetooth.println("3rd light OFF (auto)");
  }
}
