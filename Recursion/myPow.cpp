//
// Created by 18483 on 2025/1/3.
//
#include <iostream>
using namespace std;

// ����50.Pow(x, n)
// �����ݹ�
class Solution50_1_1
{
public:
    double myPow(double x, int n)
    {
        if (n == 1)
            return x;
        double ret = 0;
        if (n < 0)
            ret = myPow(1 / x, n - 1);
        else
            ret = myPow(x, n - 1);

        return ret * x;
    }
};

// ����ѭ��
class Solution_1_2
{
public:
    double myPow(double x, int n)
    {
        double base = x;
        if (n == 0)
            return 1.0;
        for (int i = 1; i < abs(n); i++)
            x = base * x;

        if (n < 0)
            x = 1 / x;

        return x;
    }
};

// ������
// �۰�˼��
class Solution50_2
{
public:
    double myPow(double x, int n)
    {
        if (!n)
            return 1;

        // �����������ת��Ϊ��������������
        if (n < 0)
            x = 1 / x;

        // ǿתΪlong long��ֹ-2^31���
        double ret = myPow(x, abs((long long) n) / 2);
        // nΪ����ʱ���һ��x
        return n % 2 == 0 ? ret * ret : ret * ret * x;
    }
};