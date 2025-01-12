//
// Created by 18483 on 2025/1/12.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

// ����491.�ǵݼ�������
/*
 * ʹ��unordered_set����ȥ�أ�ֻ��Ҫȷ����ǰ��ֵ�ȵ�ǰ��ϵ����һ��Ԫ�ش󼴿ɲ��뵽��ǰ�����
 * ���ⲻ����ʹ��used�������ȥ�أ���Ϊused������Ҫ�õ���������������Ǳ��ⲻ�ܽ�������һ������ͻ����ԭ�е�Ԫ��˳��Ӷ����ֲ����ڵķǵݼ�����
 *
 * ��չ��֮ǰʹ��used�������ȥ�ص���ĿҲ����ʹ��unordered_set����ȥ�أ�������һ���ģ�ֻ��˼·����һ�㲻ͬ
 */
class Solution491_1
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        function<void(int)> backtracking = [&](int start)-> void
        {
            if (path.size() >= 2)
                ret.push_back(path);

            // ʹ��set��¼��ǰ�����ֵ�����ں����ж��Ƿ��ظ�ʹ����ֵ��ͬ������
            unordered_set<int> uset;
            for (int i = start; i < nums.size(); i++)
            {
                // ����ȥ��
                if (!path.empty() && nums[i] < path.back() || uset.count(nums[i]))
                    continue;

                path.push_back(nums[i]);
                // ����Ҫ��uset���л��ݣ���Ϊÿһ�εݹ鶼���µ�uset
                uset.insert(nums[i]);
                backtracking(i + 1);
                path.pop_back();
            }
        };

        backtracking(0);

        return ret;
    }
};

// �����Ż�
// ��Ϊ�������ݷ�Χ��[-100, 100]�����Կ��Կ���ֱ��ʹ���������ֱ�Ӷ�ַ��������Ҫע�⣬��Ϊ���ڸ��������Կ�������Բ�������ּ�100��ӳ�䵽[0, 200]��Χ�Ŀռ�
class Solution491_2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        function<void(int)> backtracking = [&](int start)-> void
        {
            if (path.size() >= 2)
                ret.push_back(path);

            // ʹ��set��¼��ǰ�����ֵ�����ں����ж��Ƿ��ظ�ʹ����ֵ��ͬ������
            int uset[201] = {0};
            for (int i = start; i < nums.size(); i++)
            {
                // ����ȥ��
                if (!path.empty() && nums[i] < path.back() || uset[nums[i] + 100])
                    continue;

                path.push_back(nums[i]);
                // ����Ҫ��uset���л��ݣ���Ϊÿһ�εݹ鶼���µ�uset
                uset[nums[i] + 100] = 1;
                backtracking(i + 1);
                path.pop_back();
            }
        };

        backtracking(0);

        return ret;
    }
};
