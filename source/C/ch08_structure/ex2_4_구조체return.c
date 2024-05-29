#include <stdio.h>

struct vision{
    double left;
    double right;
};

typedef struct vision Vision;    // struct vision을 Vision으로 타입으로

Vision exchange(Vision robot);

int main(void){
    Vision robot;
    printf("좌 우 시력 >> ");
    scanf("%lf %lf", &robot.left, &robot.right);
    printf("입력된 좌우 시력 : %lf\t %lf\n", robot.left, robot.right);
    robot = exchange(robot);
    printf("좌우 바뀐 시력 : %lf\t %lf\n", robot.left, robot.right);
}
Vision exchange(Vision robot){
    double temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;
    return robot;
}
