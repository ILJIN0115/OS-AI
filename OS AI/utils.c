#include <stdio.h>
#include <stdlib.h> // rand() ���
#include <time.h>   // nanosleep() �Ǵ� Sleep() ����� ���� �ʿ��� �� ����
#include "utils.h"

// Windows ȯ���� ���� ��� �� �Լ�
#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(ms) Sleep(ms)
// POSIX (Linux, macOS ��) ȯ���� ���� ��� �� �Լ�
#else
#include <unistd.h> // usleep() ����� ����
#define SLEEP_MS(ms) usleep(ms * 1000)
#endif

// �Ϲ� �ζ� ��ȣ ���� (������ ����)
void generateLottoNumbers(int numbers[], int count, int maxNum) {
    int i, j, newNum;
    int isDuplicate;

    for (i = 0; i < count; i++) {
        do {
            isDuplicate = 0;
            newNum = rand() % maxNum + 1;
            for (j = 0; j < i; j++) {
                if (numbers[j] == newNum) {
                    isDuplicate = 1;
                    break;
                }
            }
        } while (isDuplicate);
        numbers[i] = newNum;
    }
}

// ���ʽ� ��ȣ ���� �Լ�
void generateBonusNumber(int *bonus, const int mainNumbers[], int mainCount, int maxNum) {
    int newNum;
    int isDuplicate;
    do {
        isDuplicate = 0;
        newNum = rand() % maxNum + 1; // 1���� maxNum ������ ���� ����
        // �Ϲ� ��ȣ��� �ߺ��Ǵ��� Ȯ��
        for (int i = 0; i < mainCount; i++) {
            if (mainNumbers[i] == newNum) {
                isDuplicate = 1; // �ߺ� �߰�
                break;
            }
        }
    } while (isDuplicate); // �ߺ����� ���� ������ �ݺ�
    *bonus = newNum; // �ߺ����� �ʴ� ��ȣ�� �����͸� ���� ����
}


// �������̽� ȿ���� �����Ͽ� ��� ��� �Լ�
void displayLottoResult(const int mainNumbers[], int mainCount, int bonus) {
    printf("��÷�� ��ȣ: ");
    // �ʱ� �ڸ� ǥ���� ��� (�Ϲ� 6�� + ���ʽ� 1��)
    for (int i = 0; i < mainCount; i++) {
        printf("[__] ");
    }
    printf("+ [__]"); // ���ʽ� ��ȣ �ڸ� ǥ����
    fflush(stdout);

    // �Ϲ� ��ȣ�� �ϳ��� ä���ִ� ȿ��
    for (int i = 0; i < mainCount; i++) {
        SLEEP_MS(700); // �� ���� �̴� �ð� ���� (���� ����)
        printf("\r��÷�� ��ȣ: ");
        for (int j = 0; j < mainCount; j++) {
            if (j <= i) {
                printf("[%2d] ", mainNumbers[j]);
            } else {
                printf("[__] ");
            }
        }
        printf("+ [__]"); // ���ʽ� ��ȣ�� ���� ǥ�� �� ��
        fflush(stdout);
    }

    // ���ʽ� ��ȣ�� ä���ִ� ȿ��
    SLEEP_MS(700); // ���ʽ� ��ȣ �̴� �ð� ����
    printf("\r��÷�� ��ȣ: ");
    for (int j = 0; j < mainCount; j++) {
        printf("[%2d] ", mainNumbers[j]);
    }
    printf("+ [%2d]", bonus); // ���ʽ� ��ȣ ǥ��
    fflush(stdout);

    printf("\n"); // ���� �� �ٲ�
}

// ���� ȿ���� �߰��� displayNumbersWithDelay �Լ�
void displayNumbersWithDelay(const int numbers[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
        fflush(stdout); // ���۸� ��� ���ڰ� ��� ���̵��� ��
        SLEEP_MS(500); // 500 �и��� (0.5��) ���, �ʿ信 ���� ����
    }
    printf("\n");
}