#pragma once
#include "Node.h"
void gotoxy(int x, int y);
void SetColor(int color);
void create_map(int width, int height);
void create_food(int width, int height);
Node* move(Node* root, int dir);
int get_len();
bool check_wall(Node* head);
bool check_snake(Node* head);
void hide_cursor();

