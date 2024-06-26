// #include <IRremote.h>//IR 리모컨라이브러리.
// #define PIN_IR_RECEIVE 2
// #define PIN_MOTOR_LEFT_FORWARD 10
// #define PIN_MOTOR_LEFT_BACKWARD 9
// #define PIN_MOTOR_RIGHT_FORWARD 6
// #define PIN_MOTOR_RIGHT_BACKWARD 5
// #define PIN_LINE_DETECT_RIGHT A0
// #define PIN_LINE_DETECT_LEFT A1
// #define REF_VALUE_LINE_DETECT 200
// int motorSpeedLeft = 0; // -255~255
// int motorSpeedRight = 0; // -255~255
// int isStartLineTracing = 0;
// int detectValueLeft = 0;
// int detectValueRight = 0;

// void setup() {
//   IrReceiver.begin(PIN_IR_RECEIVE, ENABLE_LED_FEEDBACK);
//   pinMode(PIN_MOTOR_LEFT_FORWARD, OUTPUT);
//   pinMode(PIN_MOTOR_LEFT_BACKWARD, OUTPUT);
//   pinMode(PIN_MOTOR_RIGHT_FORWARD, OUTPUT);
//   pinMode(PIN_MOTOR_RIGHT_BACKWARD, OUTPUT);
//   analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
//   analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
//   analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
//   analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
// }

// void processMotor(void) {
//   if (motorSpeedLeft >= 0)     {
//     analogWrite(PIN_MOTOR_LEFT_FORWARD, motorSpeedLeft);
//     analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
//     Serial.print("motorspeedLeft: ");
//     Serial.print(motorSpeedLeft);
//   }
//   else {
//     analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
//     analogWrite(PIN_MOTOR_LEFT_BACKWARD, motorSpeedLeft * (-1));
//     Serial.print("motorspeedLeft: ");
//     Serial.print(motorSpeedLeft);
//   }
//   if (motorSpeedRight >= 0) {
//     analogWrite(PIN_MOTOR_RIGHT_FORWARD, motorSpeedRight);
//     analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
//     Serial.print("motorspeedRight: ");
//     Serial.print(motorSpeedRight);
//   }
//   else {
//     analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
//     analogWrite(PIN_MOTOR_RIGHT_BACKWARD, motorSpeedRight * (-1));
//     Serial.print("motorspeedRight: ");
//     Serial.print(motorSpeedRight);
//   }
// }

// // void processMotor(int leftSpeed, int rightSpeed) {
// //   motorSpeedLeft = constrain(leftSpeed, MOTOR_SPEED_MIN, MOTOR_SPEED_MAX);
// //   motorSpeedRight = constrain(rightSpeed, MOTOR_SPEED_MIN, MOTOR_SPEED_MAX);

// //   // 왼쪽 모터 제어
// //   if (motorSpeedLeft >= 0) {
// //     analogWrite(PIN_MOTOR_LEFT_FORWARD, motorSpeedLeft);
// //     analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
// //   } else {
// //     analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
// //     analogWrite(PIN_MOTOR_LEFT_BACKWARD, -motorSpeedLeft);
// //   }

// //   // 오른쪽 모터 제어
// //   if (motorSpeedRight >= 0) {
// //     analogWrite(PIN_MOTOR_RIGHT_FORWARD, motorSpeedRight);
// //     analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
// //   } else {
// //     analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
// //     analogWrite(PIN_MOTOR_RIGHT_BACKWARD, -motorSpeedRight);
// //   }
// // }

// void loop() {
//   if (IrReceiver.decode() == true) {
//     if (IrReceiver.decodedIRData.protocol == NEC) {
//       if (IrReceiver.decodedIRData.command == 0x16) { // *
//         isStartLineTracing = 1;
//       }
//       else if (IrReceiver.decodedIRData.command == 0x0D) { // #
//         isStartLineTracing = 0;
//       }
//     }
//     IrReceiver.resume();
//   }

//   if (isStartLineTracing == 0) {
//     motorSpeedLeft = 0;
//     motorSpeedRight = 0;
//   }
//   else {  // isStartLineTracing == 1
//     detectValueLeft = analogRead(PIN_LINE_DETECT_LEFT);
//     detectValueRight = analogRead(PIN_LINE_DETECT_RIGHT);
//     // 양쪽 센서 모두 검은색 검출 -> 직진
//     if ((detectValueLeft > REF_VALUE_LINE_DETECT) && (detectValueRight > REF_VALUE_LINE_DETECT)) { 
//       motorSpeedLeft = 154;
//       motorSpeedRight = 175;
//       //processMotor(150, 170);


//     }
//     // 오른쪽으로 벗어남 -> 왼쪽으로 틀어야 한다.
//     else if ((detectValueLeft > REF_VALUE_LINE_DETECT) && (detectValueRight < REF_VALUE_LINE_DETECT)) {
//       motorSpeedLeft = 0;
//       motorSpeedRight = 200;
//       //processMotor(-150, 150);

//     }
//     // 왼쪽으로 벗어남 -> 오른쪽으로 틀어야 한다.
//     else if ((detectValueLeft < REF_VALUE_LINE_DETECT) && (detectValueRight > REF_VALUE_LINE_DETECT)) {
//       motorSpeedLeft = 200;
//       motorSpeedRight = 0;
//       //processMotor(150, -150);

//     }
//     else {
//       motorSpeedLeft = -50;
//       motorSpeedRight = -50;
//       //processMotor(-100, -100);
  
//     }
//   }
//   processMotor();
// }


