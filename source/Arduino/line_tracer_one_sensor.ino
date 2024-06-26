#include <IRremote.h>
#define PIN_IR_RECEIVE 2
#define PIN_MOTOR_LEFT_FORWARD 10
#define PIN_MOTOR_LEFT_BACKWARD 9
#define PIN_MOTOR_RIGHT_FORWARD 6
#define PIN_MOTOR_RIGHT_BACKWARD 5
#define PIN_LINE_DETECT_LEFT A1
#define REF_VALUE_LINE_DETECT 300
int motorSpeedLeft = 0;  // -255~255
int motorSpeedRight = 0; // -255~255
int isStartLineTracing = 0;
int detectValueLeft = 0;
int detectValueRight = 0;

int preState = 0;

void setup()
{
  IrReceiver.begin(PIN_IR_RECEIVE, ENABLE_LED_FEEDBACK);
  pinMode(PIN_MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_FORWARD, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_BACKWARD, OUTPUT);
  analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
  analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
  analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
  analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
}

void processMotor(void)
{
  if (motorSpeedLeft >= 0)
  {
    analogWrite(PIN_MOTOR_LEFT_FORWARD, motorSpeedLeft);
    analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
  }
  else
  {
    analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
    analogWrite(PIN_MOTOR_LEFT_BACKWARD, motorSpeedLeft * (-1));
  }
  if (motorSpeedRight >= 0)
  {
    analogWrite(PIN_MOTOR_RIGHT_FORWARD, motorSpeedRight);
    analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
  }
  else 
  {
    analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
    analogWrite(PIN_MOTOR_RIGHT_BACKWARD, motorSpeedRight * (-1));
  }
}

void loop()
{
  if (IrReceiver.decode() == true)
  {
    if (IrReceiver.decodedIRData.protocol == NEC)
    {
      if (IrReceiver.decodedIRData.command == 0x16)
      { 
        isStartLineTracing = 1;
      }
      else if (IrReceiver.decodedIRData.command == 0x0D)
      { 
        isStartLineTracing = 0;
      }
    }
    IrReceiver.resume();
  }

  if (isStartLineTracing == 0)
  {
    motorSpeedLeft = 0;
    motorSpeedRight = 0;
  }
  else
  { // isStartLineTracing == 1
    detectValueLeft = analogRead(PIN_LINE_DETECT_LEFT);
    if (detectValueLeft >= REF_VALUE_LINE_DETECT)
    {
      motorSpeedLeft = 195;
      motorSpeedRight = 235;
      // processMotor(150, 170);
      preState = 0;
    }
    // 오른쪽으로 벗어남 -> 왼쪽으로 틀어야 한다.
    else if (detectValueLeft < REF_VALUE_LINE_DETECT)
    {
      motorSpeedLeft = -30;
      motorSpeedRight = 200;
      preState = 1;
    }
    
  }
  processMotor();
}



