/**********************************************************************

  motor4 ------- motor3
           ||
           ||
           ||
  motor1 ------- motor2

**********************************************************************/

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
//Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

Adafruit_DCMotor *motor1 = AFMS.getMotor(1);//define motor1
Adafruit_DCMotor *motor2 = AFMS.getMotor(2);//define motor2
Adafruit_DCMotor *motor3 = AFMS.getMotor(3);//define motor3
Adafruit_DCMotor *motor4 = AFMS.getMotor(4);//define motor4

const char buttonpin = 8;
bool pressed = false;

void setup() {
  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    while (1);
  }

  // Set the speed to start, from 0 (off) to 255 (max speed)
  //myMotor->setSpeed(150);
  //myMotor->run(FORWARD);
  // turn on motor
  //myMotor->run(RELEASE);


  //Set initial speed of the motor & stop
  motor1->setSpeed(255);//setup the speed of motor1
  motor2->setSpeed(255);//setup the speed of motor2
  motor3->setSpeed(255);//setup the speed of motor3
  motor4->setSpeed(255);//setup the speed of motor4

  Serial.begin(9600);
  pinMode(buttonpin, INPUT_PULLUP);

}
void foward(){
  motor1->run(BACKWARD);
  motor2->run(FORWARD);
  motor3->run(BACKWARD);
  motor4->run(FORWARD);
}
void backward(){
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(FORWARD);
  motor4->run(BACKWARD);
}
void goleft(){
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD);
}
void goright(){
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}
void turnleft(){
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD);
}
void turnright(){
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}
void leftfoward(){
  motor1->run(BACKWARD);
  motor2->run(RELEASE);
  motor3->run(BACKWARD);
  motor4->run(RELEASE);
}
void rightfoward(){
  motor1->run(RELEASE);
  motor2->run(FORWARD);
  motor3->run(RELEASE);
  motor4->run(FORWARD);
}
void leftbackward(){
  motor1->run(RELEASE);
  motor2->run(BACKWARD);
  motor3->run(RELEASE);
  motor4->run(BACKWARD);
}
void rightbackward(){
  motor1->run(FORWARD);
  motor2->run(RELEASE);
  motor3->run(FORWARD);
  motor4->run(RELEASE);
}
void stop(){
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  motor3->run(RELEASE);
  motor4->run(RELEASE);
}

// void testrun(){
//   delay(1500);
//   foward();
//   delay(1500);
//   backward();
//   delay(1500);
//   goleft();
//   delay(1500);
//   goright();
//   delay(1500);
//   turnleft();
//   delay(1500);
//   turnright();
//   delay(1500);
//   leftfoward();
//   delay(1500);
//   rightbackward();
//   delay(1500);
//   rightfoward();
//   delay(1500);
//   rightbackward();
//   delay(10000);
// }



void Perform(){
  // perform things

  stop();
}





void loop() {
  bool currentstate = digitalRead(buttonpin);
  if(currentstate==pressed){
    Perform();
    delay(200);
    while(digitalRead(buttonpin)){
    }
  }
}
