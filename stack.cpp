#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()
{
    size = 1;
    stack = new int[size];
    for (int i = 0; i < size; i++)
        stack[i] = 0;
}

Stack::Stack(int stacksize)
{
    size = (stacksize > 0 ? stacksize : 1);
    stack = new int[size];
    for (int i = 0; i < size; i++)
        stack[i] = 0;
}

Stack::Stack(const Stack& other)
{
    size = other.size;
    stack = new int[other.size];
    for (int i = 0; i < other.size; i++)
    {
        stack[i] = other.stack[i];
    }
}

Stack::~Stack()
{
    delete[] stack;
}

void Stack::push(int elem)
{
    if (first >= size)
    {
        first++;
        Stack temp(*this);
        delete[] stack;
        size = size + 1;
        stack = new int[size];
        for (int i = 0; i < size; i++)
        {
            stack[i] = temp.stack[i];
        }
        stack[size - 1] = elem;
    }
    else
    {
        stack[first++] = elem;
    }
}

bool Stack::isEmpty() {
    calc = 0;
    for (int i = 0; i < size; i++)
    {
        if (stack[i] != 0)
            calc++;
    }
    if (calc == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stack::pop()
{
    int last = stack[size - 1];
    Stack temp(*this);
    delete[] stack;
    size = size - 1;
    stack = new int[size];
    for (int j = 0; j < size; j++)
        stack[j] = temp.stack[j];
    return last;
}

void Stack::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << stack[i];
        if (i < size - 1)
            cout << " ";
    }
    cout << endl;
}

void Stack::multiPop(int N)
{
    Stack temp(*this);
    delete[] stack;
    size = size - N;
    stack = new int[size];
    for (int j = 0; j < size; j++)
        stack[j] = temp.stack[j];
}

Stack& Stack::operator=(const Stack& other)
{
    size = other.size;
    if (this == &other)
        return *this;
    delete[] stack;
    stack = new int[other.size];
    for (int i = 0; i < other.size; i++)
        stack[i] = other.stack[i];
    return *this;
}

