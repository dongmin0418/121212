#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 25

// ��ǥ�� ��Ÿ���� ����ü
typedef struct {
    double x;
    double y;
} Point;

// ���� ȸ����Ű�� �Լ�
Point rotatePoint(Point p, double angle) {
    Point rotated;
    double radian = angle * (PI / 180.0); // ������ �������� ��ȯ
    rotated.x = p.x * cos(radian) - p.y * sin(radian);
    rotated.y = p.x * sin(radian) + p.y * cos(radian);
    return rotated;
}

// ���� A, B, C�� �׸��� �Լ�
void drawLines() {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

    // ȭ�� �ʱ�ȭ
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }

    // ���� A �׸���
    int lengthA = 3;
    for (int i = 0; i < lengthA; i++) {
        int x = i;  // x ��ǥ
        int y = 0;  // y ��ǥ (0,0���� ����)
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            screen[y][x] = 'A'; // ���� A ���
        }
    }

    // ���� B �׸��� (�ݽð� ���� 30�� ȸ��)
    int lengthB = 6;
    double angleB = 30.0; // ���� B�� ȸ�� ����
    Point startPointB = { lengthA - 1, 0 }; // A ����
    Point endPointB = startPointB; // B�� ���� ���

    for (int i = 1; i <= lengthB; i++) {
        Point p = { startPointB.x + i, startPointB.y };
        Point rotated = rotatePoint((Point) { p.x - startPointB.x, p.y - startPointB.y }, angleB);
        rotated.x += startPointB.x;
        rotated.y += startPointB.y;

        int x = (int)(rotated.x + 0.5);
        int y = (int)(rotated.y + 0.5);
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            screen[y][x] = 'B'; // ���� B ���
        }

        if (i == lengthB) { // B�� ���� ����
            endPointB = rotated;
        }
    }

    // ���� C �׸��� (B �������� �߰��� 30�� ȸ��)
    int lengthC = 9;
    double angleC = 30.0; // ���� C�� ȸ�� ����
    Point startPointC = endPointB; // C�� ������

    for (int i = 1; i <= lengthC; i++) {
        Point p = { startPointC.x + i, startPointC.y };
        Point rotated = rotatePoint((Point) { p.x - startPointC.x, p.y - startPointC.y }, angleC);
        rotated.x += startPointC.x;
        rotated.y += startPointC.y;

        int x = (int)(rotated.x + 0.5);
        int y = (int)(rotated.y + 0.5);
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
            screen[y][x] = 'C'; // ���� C ���
        }
    }

    // ȭ�� ���
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
