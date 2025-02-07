//
// Created by 18483 on 2025/2/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 力扣1005.K次取反后最大化的数组和
/*
 * 本题的基本思路就是先对数组中的至多k个绝对值较大的负数进行取反，如果负数个数小于k，那么再对最小的正数进行多次取反直到k用完
 * 根据这个思路可以看出，本题用到了两次贪心，第一次贪绝对值较大的负数，第二次贪绝对值较小的非负整数
 * 对于第一次贪，考虑先对数组按照绝对值较大者优先进行排序，当遇到负数时，对其进行取反并减小一次k值，直到没有负数或者k用完为止
 * 对于第二次贪，只需要找到最小的非负整数一直取反直到用完k为止
 * 对于第二次来说，可以考虑用循环一直对一个数进行取反，但是也可以考虑取反的周期性，如果k为奇数，那么进行k次取反，结果一定是原来数值的相反数
 * 否则k不变
 */
class Solution1005
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // 按照绝对值较大优先，对数组进行排序
        sort(nums.begin(), nums.end(), [&](int a, int b)-> bool
        {
            return abs(a) > abs(b);
        });

        // 第一次贪心：对绝对值较大的负数进行取反，使得数组的负数个数尽可能少
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
        }

        // 第二次贪心：对最小的非负整数进行取反，使得影响数组总和的负数个数最少
        // 如果k是奇数，那么多次取反后，结果就是原数取反的结果
        // 如果k是偶数，那么多次取反后，结果依旧是原数
        if (k % 2 == 1)
            nums[nums.size() - 1] *= -1;

        return accumulate(nums.begin(), nums.end(), 0);
    }
};
