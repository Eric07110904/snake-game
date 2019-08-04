// 真-貪吃蛇.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<Windows.h>
#include<conio.h>
#include "Header.h"
#include"Node.h"
using namespace std;

int main()
{
	
	
	hide_cursor();//防止閃頻
	int width, height;
	gotoxy(50, 0);
	cout << "請輸入場地長寬: ";
	cin >> width >> height;
	system("cls");
	

	
	//create play ground
	create_map(width, height);
	create_food(width, height);

	//create snake
	SetColor(2);
	Node* head=new Node(); head->x = 10; head->y = 6;
	gotoxy(head->x, head->y);
	cout << "▉";
	int dir = -1; int c = 0; int time = 500;
	//操作提示
	gotoxy(70, 5);cout << "W:上";
	gotoxy(76, 5);cout << "S:下";
	gotoxy(70, 9);cout << "A:左";
	gotoxy(76, 9);cout << "D:右";
	
	while (1) {
	
		if (_kbhit()) {
			char key = _getch();
			switch (key)
			{
				case 'w':
					if ((dir == 1&&get_len()!=1)||dir==0)
						continue;
					dir = 0;
					break;
				case 's':
					if ((dir == 0 && get_len() != 1)||dir==1)
						continue;
					dir = 1;
					break;
				case 'a':
					if ((dir == 3 && get_len() != 1)||dir==2)
						continue;
					dir = 2;
					break;
				case 'd':
					if ((dir == 2 && get_len() != 1)||dir==3)
						continue;
					dir = 3;
					break;
				default://其他按鍵 保持不變
					continue;
			
			
			}
			head=move(head, dir);
			if (check_wall(head) || !check_snake(head)) {
				system("cls");
				break;
			}
				
			
			
		}
		else if (c % time== 0&&dir!=-1) {
			head = move(head, dir);
			c = 0;
			if (check_wall(head)||!check_snake(head)){
				Sleep(3000);
				system("cls");
				break;
			}
			
		}
		c++;
		gotoxy(70,18);
		cout <<"目前的分數: "<<get_len();
		gotoxy(70,20 );
		cout << "目前速度: " << time;
	}
	
	while (1) {
		gotoxy(70, 18);
		cout << "you are fucking lose!\n";
		gotoxy(70, 20);
		cout << "你的分數為: " << get_len() << endl;
	}
	
	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
