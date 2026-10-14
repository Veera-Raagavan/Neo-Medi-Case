#include <Servo.h>

const uint8_t SERVO_PIN = 9;    // Matches app default (D9)
const long BAUD_RATE = 9600;    // Matches app serial speed
Servo servo;

String inputLine;
int currentAngle = 0;

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(currentAngle);
  Serial.begin(BAUD_RATE);
  Serial.println(F("READY SERVO:D9 BAUD:9600"));
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      handleCommand(inputLine);
      inputLine = "";
    } else {
      inputLine += c;
      if (inputLine.length() > 64) inputLine = "";
    }
  }
}
