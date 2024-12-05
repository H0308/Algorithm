//
// Created by 18483 on 2024/12/4.
//
#include <iostream>
#include <queue>
using namespace std;

// ����225.�ö���ʵ��ջ
class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        // ���뵽��Ϊ�յĶ���ĩβ
        if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop()
    {
        int back = 0;
        // �ҵ��ǿն��е����һ��
        while (!q1.empty())
        {
            back = q1.front();
            if (q1.size() == 1)
            {
                q1.pop();
                return back;
            }
            q2.push(back);
            q1.pop();
        }

        while (!q2.empty())
        {
            back = q2.front();
            if (q2.size() == 1)
            {
                q2.pop();
                break;
            }
            q1.push(back);
            q2.pop();
        }

        return back;
    }

    int top()
    {
        // �ҵ��ǿն��еĶ�ͷԪ��
        if (!q1.empty())
        {
            return q1.back();
        }

        return q2.back();
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};