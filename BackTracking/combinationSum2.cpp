//
// Created by 18483 on 2025/1/9.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ����40.����ܺ͢�
/*
 * ����Ļ���˼·���Ǽ����ܺ�sum����target����ϣ�������Ϊ�����������������ظ���Ԫ�أ�
 * ���Բ�����Ҫע��ÿһ������ڲ�����Ԫ��˳�������²��ظ����⣬��Ҫ�����ڻ�ȡ����ͬλ�õ�Ԫ�ص���Ԫ��ֵǰ���Ѿ����ֹ�ʱ�ٴ�ѡȡ���µ�����ظ�
 * �����ȥ�ط�ʽ���Դ��������濼�ǣ�
 * 1. ����ȥ�أ����ͬһ���Ԫ�ؽ���ȥ��
 * 2. ��֦ȥ�أ����ͬһ��·����Ԫ�ؽ���ȥ��
 *
 * ��[10,1,2,7,6,1,5]Ϊ����targetΪ8
 *
 * Ϊ��ʵ�������ȥ���߼�����Ҫһ������used����ʾÿһ��Ԫ���Ƿ�ʹ�ã�ֵֻ��true����false��������Ҫ�Ը������Ͻ�������
 * ��[1,1,2,5,6,7,10]��used=[false,false,false,false,false,false,false]
 * ��Ϊ�������������ͬλ�õ���ֵ��ͬ��Ԫ�س�����ͬһ������У���ʱ����[1,1,6]��used�����оͻ����[true, true, true]��
 * ���������������˵������ҪҲ�����Խ���ȥ�أ�һ��ȥ�ؾͻ���Ժ����6����ȱ��һ����Ͻ�������Կ��Բ���Ҫ���ǽ�����֦ȥ��
 *
 * ������Ҫ��������ȥ�أ���Ϊ��������1�����ʹ�õ�һ��1����ʱ��ͬһ���£��ڶ���1����δʹ��״̬����ʱused����[true,false...]
 * ���������������һ������1��һ����������[1,7]��������Ϊ7Ҳ������ڶ���1�ĺ��棬���Եڶ���1����Ҳ��������[1,7]����Ȼʹ�õ��ǲ�ͬλ�õ�1
 * ����������Ͻ����һ���ģ����Դ�ʱ����Ҫȥ��
 * ȥ�ص�˼·����������ǰ��������������ڶ���1�ı���
 *
 * ֮������Ҫʹ�õ����򣬾���Ϊ��ȷ����ͬ��Ԫ�ؿ��Գ�����һ��
 */
class Solution40
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int start, vector<bool> &used)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            // ȥ���߼�-����ȥ�ص���������֦ȥ�أ��ж�used[i - 1] == false����Ϊ�˷�ֹ����֦Ҳ������ȥ��
            if (i - 1 >= 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;

            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);

        return ret;
    }
};
