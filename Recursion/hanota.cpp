//
// Created by 18483 on 2025/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣面试题08.06.汉诺塔问题
// 正常解法
class Solution0806_1
{
public:
    void _hanota(vector<int> &A, vector<int> &B, vector<int> &C, int num)
    {
        if (num == 1)
        {
            C.push_back(A.back());
            // 注意弹出最后一个元素
            A.pop_back();
            return;
        }

        _hanota(A, C, B, num - 1);
        C.push_back(A.back());
        // 注意弹出最后一个元素
        A.pop_back();
        _hanota(B, A, C, num - 1);
    }

    void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        _hanota(A, B, C, A.size());
    }
};

// 笔试投机取巧
class Solution0806_2
{
public:
    void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        C = A;
    }
};
