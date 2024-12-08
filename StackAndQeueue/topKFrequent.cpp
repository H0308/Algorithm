//
// Created by 18483 on 2024/12/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

// ����347.ǰK����ƵԪ��
// map+����
class Solution347_1
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> freq;
        vector<int> freqs;
        vector<int> ret;
        // ͳ���ַ�����
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

        // ���ճ���Ƶ�ʽ�������
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

// �Զ���ȽϺ��������º���
struct Compare
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

// map+��
class Solution347_2
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
        map<int, int> fre;

        // ͳ�Ƴ��ִ���
        for (const auto &num: nums)
        {
            fre[num]++;
        }

        // ����ڲ�������
        for (const auto &kv: fre)
        {
            que.push(kv);
            // ��������Ƶ�ʽ�С��Ԫ��
            if (que.size() > k)
            {
                que.pop();
            }
        }

        // ��¼����ֵ��Ϊ�˱�֤���˳��ͳ���Ƶ�ʴ�Сһ�£��ȿ��ٿռ�
        vector<int> ret(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = que.top().first;
            que.pop();
        }

        return ret;
    }
};
