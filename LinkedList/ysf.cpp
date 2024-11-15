//
// Created by 18483 on 2024/11/15.
//
#include <iostream>
#include <list>

using namespace std;

// 牛客网：环形链表的约瑟夫问题
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param m int整型
     * @return int整型
     */
    int ysf(int n, int m)
    {
        list<int> q;
        // 添加节点
        for (int i = 1; i <= n; i++)
        {
            q.push_back(i);
        }

        // 报数
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