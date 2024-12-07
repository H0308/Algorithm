//
// Created by 18483 on 2024/12/7.
//
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// ����239.�����������ֵ
class Solution
{
private:
    deque<int> dq;

    // �������Ԫ��
    void pop_max(int val)
    {
        if (!dq.empty() && val == dq.front())
            dq.pop_front();
    }

    // ����ϴ�Ԫ�أ�ɾ����СԪ��
    void push_val(int val)
    {
        while (!dq.empty() && val > dq.back())
            dq.pop_back();
        dq.push_back(val);
    }

    // ��ȡ���ֵ
    int get_max()
    {
        return dq.front();
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ret;
        // ���򵥵������в���ǰk��Ԫ��
        for (int i = 0; i < k; i++)
            push_val(nums[i]);

        // ��ȡ��ǰ���ֵ
        ret.push_back(get_max());

        // �ƶ�����
        for (int i = k; i < nums.size(); i++)
        {
            // �Ƴ��������ڵĵ�һ��ֵ����������ֵ�ͳɹ��Ƴ�
            pop_max(nums[i - k]);
            // ��������
            push_val(nums[i]);
            // ��ȡ�����ֵ
            ret.push_back(get_max());
        }

        return ret;
    }
};