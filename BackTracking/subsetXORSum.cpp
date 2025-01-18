//
// Created by 18483 on 2025/1/18.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣1863.找出所有子集的异或总和再求和
/*
 * 本题的基本思路就是求出子集，根据每一个子集求出异或和，最后对所有子集的异或和进行求和
 * 所以基本步骤就是通过变量sum记录所有子集的异或和之和，xorSum记录每一个子集的异或和，为了隐藏异或和的回溯，可以考虑在参数部分使用无副作用运算
 */
class Solution1863
{
public:
    int sum = 0;

    void backtracing(vector<int> &nums, int start, int xorSum)
    {
        // 计算当前已经存在的子集的异或和之和，注意xorSum因为是无副作用，所以回溯部分是交给递归完成的
        sum += xorSum;
        for (int i = start; i < nums.size(); i++)
            backtracing(nums, i + 1, xorSum ^ nums[i]);
    }

    int subsetXORSum(vector<int> &nums)
    {
        backtracing(nums, 0, 0);
        return sum;
    }
};
