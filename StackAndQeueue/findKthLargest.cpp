//
// Created by 18483 on 2024/12/8.
//
#include <iostream>
#include <queue>
using namespace std;

// ����215.�����еĵ�K�����Ԫ��
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // ��С��
        priority_queue<int, vector<int>, greater<int>> que(nums.begin(), nums.end());

        // ����ָ��������Ԫ��
        int i = nums.size() - k;
        while (i--)
            que.pop();

        return que.top();
    }
};
