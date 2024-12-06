#include <stdio.h>
#include <math.h>

void check_response(double m, double c, double k) {
    double omega_n; // 고유 진동수
    double zeta;    // 감쇠비

    if (m <= 0) {
        printf("질량 m은 0보다 커야 합니다.\n");
        return;
    }
    if (k <= 0) {
        printf("스프링 상수 k는 0보다 커야 합니다.\n");
        return;
    }

    // 고유 진동수 계산
    omega_n = sqrt(k / m);

    // 감쇠비 계산
    zeta = c / (2 * sqrt(m * k));

    // 안정성 판단
    printf("==============================================\n");
    printf("고유 진동수(rad/s): %.2f\n", omega_n);
    printf("감쇠비: %.2f\n", zeta);

    if (zeta > 1) {
        printf("시스템은 과감쇠 상태(overdamped)입니다. 안정적입니다.\n");
    } else if (zeta == 1) {
        printf("시스템은 임계감쇠 상태(critically damped)입니다.\n");
    } else if (zeta > 0 && zeta < 1) {
        printf("시스템은 언더댐핑 상태(underdamped)입니다.\n");
    } else if (zeta == 0) {
        printf("시스템은 비감쇠 상태(undamped)입니다.\n");
    } else {
        printf("시스템은 발산합니다. (zeta < 0)\n");
    }
    printf("==============================================\n");
}

int main() {
    double m, c, k;

    printf("질량 m(kg) 값을 입력하세요: ");
    scanf("%lf", &m);

    printf("댐핑계수 c(Ns/m) 값을 입력하세요: ");
    scanf("%lf", &c);

    printf("스프링 상수 k(N/m) 값을 입력하세요: ");
    scanf("%lf", &k);

    // 응답 양상 확인 함수 호출
    check_response(m, c, k);

    return 0;
}
