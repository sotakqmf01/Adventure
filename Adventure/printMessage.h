#pragma once
#include <string>
#include <windows.h>
#include "Character.h"

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
	void printUpperFrame();					// 프레임 상단부분 출력. 게임 시작할 때 한 번만 호출.
	void printLowerFrame();					// 프레임 하단부분 출력. 게임 종료될 때 한 번만 호출.
	void printFrame();						// 프레임 중간부분 출력하는 함수. 출력이 있을 때마다 같이 출력해야함.
	void printShopRoof();
	void cursorView(char c);				// 커서 깜빡임: c=0이면 안보임, c=1이면 보임

};