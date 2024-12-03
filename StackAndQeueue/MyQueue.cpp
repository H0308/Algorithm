//
// Created by 18483 on 2024/12/3.
//
#include <iostream>
#include <stack>
using namespace std;

// ����232.��ջʵ�ֶ���
class MyQueue
{
private:
    // ��������ջ
    stack<int> pushSt;
    stack<int> popSt;

public:
    MyQueue()
    {}

    void push(int x)
    {
        // ��pushSt��������
        pushSt.push(x);
    }

    int pop()
    {
        // �ж�popSt�Ƿ�Ϊ��
        if (popSt.empty())
        {
            // ��pushSt�е������ƶ���popSt
            int top = 0;
            while (!pushSt.empty())
            {
                top = pushSt.top();
                pushSt.pop();
                popSt.push(top);
            }
        }

        // popSt��Ϊ��ʱֱ�ӵ�������
        int top = popSt.top();
        popSt.pop();
        return top;
    }

    int peek()
    {
        // ���popSt��Ϊ�գ����ظ�ջ��Ԫ��
        if (!popSt.empty())
        {
            return popSt.top();
        }

        // ��pushSt�е������ƶ���popSt
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