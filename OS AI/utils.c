#include <stdio.h>
#include <stdlib.h> // rand() 사용
#include <time.h>   // nanosleep() 또는 Sleep() 사용을 위해 필요할 수 있음
#include "utils.h"

// Windows 환경을 위한 헤더 및 함수
#ifdef _WIN32
#include <windows.h>
#define SLEEP_MS(ms) Sleep(ms)
// POSIX (Linux, macOS 등) 환경을 위한 헤더 및 함수
#else
#include <unistd.h> // usleep() 사용을 위해
#define SLEEP_MS(ms) usleep(ms * 1000)
#endif

// 일반 로또 번호 생성 (기존과 동일)
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

// 보너스 번호 생성 함수
void generateBonusNumber(int *bonus, const int mainNumbers[], int mainCount, int maxNum) {
    int newNum;
    int isDuplicate;
    do {
        isDuplicate = 0;
        newNum = rand() % maxNum + 1; // 1부터 maxNum 사이의 난수 생성
        // 일반 번호들과 중복되는지 확인
        for (int i = 0; i < mainCount; i++) {
            if (mainNumbers[i] == newNum) {
                isDuplicate = 1; // 중복 발견
                break;
            }
        }
    } while (isDuplicate); // 중복되지 않을 때까지 반복
    *bonus = newNum; // 중복되지 않는 번호를 포인터를 통해 저장
}


// 인터페이스 효과를 포함하여 결과 출력 함수
void displayLottoResult(const int mainNumbers[], int mainCount, int bonus) {
    printf("추첨된 번호: ");
    // 초기 자리 표시자 출력 (일반 6개 + 보너스 1개)
    for (int i = 0; i < mainCount; i++) {
        printf("[__] ");
    }
    printf("+ [__]"); // 보너스 번호 자리 표시자
    fflush(stdout);

    // 일반 번호를 하나씩 채워넣는 효과
    for (int i = 0; i < mainCount; i++) {
        SLEEP_MS(700); // 각 숫자 뽑는 시간 간격 (조절 가능)
        printf("\r추첨된 번호: ");
        for (int j = 0; j < mainCount; j++) {
            if (j <= i) {
                printf("[%2d] ", mainNumbers[j]);
            } else {
                printf("[__] ");
            }
        }
        printf("+ [__]"); // 보너스 번호는 아직 표시 안 함
        fflush(stdout);
    }

    // 보너스 번호를 채워넣는 효과
    SLEEP_MS(700); // 보너스 번호 뽑는 시간 간격
    printf("\r추첨된 번호: ");
    for (int j = 0; j < mainCount; j++) {
        printf("[%2d] ", mainNumbers[j]);
    }
    printf("+ [%2d]", bonus); // 보너스 번호 표시
    fflush(stdout);

    printf("\n"); // 최종 줄 바꿈
}

// 지연 효과를 추가한 displayNumbersWithDelay 함수
void displayNumbersWithDelay(const int numbers[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
        fflush(stdout); // 버퍼를 비워 숫자가 즉시 보이도록 함
        SLEEP_MS(500); // 500 밀리초 (0.5초) 대기, 필요에 따라 조절
    }
    printf("\n");
}