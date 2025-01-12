//
// Created by 18483 on 2025/1/12.
//
#include <iostream>
#include <vector>

using namespace std;

// ����78.�Ӽ�
/*
 * �Լ����Ȿ��Ҳ��������⣬�����Ӽ���ǰ���������ⲻͬ���ǣ��Ӽ�������ÿһ�εĵݹ鶼�������Ҫ�Ľ������ǰ������ֻ������������ʱ�Ż��������Ҫ�Ľ��
 * �����Ӽ������ռ����ʱ��Ҫÿһ�εݹ���ռ�һ��
 * ���⣬��Ϊ�������ע�������±���Ʒ�ֹ�ظ�����������Ӽ����ⲻ��Ҫ�����ض�������ֹ�ݹ飬���Ա���ĵݹ�Ҳ���Բ���ʽд�ݹ���ֹ���������߼��Ѿ���ѭ��������
 */
class Solution78
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(const vector<int> &nums, int start)
    {
        ret.push_back(path);
        // ���Բ���Ҫ����д�ݹ����������start��ֵ��iʱ���������forѭ���жϴӶ������ݹ�
        // if(start == nums.size())
        //     return;

        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtracking(nums, 0);

        return ret;
    }
};
