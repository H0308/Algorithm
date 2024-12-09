//
// Created by 18483 on 2024/12/4.
//
#include <iostream>
#include <queue>
using namespace std;

// 力扣225.用队列实现栈
class MyStack225_1
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack225_1()
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
            return q1.back();

        return q2.back();
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

// 仅用一个队列，但是此时就需要一个变量用于统计当前队列的元素个数
// 遍历过程中，将元素从尾部弹出，再从头部插入直到最后一个元素为止
class MyStack225_2
{
public:
    queue<int> que;

    MyStack225_2()
    {

    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int size = que.size();
        size--;
        while (size--)
        {
            que.push(que.front()); // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    int top()
    {
        int size = que.size();
        size--;
        while (size--)
        {
            // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时获得的元素就是栈顶的元素了
        que.push(que.front());    // 将获取完的元素也重新添加到队列尾部，保证数据结构没有变化
        que.pop();
        return result;
    }

    bool empty()
    {
        return que.empty();
    }
};