//
// Created by 18483 on 2024/12/5.
//
#include <iostream>
#include <vector>
using namespace std;

// 力扣622.设计循环队列
class MyCircularQueue
{
private:
    // 队头指针
    int front = 0;
    // 队尾指针
    int back = 0;
    // 最大元素个数
    int maxLen = 0;
    // 元素个数
    int num = 0;
    vector<int> cir;

public:
    MyCircularQueue(int k)
    {
        maxLen = k;
        cir.resize(k);
    }

    bool enQueue(int value)
    {
        // 判断队列是否已满
        if (isFull())
            return false;

        // 否则在指定位置插入
        // 位置修正
        if (back >= maxLen)
            back = back % maxLen;

        cir[back++] = value;
        num++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front++;
        num--;
        if (front >= maxLen)
            front = (front - 1) % maxLen;

        return true;
    }

    int Front()
    {
        if (num == 0)
            return -1;

        return cir[front];
    }

    int Rear()
    {
        if (num == 0)
            return -1;

        int ret = back == 0 ? cir[back] : cir[back - 1];

        return ret;
    }

    bool isEmpty()
    {
        return num == 0;
    }

    bool isFull()
    {
        return num == maxLen;
    }
};