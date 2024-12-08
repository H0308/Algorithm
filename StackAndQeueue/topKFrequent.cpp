//
// Created by 18483 on 2024/12/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

// 力扣347.前K个高频元素
// map+排序
class Solution347_1
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> freq;
        vector<int> freqs;
        vector<int> ret;
        // 统计字符个数
        for (auto &num: nums)
        {
            freq[num]++;
        }

        auto it = freq.begin();
        while (it != freq.end())
        {
            freqs.push_back(it->first);
            ++it;
        }

        // 按照出现频率进行排序
        sort(freqs.begin(), freqs.end(), [&](const int &num1, const int &num2) -> bool
        {
            return freqs[num1] > freqs[num2];
        });

        for (int i = 0; i < k; i++)
        {
            ret.push_back(freqs[i]);
        }

        return ret;
    }
};

// 自定义比较函数——仿函数
struct Compare
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

// map+堆
class Solution347_2
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
        map<int, int> fre;

        // 统计出现次数
        for (const auto &num: nums)
        {
            fre[num]++;
        }

        // 向堆内插入数据
        for (const auto &kv: fre)
        {
            que.push(kv);
            // 弹出出现频率较小的元素
            if (que.size() > k)
            {
                que.pop();
            }
        }

        // 记录返回值，为了保证输出顺序和出现频率大小一致，先开辟空间
        vector<int> ret(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = que.top().first;
            que.pop();
        }

        return ret;
    }
};
