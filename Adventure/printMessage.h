#pragma once
#include <string>
#include <windows.h>
using namespace std;

class PrintMessage
{
public:
	void textColor(unsigned short color);	// 컬러 텍스트 함수 0(검은색)~15(밝은 하얀색)까지 입력
	void printOpening();					// 오프닝. 구현예정
	void printIntro();
	void bossAppears();
	void displayEpitaph(string name);
	void printCongratulations();
	void gotoXY(int X, int Y);				// 메세지 출력 위치 지정을 위한 커서 위치 지정 함수
	int getcursorlocationY();				// 프레임 출력 후 같은 줄에 내용 출력을 위해 커서 좌표 따오는 함수
	void askName();							// 캐릭터 생성과정 1. 이름 입력
	void afterName(string name);			// 캐릭터 생성과정 2. 초기 스탯 표시
	void printUpperFrame();
	void printLowerFrame();
	void printFrame();						// 프레임 중간부분 출력하는 함수
};