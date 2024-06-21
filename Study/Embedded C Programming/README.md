# Embedded C Programming
> 실제 개발에 있어서 생각해야 하는 부분을 중심으로 내용 정리

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
    > 131 >> 5 는 131 / 2^5 의 값과 같다.<br/>

### 모토로라    
데이터 크기가 커졌을 때 재배열할 필요 없다.

## 조건문

## 반복문
반드시 반복문으로 코딩할 필요는 없다. 유지보수가 필요없고 수정할 일이 없다면 하드코딩도 괜찮다.

## 배열
읽는 방법
> int numArr[10] = {}

뛰어 넘는 개념

## 포인터
```C
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *numPtr;    // 포인터 변수 선언
    int num1 = 10;
    numPtr = &num1; // num1 메모리 주소를 포인터 변수에 저장
    printf("%p, %d\n", numPtr, *numPtr);
    printf("%p, %d\n", &num1, num1);
    printf("%d\n", sizeof(numPtr));
    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(char*));
    system("pause");
    return 0;
}
```
```
0061FF18, 10
0061FF18, 10
4
4
4
```
sizeof(numPtr), sizeof(int*), sizeof(char*) 값은 모두 동일하다.<br/>
&rarr; 자료형 타입이 달라도 sizeof의 출력은 동일하다.<br/>


--------  
전역변수는 빌드하면 주소 고정된다. 알아서 초기화 해준다.  

어떤 주소의 값을 알려줘. 그 값을 바꿔줘  

```C
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[10];
    // 배열을 3으로 초기화
    memset(arr, 3, sizeof(arr));

    // 초기화된 배열의 내용 출력
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```
지역변수는 함수가 실행될 때 메모리에 할당된다. 함수가 끝나면 메모리가 해제된다. 초기화가 중요<br/>
```C
#include <stdio.h>
#include <string.h>
int main()
{
    int arr[10];
    // 배열을 3으로 초기화
    memset(arr, 3, sizeof(arr));

    // 초기화된 배열의 내용 출력
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
```
```
50529027 50529027 50529027 50529027 50529027 50529027 50529027 50529027 50529027 50529027
```

배열의 자료형을 int로 바꿨을 때 결과가 다르다. memset은 바이트 단위로 초기화 하기 때문이다.

```C
#include <stdio.h>
void modifyValue(int value)
{
    int tempvalue = 10;
    value = tempvalue; // 전달된 value 값을 변경
}
int main()
{
    int num = 5;
    printf("변경 전: %d\n", num);

    modifyValue(num); // 함수에 값을 전달
    printf("변경 후: %d\n", num);
    return 0;
}
```
modifyValue 함수가 호출 될 때 stack에는 tempvalue, 매게변수, 함수가 끝나면 어디로 가야하는지 정보가 메모리에 할당된다.<br/>


