//
// Created by 18483 on 2024/12/5.
//
#include <iostream>
#include <vector>
using namespace std;

// ����622.���ѭ������
class MyCircularQueue
{
private:
    // ��ͷָ��
    int front = 0;
    // ��βָ��
    int back = 0;
    // ���Ԫ�ظ���
    int maxLen = 0;
    // Ԫ�ظ���
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
        // �ж϶����Ƿ�����
        if (isFull())
            return false;

        // ������ָ��λ�ò���
        // λ������
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