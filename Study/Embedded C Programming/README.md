# Embedded C Programming
> 실제 개발에 있어서 생각해야 하는 부분은 중심으로 내용 정리

## Index

1.	[자료형](#자료형)

2.	[연산자](#연산자)

3.  [조건문](#조건문)

4.  [반복문](#반복문)

5.  [배열](#배열)

6.  [포인터](#포인터)
## 자료형
```C
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    char num1 = -10;
    // 1바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    short num2 = 30000;
    // 2바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    int num3 = -1234567890;
    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long num4 = 1234567890;
    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long long num5 = -1234567890123456789;
    // 8바이트 부호 있는 정수형으로 변수를 선언하고 값 할당

   // char, short, int는 %d로 출력하고 long은 %ld, long long은 %lld로 출력
    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);

    return 0;
}
```
변수를 선언할 때 자료형만 선언하지 않고 크기와 부호의 유무까지 선언한다.

```C
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>    // 크기별로 정수 자료형이 정의된 헤더 파일
int main() {
    int8_t num1 = -128;                    // 8비트(1바이트) 크기의 부호 있는 정수형 변수 선언
    int16_t num2 = 32767;                  // 16비트(2바이트) 크기의 부호 있는 정수형 변수 선언 
    int32_t num3 = 2147483647;             // 32비트(4바이트) 크기의 부호 있는 정수형 변수 선언
    int64_t num4 = 9223372036854775807;    // 64비트(8바이트) 크기의 부호 있는 정수형 변수 선언
    // int8_t, int16_t, int32_t는 %d로 출력하고 int64_t는 %lld로 출력
    printf("%d %d %d %lld\n", num1, num2, num3, num4); 

    uint8_t num5 = 200;                      // 8비트(1바이트) 크기의 부호 없는 정수형 변수 선언
    uint16_t num6 = 60000;                   // 16비트(2바이트) 크기의 부호 없는 정수형 변수 선언
    uint32_t num7 = 4123456789;              // 32비트(4바이트) 크기의 부호 없는 정수형 변수 선언
    uint64_t num8 = 1234567890123456789;    // 64비트(8바이트) 크기의 부호 없는 정수형 변수 선언
    // uint8_t, uint16_t, uint32_t는 %u로 출력하고 uint64_t는 %llu로 출력
    printf("%u %u %u %llu\n", num5, num6, num7, num8); 
    return 0;
}
```

<div align="center">

|자료형|32 bit OS|64 bit OS|
|:-----------------------------------:|:-------------:|:-------------:|
|int|32 bit|32 bit|
|short|16 bit|16 bit|
|long|32 bit|${\textsf{\color{red}64 bit}}$|
|long long|64 bit|${\textsf{\color{red}64 bit}}$|
|pointer(*)|32 bit|${\textsf{\color{red}64 bit}}$|
</div>
위와 같이 OS가 다르면 비트 수가 다르기 때문에 자료형과 크기를 반드시 함께 선언해준다.

## 연산자
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    printf("num++ : %d\n", num++);
    printf("num : %d\n", num);
    printf("num-- : %d\n", num--);
    printf("num : %d\n", num);
    printf("++num : %d\n", ++num);
    printf("--num : %d\n", --num);
    system("pause");
}
```
```
num++ : 0
num : 1
num-- : 1
num : 0
++num : 1
--num : 0
```
무조건 1을 증가 시켜야 한다면 후위 연산은 <ins>(1) num을 전달</ins>하고, <ins>(2) 증가</ins>시키기 때문에 `전위 연산`이 효율적이다.

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    printf("++ : %d, --: %d\n", num++, num--);  // 값이 정확하게 일정하지 않다.
    return 0;
}
```
같은 줄에 num++, num--를 쓰게 되면 어떤 것이 먼저 실행될지 모른다. 컴파일러마다 다르기 때문에 한 줄에 같이 쓰지 않는다.

### Bit Shift
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char num1 = 131;    //  131: 1000 0011
    char num2 = -125;            // -125: 1000 0011
    printf("%u\n", num1 >> 5);
    printf("%d\n", num2 >> 5);

    return 0;
}
```
```
4
-4
```
* -125의 2의 보수는 1000 0011이고 오른쪽으로 5 쉬프트될 때 **빈자리는 1로 채워진다.** signed integer이므로 최상위 비트인 1로 채워진다.<br/>
* 비트 쉬프트로 곱셈과 나눗셈을 대신할 수 있다.
    > 131 >> 5 는 131 / 2^5 의 값과 같다.


## 포인터
