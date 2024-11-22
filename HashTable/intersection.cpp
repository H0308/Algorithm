//
// Created by 18483 on 2024/11/22.
//
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

// 力扣349.两个数组的交集
class Solution349
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s(nums1.begin(), nums1.end());
        set<int> ret;

        for (auto num: nums2)
        {
            if (s.count(num))
            {
                ret.insert(num);
            }
        }

        return vector<int>(ret.begin(), ret.end());
    }
};

// 力扣350.两个数组的交集II
class Solution350
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> m1;
        map<int, int> m2;
        for (auto num: nums1)
            m1[num]++;

        for (auto num: nums2)
            m2[num]++;

        vector<int> ret;

        auto it = m1.begin();
        while (it != m1.end())
        {
            if (m2.find(it->first) != m2.end())
                if (m1[it->first] <= m2[it->first])
                    for (int i = 0; i < m1[it->first]; i++)
                        ret.push_back(it->first);
                else
                    for (int i = 0; i < m2[it->first]; i++)
                        ret.push_back(it->first);

            ++it;
        }

        return ret;
    }
};
