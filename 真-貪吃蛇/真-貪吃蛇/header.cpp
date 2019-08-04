#include<cstdlib>
#include<Windows.h>
#include<iostream>
#include "Header.h"
#include<time.h>
using namespace std;
int w, h;
int MOVE[4][2] = { {0,-1},{0,1},{-2,0},{2,0} };
int food_x, food_y;
int snake_len = 1;
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, pos);
}

void SetColor(int x) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout, x);
}

void create_map(int width, int height) {
	//地圖最上方
	
	for (int i = 0; i < width; i++) {
		//cout << "*";
		if (i == 0) {
			cout << "╔";
		}
		else if (i == width - 1) {
			cout << "╗";
		}
		else {
			cout << "═";
			
		}
	}
	cout << endl;
	for (int i = 1; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0||j==(width-1))
				cout << "║";
			else
				cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) {
		//cout << "*";
		if (i == 0) {
			cout << "╚";
		}
		else if (i == width - 1) {
			cout << "╝";
		}
		else {
			cout << "═";
		}
	}
}
void create_food(int width, int height) {
	SetColor(3);
	srand(time(NULL));//打亂 亂數時間種子 否則rand會都一樣
	w = width; h = height;
	
	food_x = (rand() % (width-5))+1;
	food_y = (rand() % (height-2))+1;
	if (food_x % 2 == 1)//因為 輸出的圖形是方塊 長度為2char 如果是奇數 會出問題
		food_x += 1;
	gotoxy(food_x, food_y);
	cout << "●";
	SetColor(2);
	
}

Node* move(Node* root, int dir) {
	
	Node* NEW = new Node(root->x+MOVE[dir][0], root->y+MOVE[dir][1]);
	NEW->next = root;
	gotoxy(NEW->x, NEW->y);
	
	cout << "▉";
	
	Node* temp = NEW;
	Node* pre=new Node;
	while (temp->next != NULL) {
		pre = temp;
		temp = temp->next;
	}
		

	if (food_x == NEW->x && food_y == NEW->y) {//碰到食物
		//increase
		create_food(w, h);
		snake_len++;
	}
	else {
		gotoxy(temp->x, temp->y);
		cout << "  ";
		pre->next = NULL;
		
	}
		
	return NEW;
	
}
int get_len() {
	return snake_len;
}
bool check_wall(Node* head) {
	return (head->x == 0 || head->y == 0 || head->x == w-2 || head->y == h);
		
}
bool check_snake(Node* head) {
	Node* temp = head;
	temp = temp->next;
	while (temp != NULL) {
		if (head->x == temp->x && head->y ==temp->y) {
			return false;
		}
		temp = temp->next;
	}
	return true;
}
void hide_cursor() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(hout, &info);
}