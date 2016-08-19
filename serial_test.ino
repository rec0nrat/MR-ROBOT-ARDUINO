
//char dataString[10];
//int a =0;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

#include <AFMotor.h>

AF_DCMotor motor4(4);
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);


void setup() {
  Serial.begin(9600);    //Starting serial communication
  inputString.reserve(200);
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void loop() {

  uint8_t i;
  
// print the string when a newline arrives:
  

  if(inputString == "forward"){
    motor2.setSpeed(150);
    motor1.setSpeed(150);
    motor3.setSpeed(150);
    motor4.setSpeed(150);
    motor2.run(BACKWARD);
    motor1.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    Serial.println("forward");
    inputString = "";
  }else if(inputString == "stop"){
    Serial.println("stopping");
    motor2.setSpeed(0);
    motor4.setSpeed(0);
    motor3.setSpeed(0);
    motor1.setSpeed(0);
    inputString = "";
  }else if(inputString == "left"){
    motor2.setSpeed(254);
    motor1.setSpeed(254);
    motor3.setSpeed(254);
    motor4.setSpeed(254);
    motor2.run(FORWARD);
    motor1.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    Serial.println("right");
    inputString = "";
  }else if(inputString == "right"){
    motor2.setSpeed(254);
    motor1.setSpeed(254);
    motor3.setSpeed(254);
    motor4.setSpeed(254);
    motor2.run(BACKWARD);
    motor1.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    Serial.println("left");
    inputString = "";
  }
  
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
 // a++;                          // a value increase every loop
 // sprintf(dataString,"%02X",a); // convert a value to hexa 
 // Serial.println(dataString);   // send the data
 // Serial.read
 // delay(1000);                  // give the loop some break
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
