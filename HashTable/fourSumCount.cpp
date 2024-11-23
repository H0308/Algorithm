//
// Created by 18483 on 2024/11/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ����454.�������II
class Solution454
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // map������������ӳ��
        unordered_map<int, int> m;
        int count = 0;
        // ����ǰ��������
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                m[nums1[i] + nums2[j]]++;
            }
        }

        // �������������飬�����ȡ����ֵ0-(c+d)==a+b����˵�����ֹ�����һ��
        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                if (m.count(0 - nums3[i] - nums4[j]))
                {
                    count += m[0 - nums3[i] - nums4[j]];
                }
            }
        }

        return count;
    }
};
