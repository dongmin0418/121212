#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 25

// 좌표를 나타내는 구조체
typedef struct {
    double x;
    double y;
} Point;

// 점을 회전시키는 함수
Point rotatePoint(Point p, double angle) {
    Point rotated;
    double radian = angle * (PI / 180.0); // 각도를 라디안으로 변환
    rotated.x = p.x * cos(radian) - p.y * sin(radian);
    rotated.y = p.x * sin(radian) + p.y * cos(radian);
    return rotated;
}

// 직선 A, B, C를 그리는 함수
void drawLines() {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

    // 화면 초기화
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }

    // 직선 A 그리기
    int lengthA = 3;
    for (int i = 0; i < lengthA; i++) {
        int x = i;  // x 좌표
        int y = 0;  // y 좌표 (0,0에서 시작)
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            screen[y][x] = 'A'; // 직선 A 출력
        }
    }

    // 직선 B 그리기 (반시계 방향 30도 회전)
    int lengthB = 6;
    double angleB = 30.0; // 직선 B의 회전 각도
    Point startPointB = { lengthA - 1, 0 }; // A 끝점
    Point endPointB = startPointB; // B의 끝점 계산

    for (int i = 1; i <= lengthB; i++) {
        Point p = { startPointB.x + i, startPointB.y };
        Point rotated = rotatePoint((Point) { p.x - startPointB.x, p.y - startPointB.y }, angleB);
        rotated.x += startPointB.x;
        rotated.y += startPointB.y;

        int x = (int)(rotated.x + 0.5);
        int y = (int)(rotated.y + 0.5);
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            screen[y][x] = 'B'; // 직선 B 출력
        }

        if (i == lengthB) { // B의 끝점 저장
            endPointB = rotated;
        }
    }

    // 직선 C 그리기 (B 끝점에서 추가로 30도 회전)
    int lengthC = 9;
    double angleC = 30.0; // 직선 C의 회전 각도
    Point startPointC = endPointB; // C의 시작점

    for (int i = 1; i <= lengthC; i++) {
        Point p = { startPointC.x + i, startPointC.y };
        Point rotated = rotatePoint((Point) { p.x - startPointC.x, p.y - startPointC.y }, angleC);
        rotated.x += startPointC.x;
        rotated.y += startPointC.y;

        int x = (int)(rotated.x + 0.5);
        int y = (int)(rotated.y + 0.5);
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            screen[y][x] = 'C'; // 직선 C 출력
        }
    }

    // 화면 출력
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

int main() {
    drawLines();
    return 0;
}
