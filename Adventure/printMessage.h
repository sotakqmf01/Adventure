#pragma once
#include <string>
#include <windows.h>
using namespace std;

class PrintMessage
{
public:
	void textColor(unsigned short color);	// �÷� �ؽ�Ʈ �Լ� 0(������)~15(���� �Ͼ��)���� �Է�
	void printOpening();					// ������. ��������
	void printIntro();
	void bossAppears();
	void displayEpitaph(string name);
	void printCongratulations();
	void gotoXY(int X, int Y);				// �޼��� ��� ��ġ ������ ���� Ŀ�� ��ġ ���� �Լ�
	int getcursorlocationY();				// ������ ��� �� ���� �ٿ� ���� ����� ���� Ŀ�� ��ǥ ������ �Լ�
	void askName();							// ĳ���� �������� 1. �̸� �Է�
	void afterName(string name);			// ĳ���� �������� 2. �ʱ� ���� ǥ��
	void printUpperFrame();
	void printLowerFrame();
	void printFrame();						// ������ �߰��κ� ����ϴ� �Լ�
};