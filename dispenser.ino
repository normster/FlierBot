#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

String input = "";
boolean read_string = false;
int state = 0;
int pos = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("foo");
  
  input.reserve(100);
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos);
  delay(5000);
}

void moveTo(int end_pos) {
  int delay_ = 2;
  if (pos < end_pos) {
    for (; pos <= end_pos; pos++) {
      myservo.write(pos);
      delay(delay_);
    }
  } else {
    for (; pos >= end_pos; pos--) {
      myservo.write(pos);
      delay(delay_);
    }
  }
}

void loop() {
  moveTo(85);
  delay(2000);
  moveTo(0);
  delay(2000);
  /*serialEvent();
  if (read_string) {
    int end_pos = input.toInt();
    Serial.print("moving to ");
    Serial.println(end_pos);
    moveTo(end_pos);
    input = "";
    read_string = false;
  }*/
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char) Serial.read();
    Serial.println(inChar);
    
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      Serial.println("read line");
      read_string = true;
    } else {
      // add it to the inputString:
      input += inChar;
    }
  }
}

