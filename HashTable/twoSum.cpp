//
// Created by 18483 on 2024/11/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ����1.����֮��
// �ж�target - ��ǰ��ֵ�Ƿ���map�У�����ھ�˵��map�е���ֵ�͵�ǰ��ֵΪ��Ҫ����ֵ�������±꼴��
// ����set����ΪҪ�����±꣬��Ҫ�����±����ֵ��ӳ��
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        // map�洢�±����ֵӳ��
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(target - nums[i]))
            {
                return {i, m[target - nums[i]]};
            }
            m.insert({nums[i], i});
        }

        return {0};
    }
};

// �������û�����Ʒ����±꣬����Կ���ʹ��˫ָ��