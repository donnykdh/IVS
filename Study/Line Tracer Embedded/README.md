# Line Tracer를 통한 차량용 임베디드 시스템의 이해


## Index

1.	[Embedded Arduino](#Arduino)

2.	[Assemble Cooling Fan](#assemble-cooling-fan)

3.  [Line Tracer](#line-tracer)


## Embedded Arduino
### Flash
```cpp
 intcount = 0;
 // the setup function runs once when you press reset or power the board
 voidsetup() {
 Serial.begin(115200);
 pinMode(LED_BUILTIN, OUTPUT);
 }
 // the loop function runs over and over again forever
 voidloop() {
 Serial.print("HelloWorld:");
 Serial.println(count++);
 digitalWrite(LED_BUILTIN, HIGH);
 delay(1000);
 digitalWrite(LED_BUILTIN, LOW);
 delay(100);
 }
```
다음 예제 코드를 아래 과정으로 파일을 이동시킨 뒤 cmd창에 명령어를 입력하면 바로 보드에 올려 실행시킬 수 있다.
<p align="center"><img src="/Study/images/flash.png" width="100%" height="100%"></p>

```
Flash>avrdude–C avrdude.conf-v-patmega328p -carduino–PCOM5-b115200 -D -Uflash:w:HelloWorld.ino.standard.hex:i
```
### ADC
<p align="center"><img src="/Study/images/adc.png" width="40%" height="40%"></p>

```cpp
void setup() {
 Serial.begin(115200);
 }
 void loop() {
 int switchGreen = analogRead(A0);
 int switchYellow = analogRead(A1);
 Serial.print("Green:");
 Serial.print(switchGreen);
 Serial.print(", Yellow:");
 Serial.println(switchYellow);
 delay(1000);
 }
 ```
 위 코드를 실행시켰을 때 다음과 같은 결과가 나오는 것을 확인할 수 있다.
 ```
 Green:1023, Yellow:689
 Green:1023, Yellow:806
 Green:1023, Yellow:869
 Green:1023, Yellow:0
 Green:1023, Yellow:701
 Green:1023, Yellow:273
 ```
 스위치를 누르면 전압과 그라운드가 쇼트되어 값이 0이 된다. Green 스위치의 값은 항상 1023인데 Yellow 스위치의 값은 일정하지 않다.
 #### analogRead()
 지정한 아날로그 핀에서 값을 읽는다. 0에서 5V 사이의 입력 전압을 0에서 1024사이의 정수 값으로 대응시키는 것을 의미한다. 해상도는 5V/1024 (4.9mV) 이다.<br/>
 실제 현업에서 사용하는 보드는 보통 12bit로 좀 더 정밀한 조절이 가능하다.
 
 ### Pull-Up & Pull-Down 저항 

 <p align="center"><img src="/Study/images/pull_up_down.png" width="100%" height="100%"></p>

 <div align="center">

||풀업 저항 상태|풀다운 저항 상태|
|:-----------------------------------:|:-------------:|:-------------:|
|스위치 off|HIGH(1)|LOW(0)|
|스위치 on|LOW(0)|HIGH(1)|

</div>
사용하지 않는 핀은 풀다운 시켜줘서 노이즈, 정전기 방지를 해줘야 한다.

### switch

<p align="center"><img src="/Study/images/switch.png" width="40%" height="40%"></p>

```cpp
void setup() {
 pinMode(8, INPUT);
 pinMode(7, INPUT);
 pinMode(6, INPUT);
 pinMode(5, INPUT);
 pinMode(4, INPUT);
 Serial.begin(115200);
 }
 void loop() {
 int switchGreen= digitalRead(8);
 int switchYellow= digitalRead(7);
 int switchRed= digitalRead(6);
 int switchBlack= digitalRead(5);
 int switchBlue= digitalRead(4);
 Serial.print("Green:");
 Serial.print(switchGreen);
 Serial.print(", Yellow:");
 Serial.print(switchYellow);
 Serial.print(", Red:");
 Serial.print(switchRed);
 Serial.print(", Black:");
 Serial.print(switchBlack);
 Serial.print(", Blue:");
 Serial.println(switchBlue);
 delay(1000);
 }
 ```
 위 코드를 실행시키고 스위치를 하나씩 누르고 있으면 결과는 다음과 같다.
 ```
 Green:1, Yellow:1, Red:1, Black:1, Blue:1
 Green:0, Yellow:1, Red:1, Black:1, Blue:1
 Green:1, Yellow:0, Red:1, Black:1, Blue:1
 Green:1, Yellow:1, Red:0, Black:1, Blue:1
 Green:1, Yellow:1, Red:1, Black:0, Blue:1
 Green:1, Yellow:1, Red:1, Black:1, Blue:0
 ```

 ### Motor

<p align="center">
<img src="/Study/images/motor.png" width="40%" height="40%">
<img src="/Study/images/motor2.jpg" width="30%" height="30%">
</p>

<div align="center">

|Input|Input|Motor A Output|
|:----------:|:-------------:|:-------------:|
|1A|1B||
|L|L|Off|
|H|L|Forward|
|L|H|Reverse|
|H|H|Off

</div>
1A와 1B에 입력을 서로 다르게하여 모터의 방향을 바꿀 수 있다.

> Green Switch : 10씩 Fan 제어량을 증가시킨다.<br/>
> Yellow Switch : 10씩 Fan 제어량을 감소시킨다.
```cpp
#definePIN_MOTOR_CTRL_0 3
#definePIN_MOTOR_CTRL_1 11
#definePIN_SWITCH_GREEN 8
#definePIN_SWITCH_YELLOW7

int prevSwitchGreen = HIGH;
int prevSwitchYellow = HIGH;
byte motorCtrlValue0 = 0;

voidsetup() {
    pinMode(PIN_SWITCH_GREEN, INPUT);
    pinMode(PIN_SWITCH_YELLOW, INPUT);
    pinMode(PIN_MOTOR_CTRL_0, OUTPUT);
    pinMode(PIN_MOTOR_CTRL_1, OUTPUT);
    analogWrite(PIN_MOTOR_CTRL_0, 0);
    analogWrite(PIN_MOTOR_CTRL_1, 0);
    Serial.begin(115200);
}
voidloop() {
    int currentSwitchGreen= digitalRead(PIN_SWITCH_GREEN);
    int currentSwitchYellow= digitalRead(PIN_SWITCH_YELLOW);
    if ((prevSwitchGreen== LOW) && (currentSwitchGreen== HIGH))
    {
        motorCtrlValue0 = (motorCtrlValue0 < 245) ? (motorCtrlValue0 + 10) : 255;
        analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
        analogWrite(PIN_MOTOR_CTRL_1, 0);
        Serial.println(motorCtrlValue0);
    }
    if ((prevSwitchYellow== LOW) && (currentSwitchYellow== HIGH))
    {
        motorCtrlValue0 = (motorCtrlValue0 > 10) ? (motorCtrlValue0 -10) : 0;
        analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
        analogWrite(PIN_MOTOR_CTRL_1, 0);
        Serial.println(motorCtrlValue0);
    }
    prevSwitchGreen= currentSwitchGreen;
    prevSwitchYellow= currentSwitchYellow;
    delay(100);
}
```

### Capacitor
* Capacitor란 콘덴서 축전지라고도 불리는 소자로 전기를 일시적으로 저장한다.
* Capacitor가 없다면 서보 모터가 아두이노의 최대 전류 용량보다 많은 전류를 소모할 경우 아두이노 보드가 비정상 동작 할 수 있다. Capacitor는 +, -극이 정해져 있다.

### PWM

## Assemble Cooling Fan
### Motor Type
전기에너지를 기계에너지로 바꾸는 동력기계장치
* DC모터
* 서보모터
  * attach()
    > servoRotate.attach(13);<br/>
    > 13번 핀으로 모터를 제어한다
  * write()
    > servoRotate.write(90);<br/>
    > 서보모터를 90도로 동작 (최대 180도까지 가능)

<br/>

<p align="center">
<img src="/Study/images/fan.jpg" width="30%" height="30%">
</p>


Cooling Fan 예제 코드

```cpp
#include <Servo.h>  // 서보모터 라이브러리
#define PIN_MOTOR_CTRL_0 3
#define PIN_MOTOR_CTRL_1 11
#define PIN_SWITCH_GREEN 8
#define PIN_SWITCH_YELLOW 7
#define PIN_SWITCH_RED 6
#define PIN_SWITCH_BLACK 5
#define PIN_SWITCH_BLUE 4
#define PIN_SERVO_CTRL 13   // 서보 컨트롤 핀
int prevSwitchGreen = HIGH;
int prevSwitchYellow = HIGH;
int prevSwitchRed = HIGH;
int prevSwitchBlack = HIGH;
int prevSwitchBlue = HIGH;
byte motorCtrlValue0;
byte servoPosition = 90;    // 90도(전방) 초기화
Servo servoRotate;  // 객체 생성
```
```cpp
void setup() {
  servoRotate.attach(PIN_SERVO_CTRL);
  servoRotate.write(servoPosition);
  pinMode(PIN_SWITCH_GREEN, INPUT);
  pinMode(PIN_SWITCH_YELLOW, INPUT);
  pinMode(PIN_SWITCH_RED, INPUT);
  pinMode(PIN_SWITCH_BLACK, INPUT);
  pinMode(PIN_SWITCH_BLUE, INPUT);
  pinMode(PIN_MOTOR_CTRL_0, OUTPUT);
  pinMode(PIN_MOTOR_CTRL_1, OUTPUT);
  pinMode(PIN_SERVO_CTRL, OUTPUT);
  analogWrite(PIN_MOTOR_CTRL_0, 0);
  analogWrite(PIN_MOTOR_CTRL_1, 0);
  Serial.begin(115200);
}
```
```cpp
void loop() {
  // Fan Control
  int currentSwitchGreen = digitalRead(PIN_SWITCH_GREEN);
  int currentSwitchYellow = digitalRead(PIN_SWITCH_YELLOW);
  int currentSwitchRed = digitalRead(PIN_SWITCH_RED);
  if ((prevSwitchGreen == LOW) && (currentSwitchGreen == HIGH)) {
    motorCtrlValue0 = (motorCtrlValue0 < 245) ? (motorCtrlValue0 + 10) : 255;
    analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
    Serial.println(motorCtrlValue0);
  }
  if ((prevSwitchYellow == LOW) && (currentSwitchYellow == HIGH)) {
    motorCtrlValue0 = (motorCtrlValue0 > 10) ? (motorCtrlValue0 - 10) : 0;
    analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
    Serial.println(motorCtrlValue0);
  }
  if ((prevSwitchRed == LOW) && (currentSwitchRed == HIGH)) {
    motorCtrlValue0 = 0;
    analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
    Serial.println(motorCtrlValue0);
    servoPosition = 90;
    servoRotate.write(servoPosition);
    Serial.println(servoPosition);
  }
  prevSwitchGreen = currentSwitchGreen;
  prevSwitchYellow = currentSwitchYellow;
  prevSwitchRed = currentSwitchRed;

  // Rotate Control
  int currentSwitchBlack = digitalRead(PIN_SWITCH_BLACK);
  int currentSwitchBlue = digitalRead(PIN_SWITCH_BLUE);
  if ((prevSwitchBlack == LOW) && (currentSwitchBlack == HIGH)) {
    servoPosition = (servoPosition < 170) ? (servoPosition + 10) : 180;
    servoRotate.write(servoPosition);
    Serial.println(servoPosition);
  }
  if ((prevSwitchBlue == LOW) && (currentSwitchBlue == HIGH)) {
    servoPosition = (servoPosition > 10) ? (servoPosition - 10) : 0;
    servoRotate.write(servoPosition);
    Serial.println(servoPosition);
  }
  prevSwitchBlack = currentSwitchBlack;
  prevSwitchBlue = currentSwitchBlue;
  delay(100);
}
```
Cooling Fan 연습문제
```
1.초록색버튼:최대속도의50%로Fan 회전.(제어량과회전속도는비례한다고가정)
2.노란색버튼: 최대속도로Fan 회전.
3.빨간색버튼: Fan 회전정지.
4.검정색버튼: Fan 목의회전을멈추고정면(90도, 나를바라보는방향)을바라본다.
5.파란색버튼: Fan 목이30~150도사이에서연속적으로회전한다.(30도, 150도도달시Fan 목회전방향전환)
※ 제약: Servo 의position 설정시servoRotate.read()의return값을변수copy 없이 즉시전달인자로활용해야한다.
( servoRotate.write(ServoRotate.read()) )
```
```cpp
#include <Servo.h>
#define PIN_MOTOR_CTRL_0 3
#define PIN_MOTOR_CTRL_1 11
#define PIN_SWITCH_GREEN 8
#define PIN_SWITCH_YELLOW 7
#define PIN_SWITCH_RED 6
#define PIN_SWITCH_BLACK 5
#define PIN_SWITCH_BLUE 4
#define PIN_SERVO_CTRL 13
int prevSwitchGreen = HIGH;
int prevSwitchYellow = HIGH;
int prevSwitchRed = HIGH;
int prevSwitchBlack = HIGH;
int prevSwitchBlue = HIGH;
byte motorCtrlValue0;
byte servoPosition = 90;
int rotateFlag = 0;
Servo servoRotate;
```
```cpp
void setup() {
  servoRotate.attach(PIN_SERVO_CTRL);
  servoRotate.write(servoPosition);
  pinMode(PIN_SWITCH_GREEN, INPUT);
  pinMode(PIN_SWITCH_YELLOW, INPUT);
  pinMode(PIN_SWITCH_RED, INPUT);
  pinMode(PIN_SWITCH_BLACK, INPUT);
  pinMode(PIN_SWITCH_BLUE, INPUT);
  pinMode(PIN_MOTOR_CTRL_0, OUTPUT);
  pinMode(PIN_MOTOR_CTRL_1, OUTPUT);
  pinMode(PIN_SERVO_CTRL, OUTPUT);
  analogWrite(PIN_MOTOR_CTRL_0, 0);
  analogWrite(PIN_MOTOR_CTRL_1, 0);
  Serial.begin(115200);
}
```
```cpp
void loop() {
  // Fan Control
  int currentSwitchGreen = digitalRead(PIN_SWITCH_GREEN);
  int currentSwitchYellow = digitalRead(PIN_SWITCH_YELLOW);
  int currentSwitchRed = digitalRead(PIN_SWITCH_RED);
  if ((prevSwitchGreen == LOW) && (currentSwitchGreen == HIGH)) {
    motorCtrlValue0 = 127;  // 최대 속도의 50프로
    analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
    Serial.println(motorCtrlValue0);
  }
  if ((prevSwitchYellow == LOW) && (currentSwitchYellow == HIGH)) {
    motorCtrlValue0 = 255;  // 최대 속도
    analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
    Serial.println(motorCtrlValue0);
  }
  if ((prevSwitchRed == LOW) && (currentSwitchRed == HIGH)) {
    motorCtrlValue0 = 0;  // 정지
    analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
    Serial.println(motorCtrlValue0);
  }
  prevSwitchGreen = currentSwitchGreen;
  prevSwitchYellow = currentSwitchYellow;
  prevSwitchRed = currentSwitchRed;

  // Rotate Control
  int currentSwitchBlack = digitalRead(PIN_SWITCH_BLACK);
  int currentSwitchBlue = digitalRead(PIN_SWITCH_BLUE);
  
  if ((prevSwitchBlack == LOW) && (currentSwitchBlack == HIGH)) {
    rotateFlag = 0;
    servoPosition = 90;
    servoRotate.write(servoPosition);
    Serial.println(servoPosition);
  }
  if ((prevSwitchBlue == LOW) && (currentSwitchBlue == HIGH)) {
    rotateFlag = 1;
  }
  if ((servoRotate.read() < 30) || (servoRotate.read() > 150)) {
    rotateFlag = rotateFlag * (-1);
  }
  if (rotateFlag != 0) {
    servoRotate.write(servoRotate.read() + rotateFlag);
  }
  prevSwitchBlack = currentSwitchBlack;
  prevSwitchBlue = currentSwitchBlue;
  delay(100);
}
```
### Interrupt
* 아두이노 우노에서 2번, 3번 핀 사용 가능하다.
* `attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);`
* 사용할 pin
* ISP: 서비스 루틴 이름(함수 이름)
* mode: 어떤 트리거가 발생할 때 인터럽트를 실행할지<br/>

위 코드에서 `#define pin_SWITCH_BLACK 2`로 바꿔 주고 `isrSwitchBlack()`함수를 추가 해주고 main함수에서 인터럽트를 걸어준다.

```cpp
void isrSwitchBlack(){
    rotateFlag = 0;
    servoRotate.write(90);
}
```
```cpp
void setup() {
  attachInterrupt(digitalPinToInterrupt(PIN_SWITCH_BLACK), isrSwitchBlack, RISING);
```
loop 한번을 실행하는데 걸리는 시간 측정하기
```cpp
int taskStartTime = 0;
int taskEndTime = 0;

void loop(){
    taskStartTime = micros();
    .
    .
    .
    taskEndTime = micros();
    Serial.println("execution time is " + (String)(taskEndTime - TtaskStartTime) + "[us]");
}
``` 
```time = micros()```

* Task 총 실행시간은 80% 이하여야 한다.
* Stack 최대 사용률은 70% 이하여야 한다.

### EEPROM
꺼졌다 켜져도 정보가 지워지지 않고 남아 있다.
> #include <EEprom.h>

`EEPROM.read(0);`

0번주소에 저장된 값을 읽겠다. 하나의 주소에 한 바이트 값 저장 가능<br/>

`EEPROM.write(0, EEPROM.read(0) + 1);`

0번 주소에 EEPROM.read(0)값에 1을 더하여 저장한다.

> 리셋버튼 -> loop함수에서 setup함수로 간다.

### Endian
* Big-endian
* Little-endian

## Line Tracer
### Voltage
```map(adcInput, 0, 1023, 0, 5000);```

adcInput을 0~1023에서 0~5000으로 확장 시킨다.

#### 전압 분배
아두이노의 pin의 입력은 5V를 초과하면 안된다.

### IrRemote







