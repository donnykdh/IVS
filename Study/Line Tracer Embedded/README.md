# Line Tracer를 통한 차량용 임베디드 시스템의 이해


## Index

1.	[Embedded Arduino](#Arduino)

2.	[연산자](#연산자)

3.  [조건문](#조건문)

4.  [반복문](#반복문)

5.  [배열](#배열)

6.  [포인터](#포인터)
## Embedded Arduino
### Flash
```Arduino
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

```Arduino
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

```Arduino
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









