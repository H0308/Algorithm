//
// Created by 18483 on 2025/1/13.
//
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// ����47.ȫ���Т�
/*
 * �������ȫ���е�˼·+ʹ��unordered_set��ͬ�����ȥ�أ�������Ϊ�������ݷ�Χ��С������ֱ�ӿ������������unordered_set
 *
 * ע�⣬���ʹ��used�������ȥ�أ���ʱ������������֦ȥ�ض����Խ����Ч��������ԭ��������[1,1,1]���������Ƽ�����ȥ��
 */
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // ʹ��used����Ƿ��Ѿ�ʹ�ù�
        vector<bool> used(nums.size(), false);

        function < void() > backtracing = [&]()-> void
        {
            if (path.size() == nums.size())
            {
                ret.push_back(path);
                return;
            }

            // ��¼��ǰ���Ƿ�����ͬԪ���Ѿ���ʹ��
            int isAppeared[21] = {0};

            for (int i = 0; i < nums.size(); i++)
            {
                if (used[i] || isAppeared[nums[i] + 10])
                    continue;

                path.push_back(nums[i]);
                used[i] = true;
                isAppeared[nums[i] + 10] = 1;
                backtracing();
                path.pop_back();
                used[i] = false;
            }
        };

        backtracing();

        return ret;
    }
};
