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
