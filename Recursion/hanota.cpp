//
// Created by 18483 on 2025/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣面试题08.06.汉诺塔问题
// 正常解法
/*
 * 基本思路：通过模拟找出规律：
 * 1. 当A只有一个盘时，直接将A的盘移动到C上
 * 2. 当A有两个及以上的盘时，先将最后一个盘以上的盘借助C移动到B上，接着将A此时的唯一一个盘移动到C上
 *    再将B上的盘借助A移动到C上
 */
class Solution0806_1
{
public:
    void _hanota(vector<int> &A, vector<int> &B, vector<int> &C, int num)
    {
        // 注意使用num而不是A.size()，因为要移动的是剩余盘子，A的元素个数不能直观反映还有多个盘子
        // 另一方面，使用num可以表示当前递归的层次，防止栈溢出的问题
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
