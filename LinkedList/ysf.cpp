//
// Created by 18483 on 2024/11/15.
//
#include <iostream>
#include <list>

using namespace std;

// ţ���������������Լɪ������
class Solution
{
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param n int����
     * @param m int����
     * @return int����
     */
    int ysf(int n, int m)
    {
        list<int> q;
        // ��ӽڵ�
        for (int i = 1; i <= n; i++)
        {
            q.push_back(i);
        }

        // ����
        int count = 1;
        for (auto it = q.begin(); q.size() > 1;)
        {
            if (count == m)
            {
                it = q.erase(it);
                if (it == q.end())
                {
                    it = q.begin();
                }
                count = 1;
            }
            else
            {
                if (++it == q.end())
                {
                    it = q.begin();
                }
                count++;
            }
        }

        return q.back();
    }
};