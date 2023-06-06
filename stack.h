#include <iostream>

using namespace std;

class Stack
{

private:
	int size;
	int* stack;
	int calc;
	int first = 0;

public:
	Stack();
	Stack(int);
	Stack(const Stack&);
	~Stack();
	void push(int);
	bool isEmpty();
	int pop();
	void show();
	void multiPop(int);
	Stack& operator = (const Stack&);
};

