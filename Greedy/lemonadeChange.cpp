//
// Created by 18483 on 2025/2/7.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣860.柠檬水找零
/*
 * 本题就是按照题目的要求去模拟，一共有三种情况：
 * 1. 收到面值为5，直接收下
 * 2. 收到面值为10，找面值5
 * 3. 收到面值为20，可以找10和5，也可以找3个5，但是优先10和5，因为5更通用
 * 注意，本题不需要考虑具体的计算，例如找零还剩多少钱，只需要确定是否还可以正确找零即可，对于这种情况，只需要记录可以用来找零的面值个数是否足够即可
 */
class Solution860
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (auto bill: bills)
        {
            if (bill == 5)
                five++;
            else if (bill == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else if (bill == 20)
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }

        return true;
    }
};
