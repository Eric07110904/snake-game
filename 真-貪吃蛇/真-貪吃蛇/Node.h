#pragma once
class Node
{
public:
	int x;
	int y;
	Node* next;
	Node* pre;
	Node() :x(0), y(0), next(0), pre(0) {};
	Node(int X, int Y) :x(X), y(Y) ,next(0),pre(0){};
};

