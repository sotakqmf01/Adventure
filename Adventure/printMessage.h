#pragma once
#include <string>
#include <windows.h>
using namespace std;

class PrintMessage
{
public:
	void textColor(unsigned short color);	// �÷� �ؽ�Ʈ �Լ� 0(������)~15(���� �Ͼ��)���� �Է�
	void printIntro();
	void bossAppears();
	void displayEpitaph(string name);
};