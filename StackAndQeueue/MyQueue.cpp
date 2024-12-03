//
// Created by 18483 on 2024/12/3.
//
#include <iostream>
#include <stack>
using namespace std;

// 力扣232.用栈实现队列
class MyQueue
{
private:
    // 创建两个栈
    stack<int> pushSt;
    stack<int> popSt;

public:
    MyQueue()
    {}

    void push(int x)
    {
        // 向pushSt插入数据
        pushSt.push(x);
    }

    int pop()
    {
        // 判断popSt是否为空
        if (popSt.empty())
        {
            // 将pushSt中的数据移动到popSt
            int top = 0;
            while (!pushSt.empty())
            {
                top = pushSt.top();
                pushSt.pop();
                popSt.push(top);
            }
        }

        // popSt不为空时直接弹出数据
        int top = popSt.top();
        popSt.pop();
        return top;
    }

    int peek()
    {
        // 如果popSt不为空，返回该栈顶元素
        if (!popSt.empty())
        {
            return popSt.top();
        }

        // 将pushSt中的数据移动到popSt
        int top = 0;
        while (!pushSt.empty())
        {
            top = pushSt.top();
            pushSt.pop();
            popSt.push(top);
        }

        return popSt.top();
    }

    bool empty()
    {
        return pushSt.empty() && popSt.empty();
    }
};