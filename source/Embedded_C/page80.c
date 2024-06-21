#include <stdio.h>
void modifyValue(int *value)
{
    int tempvalue = 10;

    //const temp = 10;
    //temp = 20;
    *value = tempvalue; // 포인터를 통해 값을 변경
}
int main()
{
    const int num = 5; // 값 변경을 막는다.
    printf("변경 전: %d\n", num);

    modifyValue(&num); // 함수에 포인터를 전달
    printf("변경 후: %d\n", num);
    return 0;
}
// 주소로 접근하면 const여도 값이 변경된다.