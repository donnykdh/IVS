#include <stdio.h>

int main(void) {
	char name[100], gender[3];
	int korean, english, math;
	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, (unsigned)sizeof(name));
	printf("성별을 입력하세요 (남/여) : ");
	scanf_s("%s", gender, (unsigned)sizeof(gender));
	printf("국어 영어 수학 점수를 입력하세요 : ");
	scanf_s("%d %d %d", &korean, &english, &math);

	printf("---학생정보---\n");
	printf("이름 : %s\n", name);
	printf("성별 : %s\n", gender);
	printf("국어 = %d\n", korean);
	printf("영어 = %d\n", english);
	printf("수학 = %d\n", math);
	printf("합계 = %d\n", korean + english + math);
	printf("평균 = %.2lf\n", (korean+english+math)/3.0);
}

