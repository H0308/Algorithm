//
// Created by 18483 on 2024/11/23.
//
#include <iostream>
#include <set>
using namespace std;

// 力扣202.快乐数
// 解法1：集合
class Solution202
{
public:
    bool isHappy(int n)
    {
        set<int> s;
        int temp = n;
        int sum = 0;
        while (temp != 1)
        {
            while (temp)
            {
                int r = temp % 10;
                temp /= 10;

                sum += r * r;
            }
            temp = sum;

            if (s.count(sum))
                return false;
            s.insert(sum);
            sum = 0;
        }

        return true;
    }
};

// 解法2：双指针（见双指针章节）