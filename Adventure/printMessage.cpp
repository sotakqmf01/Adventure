﻿#include "printMessage.h"
#include "Character.h"
#include "GenerateRandomNumber.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

void PrintMessage::gotoXY(int x, int y) 
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int PrintMessage::getcursorlocationY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int cursorY = csbi.dwCursorPosition.Y;
    return cursorY;
}


void PrintMessage::textColor(unsigned short color)	// 컬러 텍스트 함수 0(검은색)~15(밝은 하얀색)까지 입력
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

void PrintMessage::printOpening()
{
    // 구현예정
}

void PrintMessage::askName()
{
    system("cls");
    textColor(6);
    gotoXY(43, 6);
    cout << "   ______________________________" << endl;
    gotoXY(43, 7);
    cout << " / \\                             \\." << endl;
    gotoXY(43, 8);
    cout << "|   |                            |." << endl;
    gotoXY(43, 9);
    cout << " \\_/|                            |." << endl;
    gotoXY(43, 10);
    cout << "    |     ";
    textColor(7);    
    cout << "환영합니다.";
    textColor(6);
    cout << "            |." << endl;
    gotoXY(43, 11);
    cout << "    |     ";
    textColor(7);
    cout << "모험가님.";
    textColor(6); 
    cout << "              |." << endl;
    gotoXY(43, 12);
    cout << "    |                            |." << endl;
    gotoXY(43, 13);
    cout << "    |     "; 
    textColor(7); 
    cout << "모험가님의 이름은";
    textColor(6);    
    cout << "      |." << endl;
    gotoXY(43, 14);
    cout << "    |     ";
    textColor(7); 
    cout << "무엇입니까?";
    textColor(6);    
    cout << "            |." << endl;
    
    gotoXY(43, 15);
    cout << "    |                            |." << endl;
    gotoXY(43, 16);
    cout << "    |     ";
    textColor(15);    
    cout << "__________________"; 
    textColor(6);
    cout << "     |." << endl;
    gotoXY(43, 17);
    cout << "    |                            |." << endl;
    gotoXY(43, 18);
    cout << "    |                            |." << endl;
    gotoXY(43, 19);
    cout << "    |                            |." << endl;
    gotoXY(43, 20);
    cout << "    |                            |." << endl;
    gotoXY(43, 21);
    cout << "    |                            |." << endl;
    gotoXY(43, 22);
    cout << "    |   _________________________|__" << endl;
    gotoXY(43, 23);
    cout << "    |  /                           /." << endl;
    gotoXY(43, 24);
    cout << "    \\_/___________________________/." << endl;
    textColor(7);
    gotoXY(53,16); // 이름 입력칸 좌표 (53, 16) 로 커서 갖다놓기
}
void PrintMessage::afterName(string name)
{
    Character* player = Character::getInstance(name);
    cursorView(0);
    if (name == "창민")
    {
        for (int i = 10; i <= 16; i++)
        {
            gotoXY(53, i);
            cout << "                       ";
            Sleep(100);
        }
        cursorView(1);
        gotoXY(53, 10);
        textColor(7);
        cout << "돌아오셨군요!";
        gotoXY(53, 11);
        cout << player->getName() << ".";
        Sleep(1500);
        gotoXY(53, 13);
        cout << "당신의 능력치입니다.";
        Sleep(1000);
        gotoXY(53, 15);
        cout << "레벨: ";
        gotoXY(61, 15);
        cout << player->getLevel();
        Sleep(800);
        gotoXY(53, 16);
        cout << "체력: 200/200";
        Sleep(800);
        gotoXY(53, 17);
        cout << "골드: ";
        gotoXY(61, 17);
        cout << player->getGold();
        Sleep(800);
        gotoXY(53, 18);
        cout << "대미지: ";
        gotoXY(63, 18);
        cout << player->getAttack();
        Sleep(800);
        gotoXY(53, 19);
        cout << "경험치: 0/100";
        Sleep(800);
        gotoXY(55, 21);
        cout << "행운을 빕니다!";
        Sleep(2000);
        system("cls");
    }
    else
    {
        for (int i = 10; i <= 16; i++)
        {
            gotoXY(53, i);
            cout << "                       ";
            Sleep(100);
        }
        cursorView(1);
        gotoXY(53, 10);
        textColor(7);
        cout << "반갑습니다.";
        gotoXY(53, 11);
        cout << player->getName() << ".";
        Sleep(1500);
        gotoXY(53, 13);
        cout << "당신의 능력치입니다.";
        Sleep(1000);
        gotoXY(53, 15);
        cout << "레벨: ";
        gotoXY(61, 15);
        cout << player->getLevel();
        Sleep(800);
        gotoXY(53, 16);
        cout << "체력: 200/200";
        Sleep(800);
        gotoXY(53, 17);
        cout << "골드: ";
        gotoXY(61, 17);
        cout << player->getGold();
        Sleep(800);
        gotoXY(53, 18);
        cout << "대미지: ";
        gotoXY(63, 18);
        cout << player->getAttack();
        Sleep(800);
        gotoXY(53, 19);
        cout << "경험치: 0/100";
        Sleep(800);
        gotoXY(55, 21);
        cout << "행운을 빕니다!";
        Sleep(2000);
        system("cls");
    }

}
void PrintMessage::printIntro()
{   
    cursorView(0);
    gotoXY(2, 8);
	textColor(12);
	cout << "_________";
	textColor(7);
	cout << " ______     __    ______     ";
	textColor(9);
	cout << "_______  ______            _______  _       _________          _______  _______ " << endl;
    gotoXY(2, 9);
	textColor(12);
	cout << "\\__   __/";
	textColor(7);
	cout << "(  __  \\   /__\\  (  __  \\   ";
	textColor(9);
	cout << "(  ___  )(  __  \\ |\\     /|(  ____ \\( (    /|\\__   __/|\\     /|(  ____ )(  ____ \\" << endl;
    gotoXY(2, 10);
	textColor(12);
	cout << "   ) (   ";
	textColor(7);
	cout << "| (  \\  ) ( \\/ ) | (  \\  )  ";
	textColor(9);
	cout << "| (   ) || (  \\  )| )   ( || (    \\/|  \\  ( |   ) (   | )   ( || (    )|| (    \\/" << endl;
    gotoXY(2, 11);
	textColor(12);
	cout << "   | |   ";
	textColor(7);
	cout << "| |   ) |  \\  /  | |   ) |  ";
	textColor(9);
	cout << "| (___) || |   ) || |   | || (__    |   \\ | |   | |   | |   | || (____)|| (__    " << endl;
    gotoXY(2, 12);
	textColor(12);
	cout << "   | |   ";
	textColor(7);
	cout << "| |   | |  /  \\/\\| |   | |  ";
	textColor(9);
	cout << "|  ___  || |   | |( (   ) )|  __)   | (\\ \\) |   | |   | |   | ||     __)|  __)   " << endl;
    gotoXY(2, 13);
	textColor(12);
	cout << "   | |   ";
	textColor(7);
	cout << "| |   ) | / /\\  /| |   ) |  ";
	textColor(9);
	cout << "| (   ) || |   ) | \\ \\_/ / | (      | | \\   |   | |   | |   | || (\\ (   | (      " << endl;
    gotoXY(2, 14);
	textColor(12);
	cout << "   | |   ";
	textColor(7);
	cout << "| (__/  )(  \\/  \\| (__/  )  ";
	textColor(9);
	cout << "| )   ( || (__/  )  \\   /  | (____/\\| )  \\  |   | |   | (___) || ) \\ \\__| (____/\\" << endl;
    gotoXY(2, 15);
	textColor(12);
	cout << "   )_(   ";
	textColor(7);
	cout << "(______/  \\___/\\/(______/   ";
	textColor(9);
	cout << "|/     \\|(______/    \\_/   (_______/|/    )_)   )_(   (_______)|/   \\__/(_______/" << endl;
	textColor(5);
    Sleep(3000);
    gotoXY(90, 17);
    cout << "by 이것좀 해조" << endl;
	Sleep(1500);
    gotoXY(48, 20);
    textColor(15);
    cout << "캐릭터 작성을 시작합니다."; 
    gotoXY(53, 21);
    cout << "(Press any key)";
    cursorView(1);
    _getch();
}

void PrintMessage::printUpperFrame()
{
    textColor(6);
    cout << "            .-------------------------------------------------------------------------------------------------." << endl;
    cout << "           /  .-.                                                                                         .-.  \\" << endl;
    cout << "          |  /   \\                                                                                       /   \\  |" << endl;
    cout << "          | |\\_.  |                                                                                     |    /| |" << endl;
    cout << "          |\\|  | /|                                                                                     |\\  | |/|" << endl;
    cout << "          | `---' |                                                                                     | `---' |" << endl;
    //cout << "          |       |                                                                                     |       |" << endl;
    //cout << "          |       |                                                                                     |       |" << endl;
    //cout << "          |       |                                                                                     |       |" << endl;
    //cout << "          |       |                                                                                     |       |" << endl;
    //cout << "          |       |-------------------------------------------------------------------------------------|       |" << endl;
    //cout << "          \\       |                                                                                     |       /" << endl;
    //cout << "           \\     /                                                                                       \\     /" << endl;
    //cout << "            `---'                                                                                         `---'" << endl;
    
    textColor(15);
    gotoXY(30, 1);
    cout << "   _     ___  _";
    gotoXY(47, 1);
    cout << "    _  ____  _     ____  _      ____  _    ";
    gotoXY(30, 2);
    cout << "  / \\__/|\\  \\//";
    gotoXY(47, 2);
    cout << "   / |/  _ \\/ \\ /\\/  __\\/ \\  /|/  _ \\/ \\   ";
    gotoXY(30, 3);
    cout << "  | |\\/|| \\  / ";
    gotoXY(47, 3);
    cout << "   | || / \\|| | |||  \\/|| |\\ ||| / \\|| |   ";
    gotoXY(30, 4);
    cout << "  | |  || / /  ";
    gotoXY(47, 4);
    cout << "/\\_| || \\_/|| \\_/||    /| | \\||| |-||| |_/\\";
    gotoXY(30, 5);
    cout << "  \\_/  \\|/_/   ";
    gotoXY(47, 5);
    cout << "\\____/\\____/\\____/\\_/\\_\\\\_/  \\|\\_/ \\|\\____/";
    textColor(7);
    gotoXY(0, 6);
}
void PrintMessage::printLowerFrame()
{
    textColor(6);
    //cout << "            .-------------------------------------------------------------------------------------------------." << endl;
    //cout << "           /  .-.                                                                                         .-.  \\" << endl;
    //cout << "          |  /   \\                                                                                       /   \\  |" << endl;
    //cout << "          | |\\_.  |                                                                                     |    /| |" << endl;
    //cout << "          |\\|  | /|                                                                                     |\\  | |/|" << endl;
    //cout << "          | `---' |                                                                                     | `---' |" << endl;
    //cout << "          |       |                                                                                     |       |" << endl;
    //cout << "          |       |                                                                                     |       |" << endl;
    //cout << "          |       |                                                                                     |       |" << endl;
    cout << "          |       |                                                                                     |       |" << endl;
    cout << "          |       |-------------------------------------------------------------------------------------|       |" << endl;
    cout << "          \\       |                                                                                     |       /" << endl;
    cout << "           \\     /                                                                                       \\     /" << endl;
    cout << "            `---'                                                                                         `---'" << endl;
    textColor(7);
}
void PrintMessage::printFrame()
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

void PrintMessage::printShopRoof()
{
	printFrame();
	cout << endl;
	printFrame();
    textColor(12);
    cout << "      /////////////////////////"; textColor(207); cout << "상점";  textColor(12); cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl; textColor(7);
}

void PrintMessage::cursorView(char c)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = c;
	ConsoleCursor.dwSize = 2;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void PrintMessage::bossAppears() 
{
    
    cursorView(0);
    printFrame();
    cout << endl;
    printFrame();
    cout << endl;
    printFrame();
    cout << endl;
    printFrame();
    cout << endl;
    printFrame();
    cout << endl;
    printFrame();
    cout << endl;
    printFrame();
    cout << endl;
    printFrame();
    cout << endl;

    
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "           .                                                      ." << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "         .n                   .                 .                  n." << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "   .   .dP                  dP                   9b                 9b.    ." << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "  4    qXb         .       dX                     Xb       .        dXp     t" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << " dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << " 9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "  9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "   `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "     `9XXXXXXXXXXXP' `9XX'   ..     `98v8P'    ..    `XXP' `9XXXXXXXXXXXP'" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "         ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                         )b.  .dbo.dP'`v'`9b.odb.  .dX(" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                       ,dXXXXXXXXXXXb     dXXXXXXXXXXXb." << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                      dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                     dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                     9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                      `'      9XXXXXX(   )XXXXXXP      `'" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                               XXXX X.`v'.X XXXX" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                               XP^X'`b   d'`X^XX" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                               X. 9  `   '  P )X" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                               `b  `       '  d'" << endl;
   printFrame(); textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                                `             '" << endl;
   Sleep(1000);
   
   
    textColor(8);  gotoXY(22, getcursorlocationY()-21);            cout << "           .                                                      ." << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "         .n                   .                 .                  n." << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "   .   .dP                  dP                   9b                 9b.    ." << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "  4    qXb         .       dX                     Xb       .        dXp     t" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << " dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << " 9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "  9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "   `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "     `9XXXXXXXXXXXP' `9XX'   ..     `98v8P'    ..    `XXP' `9XXXXXXXXXXXP'" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "         ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                         )b.  .dbo.dP'`v'`9b.odb.  .dX(" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                       ,dXXXXXXXXXXXb     dXXXXXXXXXXXb." << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                      dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                     dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                     9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                      `'      9XXXXXX(   )XXXXXXP      `'" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                               XXXX X.`v'.X XXXX" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                               XP^X'`b   d'`X^XX" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                               X. 9  `   '  P )X" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                               `b  `       '  d'" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                                `             '" << endl;
   Sleep(800);
   textColor(7);  gotoXY(22, getcursorlocationY() - 21);            cout << "           .                                                      ." << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "         .n                   .                 .                  n." << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "   .   .dP                  dP                   9b                 9b.    ." << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "  4    qXb         .       dX                     Xb       .        dXp     t" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << " dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << " 9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "  9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "   `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "     `9XXXXXXXXXXXP' `9XX'   ..     `98v8P'    ..    `XXP' `9XXXXXXXXXXXP'" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "         ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                         )b.  .dbo.dP'`v'`9b.odb.  .dX(" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                       ,dXXXXXXXXXXXb     dXXXXXXXXXXXb." << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                      dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                     dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                     9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                      `'      9XXXXXX(   )XXXXXXP      `'" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                               XXXX X.`v'.X XXXX" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                               XP^X'`b   d'`X^XX" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                               X. 9  `   '  P )X" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                               `b  `       '  d'" << endl;
   textColor(7);  gotoXY(22, getcursorlocationY());   cout << "                                `             '" << endl;
   Sleep(800);
   textColor(12);  gotoXY(22, getcursorlocationY() - 21);            cout << "           .                                                      ." << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "         .n                   .                 .                  n." << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "   .   .dP                  dP                   9b                 9b.    ." << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "  4    qXb         .       dX                     Xb       .        dXp     t" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << " dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << " 9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "  9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "   `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "     `9XXXXXXXXXXXP' `9XX'   ..     `98v8P'    ..    `XXP' `9XXXXXXXXXXXP'" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "         ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                         )b.  .dbo.dP'`v'`9b.odb.  .dX(" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                       ,dXXXXXXXXXXXb     dXXXXXXXXXXXb." << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                      dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                     dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                     9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                      `'      9XXXXXX(   )XXXXXXP      `'" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                               XXXX X.`v'.X XXXX" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                               XP^X'`b   d'`X^XX" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                               X. 9  `   '  P )X" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                               `b  `       '  d'" << endl;
   textColor(12);  gotoXY(22, getcursorlocationY());   cout << "                                `             '" << endl;
   Sleep(800);
    textColor(4);  gotoXY(22, getcursorlocationY()-21);            cout << "           .                                                      ." << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "         .n                   .                 .                  n." << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "   .   .dP                  dP                   9b                 9b.    ." << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "  4    qXb         .       dX                     Xb       .        dXp     t" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << " dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << " 9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "  9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "   `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "     `9XXXXXXXXXXXP' `9XX'   ..     `98v8P'    ..    `XXP' `9XXXXXXXXXXXP'" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "         ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                         )b.  .dbo.dP'`v'`9b.odb.  .dX(" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                       ,dXXXXXXXXXXXb     dXXXXXXXXXXXb." << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                      dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                     dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                     9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                      `'      9XXXXXX(   )XXXXXXP      `'" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                               XXXX X.`v'.X XXXX" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                               XP^X'`b   d'`X^XX" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                               X. 9  `   '  P )X" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                               `b  `       '  d'" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                                `             '" << endl;
   Sleep(800);

   printFrame(); textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                     _   _         _   _         _   _" << endl;
   printFrame(); textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
   printFrame(); textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
   printFrame(); textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
   printFrame(); textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
    textColor(8);  gotoXY(22, getcursorlocationY()-5);   cout << "                     _   _         _   _         _   _" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
    textColor(0);  gotoXY(22, getcursorlocationY()-5);   cout << "                     _   _         _   _         _   _" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
    textColor(8);  gotoXY(22, getcursorlocationY()-5);   cout << "                     _   _         _   _         _   _" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
    textColor(4);  gotoXY(22, getcursorlocationY()-5);   cout << "                     _   _         _   _         _   _" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
    textColor(8);  gotoXY(22, getcursorlocationY()-5);   cout << "                     _   _         _   _         _   _" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
    textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
    textColor(0);  gotoXY(22, getcursorlocationY() - 5);   cout << "                     _   _         _   _         _   _" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
    textColor(0);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
   textColor(8);  gotoXY(22, getcursorlocationY() - 5);   cout << "                     _   _         _   _         _   _" << endl;
   textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
   textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
   textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
   textColor(8);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
   Sleep(400);
    textColor(4);  gotoXY(22, getcursorlocationY() - 5);   cout << "                     _   _         _   _         _   _" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    | | | | __ _  | | | | __ _  | | | | __ _" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    | |_| |/ _` | | |_| |/ _` | | |_| |/ _` |" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    |  _  | (_| | |  _  | (_| | |  _  | (_| |" << endl;
    textColor(4);  gotoXY(22, getcursorlocationY());   cout << "                    |_| |_|\\__,_| |_| |_|\\__,_| |_| |_|\\__,_|" << endl;
  
   printFrame();
   cout << endl;
   printFrame();
   cout << endl;
   printFrame();
   cout << endl;

    Sleep(3000);
    cursorView(1);
}

void PrintMessage::displayEpitaph(string name)
{
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                   _____  _____" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  <     `/     |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                   >          (" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |   _     _  |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |  |_) | |_) |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |  | \\ | |   |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |            |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "   ______.______%_|            |__________  _____" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << " _/                                       \\|     |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "|               "; 
	textColor(15);
	cout << "      " << name;
	textColor(7);
	cout << "              <" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "|_____.-._________              ____/|___________|" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  | * 15/03/XX |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  | + 17/01/25 |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |            |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |            |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |   _        <" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                  |__/         |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    cout << "                   / `--.      |" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    textColor(2);
	cout << "                 %";
	textColor(7);
	cout << "|            |"; 
	textColor(2);
	cout << "%" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    textColor(2);
    cout << "             |/.%%";
	textColor(7);
	cout << "|           -<"; 
	textColor(2); 
	cout << "@%%%" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    textColor(2);
    cout << "             `\\%`@";
	textColor(7);
	cout << "|     v      |";
	textColor(2); 
	cout << "@@%@%%    " << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    textColor(2);
	cout << "           .%%%@@@";
	textColor(7); 
    cout << "|"; 
    textColor(2); 
    cout << "%";
    textColor(7);
    cout << "    |    ";
	textColor(2); 
	cout << "% @@@%%@%%%%" << endl;
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    gotoXY(32, getcursorlocationY());
    textColor(2);
    cout << "      _.%%%%%%@@@@@@%%"; 
    textColor(7);
    cout << "_/";
    textColor(2);
    cout << "%"; 
    textColor(7);
    cout << "\\_";
    textColor(2);
    cout << "%@@%%@@@@@@@%%%%%%" << endl;
	textColor(7);
    textColor(6);
    cout << "          |       |                                                                                     |       |";
    textColor(7);
    cout << endl;
}

//void PrintMessage::printCongratulations()
//{  
//        SetConsoleOutputCP(CP_UTF8);
//        SetConsoleCP(CP_UTF8);
//        
//        textColor(15);
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣿⣿⣿⣿⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣶⡾⠿⠟⠛⠉⠁⠀⠀⠀⠉⠙⠻⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⣾⠿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⠿⠟⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣢⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⣀⣠⣤⠶⠟⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠴⠿⢭⣯⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡟⡇" << endl;
//        cout << "⠀⢀⣤⢾⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠇⡇" << endl;
//        cout << "⢠⡟⠁⠉⠉⠙⠲⢦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀축하합니다! 고대의 악마를⠀⠀⠀⠀⠀⠀⠀⠘⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⡾⢋⡵⠃⢠⠇" << endl;
//        cout << "⣾⠀⢠⠞⢛⠷⣦⡀⠉⠻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀무찔렀습니다.⠀⠀⠀⠈⣷⡄⠀⠀⠀⠀⠀⣀⣴⠾⠋⢁⡴⠋⠀⣠⡟⠀" << endl;
//        cout << "⢿⡀⠘⣖⣈⡷⢸⡧⠀⠀⠘⢿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣷⡀⠀⣠⣴⠟⠋⠀⢀⡴⠋⠀⣠⡾⠋⠀⠀" << endl;
//        cout << "⠘⢷⣄⠈⠉⢀⣾⣧⣴⠶⠚⠉⢹⣦⠀⠀⣀⣀⡤⠀먼 옛날 봉인되었던 악마는⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣩⣵⠟⠋⠀⠀⢀⡴⠋⠀⢠⣾⠏⠀⠀⠀⠀" << endl;
//        cout << "⠀⠈⠉⠛⠛⠋⠉⠁⠀⠀⠀⠀⠈⢻⣯⠝⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⣾⠟⠁⠀⠀⢀⣴⠏⠀⠀⢠⡾⠁⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢹⣦⠖⠂⠀⠀물질계를 파멸시킬 기회만 노리고⠀⠀⠀⢀⠀⣼⡏⠀⠀⠀⣠⡟⠁⠀⠀⠀⣾⠃⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡆⠀⠀⠀있었습니다.⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⣴⡟⠀⢿⡇⠀⠀⣼⠏⢀⣀⣤⣤⣴⣿⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⢀⡜⢿⣇⠀⠸⡇⢀⣼⠃⠀⠀⠈⠳⣶⡴⠁⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⠀⠀그러나 당신의 영웅적인 활약으로⠀⠹⣄⣉⣓⣦⣝⣾⠃⠀⢀⣀⣤⠾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡆⠀악마의 사악한 계획은 무너지고⠀ ⠀⣩⠟⡋⣽⢿⡦⢭⣭⠭⠗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⠀⠀물질계의 평화는 다시 한번⠀⠀⠀⠀⠘⠁⠈⢹⡟⠀⢹⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡄⠀⠀지켜졌습니다.⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠇⠤⢚⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⣸⣿⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠀⠀⠀이에 당신에게 무한한 감사를⠀ ⠀⠀⠹⣿⠀⠀⠀⠸⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀드리는 바입니다.⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀ ⠀⢻⠀⠀⠀⠀⢙⡤⠤⠈⠙⠳⢤⡀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠴⠒⠋⠁⠀⠀⠀⠀⠀⠈⢿⡆⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀     감사합니다!⠀⠀⠀⠀⠀ ⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠼⢷⣶⠖⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠶⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠇⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⠿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣶⠾⠛⠁⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⣀⣠⣤⣶⡿⠟⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⠶⠚⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⢠⣼⣿⣯⣟⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⡴⠖⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡀⠀⡟⢡⢥⡈⠹⣧⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⡶⠞⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⡄⢻⣌⣠⡟⠀⣿⠂⠀⢀⣀⣤⣴⠶⠟⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⢿⣦⣌⣁⣀⣼⢯⣴⠶⢛⠋⠉⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
//        textColor(7);
//        Sleep(3000);
//
//      
//}