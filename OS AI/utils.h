#ifndef UTILS_H
#define UTILS_H

// ������ ������ŭ �ߺ����� �ʴ� �Ϲ� �ζ� ��ȣ�� �����ϴ� �Լ�
void generateLottoNumbers(int numbers[], int count, int maxNum);

// �Ϲ� ��ȣ�� �ߺ����� �ʴ� ���ʽ� ��ȣ�� �����ϴ� �Լ�
void generateBonusNumber(int *bonus, const int mainNumbers[], int mainCount, int maxNum);

// �Ϲ� ��ȣ�� ���ʽ� ��ȣ�� ������ �������� ����ϴ� �Լ� (���� ȿ�� ����)
void displayLottoResult(const int mainNumbers[], int mainCount, int bonus);

#endif