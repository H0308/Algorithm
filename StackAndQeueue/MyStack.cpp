//
// Created by 18483 on 2024/12/4.
//
#include <iostream>
#include <queue>
using namespace std;

// 力扣225.用队列实现栈
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
        // 插入到不为空的队列末尾
        if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop()
    {
        int back = 0;
        // 找到非空队列的最后一个
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
        // 找到非空队列的对头元素
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