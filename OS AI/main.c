#include <stdio.h>
#include <stdlib.h> // srand(), rand(), system() ���
#include <time.h>   // time() ���
#include <string.h> // strcmp() ���
#include "utils.h"

#define LOTTO_COUNT 6 // ������ �Ϲ� �ζ� ��ȣ ���� (���ʽ� ����)
#define MAX_LOTTO_NUM 45 // �ζ� ��ȣ �ִ밪
#define INPUT_BUFFER_SIZE 10 // �Է� ���� ũ��

int main() {
    int lottoNumbers[LOTTO_COUNT];
    int bonusNumber; // ���ʽ� ��ȣ�� ������ ����
    char userInput[INPUT_BUFFER_SIZE]; // ����� �Է��� ������ �迭

    // ���� ������ �ʱ�ȭ (�Ź� �ٸ� ��ȣ�� �����ϱ� ����)
    srand(time(NULL));

    // �ʱ� �޽��� (�� ���� ���)
    printf("�ζ� ��ȣ ������\n");
    printf("���͸� ������ ù ��÷�� �����մϴ�...");
    getchar(); // ����ڰ� Enter�� ���� ������ ���

    do {
        system("cls"); // �ܼ� ȭ�� ����� (Windows)

        // �Ϲ� �ζ� ��ȣ 6�� ���� �Լ� ȣ��
        generateLottoNumbers(lottoNumbers, LOTTO_COUNT, MAX_LOTTO_NUM);

        // ���ʽ� ��ȣ ���� �Լ� ȣ�� (�Ϲ� ��ȣ�� �ߺ����� �ʰ�)
        generateBonusNumber(&bonusNumber, lottoNumbers, LOTTO_COUNT, MAX_LOTTO_NUM);

        // ��÷ ���� �޽��� �߰�
        printf("�ζ� ��ȣ�� ��÷�մϴ�...\n");

        // ������ �ζ� ��ȣ�� ���ʽ� ��ȣ ��� (�������̽� ȿ��)
        displayLottoResult(lottoNumbers, LOTTO_COUNT, bonusNumber);

        // �ٽ� �������� ����
        printf("\n�ٽ� �����Ϸ��� '�ٽ�'�� �Է��ϰ� Enter�� �������� (����� Enter�� ��������): ");
        fgets(userInput, INPUT_BUFFER_SIZE, stdin); // ����� �Է� �ޱ�
        userInput[strcspn(userInput, "\n")] = 0; // �Էµ� ���ڿ� ���� ���� ���� ����

    } while (strcmp(userInput, "�ٽ�") == 0); // ����ڰ� "�ٽ�"�� �Է��ߴ��� Ȯ��

    printf("���α׷��� �����մϴ�.\n");

    return 0;
}