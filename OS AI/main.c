#include <stdio.h>
#include <stdlib.h> // srand(), rand(), system() 사용
#include <time.h>   // time() 사용
#include <string.h> // strcmp() 사용
#include "utils.h"

#define LOTTO_COUNT 6 // 생성할 일반 로또 번호 개수 (보너스 제외)
#define MAX_LOTTO_NUM 45 // 로또 번호 최대값
#define INPUT_BUFFER_SIZE 10 // 입력 버퍼 크기

int main() {
    int lottoNumbers[LOTTO_COUNT];
    int bonusNumber; // 보너스 번호를 저장할 변수
    char userInput[INPUT_BUFFER_SIZE]; // 사용자 입력을 저장할 배열

    // 난수 생성기 초기화 (매번 다른 번호를 생성하기 위해)
    srand(time(NULL));

    // 초기 메시지 (한 번만 출력)
    printf("로또 번호 생성기\n");
    printf("엔터를 누르면 첫 추첨을 시작합니다...");
    getchar(); // 사용자가 Enter를 누를 때까지 대기

    do {
        system("cls"); // 콘솔 화면 지우기 (Windows)

        // 일반 로또 번호 6개 생성 함수 호출
        generateLottoNumbers(lottoNumbers, LOTTO_COUNT, MAX_LOTTO_NUM);

        // 보너스 번호 생성 함수 호출 (일반 번호와 중복되지 않게)
        generateBonusNumber(&bonusNumber, lottoNumbers, LOTTO_COUNT, MAX_LOTTO_NUM);

        // 추첨 시작 메시지 추가
        printf("로또 번호를 추첨합니다...\n");

        // 생성된 로또 번호와 보너스 번호 출력 (인터페이스 효과)
        displayLottoResult(lottoNumbers, LOTTO_COUNT, bonusNumber);

        // 다시 생성할지 묻기
        printf("\n다시 생성하려면 '다시'를 입력하고 Enter를 누르세요 (종료는 Enter만 누르세요): ");
        fgets(userInput, INPUT_BUFFER_SIZE, stdin); // 사용자 입력 받기
        userInput[strcspn(userInput, "\n")] = 0; // 입력된 문자열 끝의 개행 문자 제거

    } while (strcmp(userInput, "다시") == 0); // 사용자가 "다시"를 입력했는지 확인

    printf("프로그램을 종료합니다.\n");

    return 0;
}