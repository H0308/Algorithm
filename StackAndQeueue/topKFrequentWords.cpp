//
// Created by 18483 on 2024/12/8.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

using psi = pair<string, int>;

struct Compare
{
    bool operator()(const psi &p1, const psi &p2)
    {
        return p1.second > p2.second || p1.second == p2.second && p1.first < p2.first;
    }
};

// 力扣692.前K个高频单词
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        priority_queue<psi, vector<psi>, Compare> que;

        // map统计单词的次数
        map<string, int> fre;

        for (const auto &str: words)
        {
            fre[str]++;
        }

        // 向队列中插入数据
        for (const auto &it: fre)
        {
            que.push(it);
            if (que.size() > k)
            {
                que.pop();
            }
        }

        // 存储返回值
        vector<string> ret(k);
        for (int i = ret.size() - 1; i >= 0; i--)
        {
            ret[i] = que.top().first;
            que.pop();
        }

        return ret;
    }
};
