//
// Created by 18483 on 2025/1/13.
//
#include <iostream>
#include <vector>

using namespace std;

// ����46.ȫ����
/*
 * ��������ϲ�ͬ���ǣ����н���ÿһ�������Ԫ��֮���˳��һ��˳��ͬ���������ֲ�ͬ�����������[1,2,3]��[1,3,2]
 * ���Կ����������У������Ѿ�ȡ��һ��Ԫ�أ���һ�����ɻ��Ǵ�ͷ��ʼ�ң����һ���Ҫ�����Ѿ�ѡ������֣����Կ��Կ���ʹ��һ��used�����������ȡ����Ԫ��
 */
class Solution46
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(const vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;

            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);

        backtracking(nums, used);

        return ret;
    }
};
