#pragma once
#include <string>
#include <windows.h>
using namespace std;

class PrintMessage
{
public:
	void textColor(unsigned short color);	// 컬러 텍스트 함수 0(검은색)~15(밝은 하얀색)까지 입력
	void printIntro();
	void bossAppears();
	void displayEpitaph(string name);
};