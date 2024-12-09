//
// Created by 18483 on 2024/12/4.
//
#include <iostream>
#include <queue>
using namespace std;

// ����225.�ö���ʵ��ջ
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
            return q1.back();

        return q2.back();
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

// ����һ�����У����Ǵ�ʱ����Ҫһ����������ͳ�Ƶ�ǰ���е�Ԫ�ظ���
// ���������У���Ԫ�ش�β���������ٴ�ͷ������ֱ�����һ��Ԫ��Ϊֹ
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
            que.push(que.front()); // ������ͷ����Ԫ�أ��������һ��Ԫ���⣩ ������ӵ�����β��
            que.pop();
        }
        int result = que.front(); // ��ʱ������Ԫ��˳�����ջ��˳����
        que.pop();
        return result;
    }

    int top()
    {
        int size = que.size();
        size--;
        while (size--)
        {
            // ������ͷ����Ԫ�أ��������һ��Ԫ���⣩ ������ӵ�����β��
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // ��ʱ��õ�Ԫ�ؾ���ջ����Ԫ����
        que.push(que.front());    // ����ȡ���Ԫ��Ҳ������ӵ�����β������֤���ݽṹû�б仯
        que.pop();
        return result;
    }

    bool empty()
    {
        return que.empty();
    }
};