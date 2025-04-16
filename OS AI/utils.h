#ifndef UTILS_H
#define UTILS_H

// 지정된 개수만큼 중복되지 않는 일반 로또 번호를 생성하는 함수
void generateLottoNumbers(int numbers[], int count, int maxNum);

// 일반 번호와 중복되지 않는 보너스 번호를 생성하는 함수
void generateBonusNumber(int *bonus, const int mainNumbers[], int mainCount, int maxNum);

// 일반 번호와 보너스 번호를 지정된 형식으로 출력하는 함수 (지연 효과 포함)
void displayLottoResult(const int mainNumbers[], int mainCount, int bonus);

#endif