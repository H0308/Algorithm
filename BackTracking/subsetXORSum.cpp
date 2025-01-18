//
// Created by 18483 on 2025/1/18.
//
#include <iostream>
#include <vector>

using namespace std;

// ����1863.�ҳ������Ӽ�������ܺ������
/*
 * ����Ļ���˼·��������Ӽ�������ÿһ���Ӽ�������ͣ����������Ӽ������ͽ������
 * ���Ի����������ͨ������sum��¼�����Ӽ�������֮�ͣ�xorSum��¼ÿһ���Ӽ������ͣ�Ϊ���������͵Ļ��ݣ����Կ����ڲ�������ʹ���޸���������
 */
class Solution1863
{
public:
    int sum = 0;

    void backtracing(vector<int> &nums, int start, int xorSum)
    {
        // ���㵱ǰ�Ѿ����ڵ��Ӽ�������֮�ͣ�ע��xorSum��Ϊ���޸����ã����Ի��ݲ����ǽ����ݹ���ɵ�
        sum += xorSum;
        for (int i = start; i < nums.size(); i++)
            backtracing(nums, i + 1, xorSum ^ nums[i]);
    }

    int subsetXORSum(vector<int> &nums)
    {
        backtracing(nums, 0, 0);
        return sum;
    }
};
