//
// Created by 18483 on 2025/1/8.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����39.����ܺ�
/*
 * ������ǰ�������������Ĳ�ͬ�����ÿ��Ԫ�ؿ��Ա����ʹ�ã���һ����Ͻ�����У�ͬһ�����ֿ��Ա��ظ�ʹ�ö��
 * �����䱾�ʻ���һ����ϣ�ֻ����Ϊ���������һ��������ʹ��ÿһ������Ӧ�ô���һ��������λ�ü�����󣬶�����ȫ����ͷ��ʼ����������֮ǰ��ֱ�ӴӺ�һ��Ԫ�ؽ�������
 */
class Solution39_1
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int index)
    {
        // ��ֹջ���
        if (sum > target)
            return;
        // ���½��
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates, target, 0, 0);

        return ret;
    }
};

// ��֦�Ż����������
// ��������ʹ��ԭ�����Ԫ�ص��������������ǰԪ�ؼ��ϵ�ǰ��sum�Ѿ�����target����ô�����Ԫ��Ҳ�Ͳ���Ҫ�ٱ�����
// ע��˴������򲻿���ʡ�ԣ���Ϊ���ֻ���ж�sum + ��ǰԪ�ش���target�Ͳ���������ʱ���Ϳ��ܻ���ֺ������С��Ԫ�ؿ���ȷ��sum + С��Ԫ�ص���target
class Solution39_2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int index)
    {
        // ��ֹջ���
        if (sum > target)
            return;
        // ���½��
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);

        return ret;
    }
};
