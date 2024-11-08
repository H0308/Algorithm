//
// Created by 18483 on 2024/11/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����461.��������
// �ⷨ1���⺯������
class Solution461_1
{
public:
    int hammingDistance(int x, int y)
    {
        return __builtin_popcount(x ^ y);
    }
};

// �ⷨ2��������λ����ͳ��1�ĸ���
class Solution461_2
{
public:
    int hammingDistance(int x, int y)
    {
        // ͳ�Ƹ���
        int count = 0;
        // �������
        int ans = x ^ y;

        // �ҳ�һ�����ٸ�1
        for (int i = 0; i < 32; i++)
        {
            if ((ans >> i) & 1)
            {
                count++;
            }
        }
        return count;
    }
};

// �ⷨ3��ʹ��n&(n-1)���ν�������е�1���0������ٴξ��൱���ж��ٸ�1
class Solution461_3
{
public:
    int lowbit(int num)
    {
        return num & (num - 1);
    }

    int hammingDistance(int x, int y)
    {
        // ͳ�Ƹ���
        int count = 0;
        // �������
        int ans = x ^ y;

        // �ҳ�һ�����ٸ�1
        while (ans)
        {
            ans = lowbit(ans);
            count++;
        }
        return count;
    }
};

// ����338.����λ����
class Solution338
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ret;
        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int temp = i;
            // λ����
            while (temp)
            {
                temp = temp & (temp - 1);
                count++;
            }

            ret.push_back(count);
        }

        return ret;
    }
};

// ����191.λ1�ĸ���
class Solution191
{
public:
    int lowbit(int num)
    {
        return num & (num - 1);
    }

    int hammingWeight(int n)
    {
        int count = 0;

        while (n)
        {
            n = lowbit(n);
            count++;
        }

        return count;
    }
};

// ����136.ֻ����һ�ε�����
class Solution136
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        // ʹ���������Ľ���ɺ�������������
        for (auto num: nums)
        {
            ans ^= num;
        }

        return ans;
    }
};

// 260.ֻ����һ�ε����֢�
class Solution260
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int ans = 0;
        // �Ȼ�ȡ����������һ�ε�����
        for (auto n: nums)
        {
            ans ^= n;
        }

        // ���ݽ��ans��ԭ���ݽ��з���
        vector<int> ret(2);
        // ȡ�����λ��1���ڵ�λ��
        // int pos = ans & (-ans);
        // ע���ֹ���
        int pos = (ans == INT_MIN) ? ans : ans & (-ans);
        // ����
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & pos)
            {
                ret[0] ^= nums[i];
            }
            else
            {
                ret[1] ^= nums[i];
            }
        }

        return ret;
    }
};

// ����137.ֻ����һ�ε�����II
// �ⷨ1��˫ָ��
class Solution137
{
public:
    int singleNumber(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() == 1)
        {
            return nums[slow];
        }
        while (fast < nums.size())
        {
            if (nums[slow + 1] == nums[fast])
            {
                fast++;
            }
            else
            {
                slow = fast;
                fast++;
                if (fast < nums.size() && nums[fast] != nums[slow])
                {
                    break;
                }
            }
        }
        return nums[slow];
    }
};
