//
// Created by 18483 on 2025/1/7.
//
#include <iostream>
#include <vector>

using namespace std;

// ����216.����ܺ͢�
// ����˼·������77һ�£�Ψһ��ͬ���ǵݹ������������path���Ⱥ�sum������Ҫ��
// ������ö��ÿһ�����ʱ��Ҫ����path��sum���ݹ��������Ҫ�ָ�path��sum��ֱ���ҵ����������Ž�path���뵽�������
class Solution216_1
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(int k, int n, int sum, int start)
    {
        if (path.size() == k && sum == n)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            backtracking(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, 0, 1);
        return ret;
    }
};

// ��֦�Ż�
// ����ļ�֦�����ԣ����sum�Ѿ�����Ŀ��ֵnʱ�Ͳ���Ҫ�����ݹ���
// ��������ļ�֦�⣬������77һ��Ҳ�ж�forѭ���Ĵ������м�֦
class Solution216_2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(int k, int n, int sum, int start)
    {
        if (path.size() == k && sum == n)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i <= (9 - (k - path.size()) + 1); i++)
        {
            path.push_back(i);
            sum += i;
            // ��֦�Ż�
            if (sum > n)
            {
                path.pop_back();
                sum -= i;
                return;
            }
            backtracking(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, 0, 1);
        return ret;
    }
};
