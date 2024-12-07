//
// Created by 18483 on 2024/12/7.
//
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// 力扣239.滑动窗口最大值
class Solution
{
private:
    deque<int> dq;

    // 弹出最大元素
    void pop_max(int val)
    {
        if (!dq.empty() && val == dq.front())
            dq.pop_front();
    }

    // 插入较大元素，删除较小元素
    void push_val(int val)
    {
        while (!dq.empty() && val > dq.back())
            dq.pop_back();
        dq.push_back(val);
    }

    // 获取最大值
    int get_max()
    {
        return dq.front();
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ret;
        // 先向单调队列中插入前k个元素
        for (int i = 0; i < k; i++)
            push_val(nums[i]);

        // 获取当前最大值
        ret.push_back(get_max());

        // 移动窗口
        for (int i = k; i < nums.size(); i++)
        {
            // 移除滑动窗口的第一个值，如果是最大值就成功移除
            pop_max(nums[i - k]);
            // 插入数据
            push_val(nums[i]);
            // 获取到最大值
            ret.push_back(get_max());
        }

        return ret;
    }
};