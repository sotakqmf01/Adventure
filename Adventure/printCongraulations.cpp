#pragma execution_character_set("utf-8")
#include "printCongratulations.h"
#include "GenerateRandomNumber.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;


void PrintCongratulations::gotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int PrintCongratulations::getcursorlocationY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int cursorY = csbi.dwCursorPosition.Y;
    return cursorY;
}


void PrintCongratulations::textColor(unsigned short color)	// 컬러 텍스트 함수 0(검은색)~15(밝은 하얀색)까지 입력
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

void PrintCongratulations::printFrame()
{
    int randomframe = generateRandomNumber(0, 3);

    switch (randomframe)
    {
    case 0:
        textColor(6);
        cout << "          |       |                                                                                     |       |";
        textColor(7);
        gotoXY(26, getcursorlocationY());
        break;
    case 1:
        textColor(6);
        cout << "          >       |                                                                                     <       |";
        textColor(7);
        gotoXY(26, getcursorlocationY());
        break;
    case 2:
        textColor(6);
        cout << "          |       S                                                                                     |       |";
        textColor(7);
        gotoXY(26, getcursorlocationY());
        break;
    case 3:
        textColor(6);
        cout << "          >       |                                                                                     |       <";
        textColor(7);
        gotoXY(26, getcursorlocationY());
        break;
    }
}

void PrintCongratulations::printCongratulations()
{
    UINT OriginCP = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    printFrame();
    cout << endl;
    printFrame();
    cout << endl;
   
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣿⣿⣿⣿⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣶⡾⠿⠟⠛⠉⠁⠀⠀⠀⠉⠙⠻⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⣾⠿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⠿⠟⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⣢⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⣀⣠⣤⠶⠟⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠴⠿⢭⣯⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⢀⡟⡇" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⢀⣤⢾⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⢀⣴⣿⠇⡇" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⢠⡟⠁⠉⠉⠙⠲⢦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⢀⣤⡾⢋⡵⠃⢠⠇" << endl; textColor(6); 
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⣾⠀⢠⠞⢛⠷⣦⡀⠉⠻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⡄⠀⠀⠀⠀⠀"; textColor(9); cout << "⣀⣴⠾⠋⢁⡴⠋⠀⣠⡟⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⢿⡀⠘⣖⣈⡷⢸⡧⠀⠀⠘⢿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣷⡀⠀"; textColor(9); cout << "⣠⣴⠟⠋⠀⢀⡴⠋⠀⣠⡾⠋⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠘⢷⣄⠈⠉⢀⣾⣧⣴⠶⠚⠉⢹⣦⠀⠀⣀⣀⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⣩⣵⠟⠋⠀⠀⢀⡴⠋⠀⢠⣾⠏⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠈⠉⠛⠛⠋⠉⠁⠀⠀⠀⠀⠈⢻⣯⠝⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⣾⠟⠁⠀⠀⢀⣴⠏⠀⠀⢠⡾⠁⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢹⣦⠖⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⢀⠀⣼⡏⠀⠀⠀⣠⡟⠁⠀⠀⠀⣾⠃⠀⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⣴⡟⠀⢿⡇⠀⠀⣼⠏⢀⣀⣤⣤⣴⣿⠀⠀⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⢀⡜⢿⣇⠀⠸⡇⢀⣼⠃⠀⠀⠈⠳⣶⡴⠁⠀⠀⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⠹⣄⣉⣓⣦⣝⣾⠃⠀⢀⣀⣤⠾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⣩⠟⡋⣽⢿⡦⢭⣭⠭⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⠘⠁⠈⢹⡟⠀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⢀⣿⠇⠤⢚⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl; textColor(6);
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⣸⣿⠀⠀⠀"; textColor(6); cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⠹⣿⠀⠀⠀"; textColor(6); cout << "⠸⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"; textColor(9); cout << "⢻⠀⠀⠀⠀"; textColor(6); cout << "⢙⡤⠤⠈⠙⠳⢤⡀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠴⠒⠋⠁⠀⠀⠀⠀⠀⠈⢿⡆⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠼⢷⣶⠖⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠶⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠇⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⠿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣶⠾⠛⠁⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⣀⣠⣤⣶⡿⠟⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⠶⠚⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⢠⣼⣿⣯⣟⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⡴⠖⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡀⠀⡟⢡⢥⡈⠹⣧⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⡶⠞⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⡄⢻⣌⣠⡟⠀⣿⠂⠀⢀⣀⣤⣴⠶⠟⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   printFrame(); textColor(6);  gotoXY(30, getcursorlocationY()); cout << "⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⢿⣦⣌⣁⣀⣼⢯⣴⠶⢛⠋⠉ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    textColor(15);
    gotoXY(42, 6); cout << "혜성처럼 나타나 세계를 구원해주신";
    gotoXY(44, 7); cout << "모험가님께 감사드립니다.";
    //gotoXY(44, 8); cout << "내가 이겼다";
    gotoXY(44, 9); cout << "은혜를 갚고자 이 세상에 남아주시길 바랐지만";
    gotoXY(44, 10); cout << "그 어떤 보상도 마다하시니";
    gotoXY(44, 13); cout << "저희는 그저 모험가님을 마음깊이 기리는 수밖에 없네요.";
    gotoXY(44, 14); cout << "영원히 잊지 않겠습니다.";
    gotoXY(44, 16); cout << "지구라는 곳으로 돌아가셔도..";
    gotoXY(44, 17); cout << "가끔은 이 곳에서의 기억을 떠올려 주세요!";
    gotoXY(0, 29);
    SetConsoleOutputCP(OriginCP);
    SetConsoleCP(OriginCP);
    _getch();
}