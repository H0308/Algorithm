//
// Created by 18483 on 2024/12/8.
//
#include <iostream>
#include <queue>
using namespace std;

// 力扣215.数组中的第K个最大元素
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // 建小堆
        priority_queue<int, vector<int>, greater<int>> que(nums.begin(), nums.end());

        // 弹出指定个数的元素
        int i = nums.size() - k;
        while (i--)
            que.pop();

        return que.top();
    }
};
