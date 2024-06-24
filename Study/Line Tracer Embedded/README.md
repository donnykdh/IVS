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

|Input||Motor A Output|
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

## Line Tracer








