//
// Created by 18483 on 2024/11/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 力扣461.汉明距离
// 解法1：库函数方法
class Solution461_1
{
public:
    int hammingDistance(int x, int y)
    {
        return __builtin_popcount(x ^ y);
    }
};

// 解法2：利用移位计数统计1的个数
class Solution461_2
{
public:
    int hammingDistance(int x, int y)
    {
        // 统计个数
        int count = 0;
        // 二者异或
        int ans = x ^ y;

        // 找出一共多少个1
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

// 解法3：使用n&(n-1)依次将异或结果中的1变成0，变多少次就相当于有多少个1
class Solution461_3
{
public:
    int lowbit(int num)
    {
        return num & (num - 1);
    }

    int hammingDistance(int x, int y)
    {
        // 统计个数
        int count = 0;
        // 二者异或
        int ans = x ^ y;

        // 找出一共多少个1
        while (ans)
        {
            ans = lowbit(ans);
            count++;
        }
        return count;
    }
};

// 力扣338.比特位计数
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
            // 位运算
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

// 力扣191.位1的个数
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

// 力扣136.只出现一次的数字
class Solution136
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        // 使用异或运算的结合律和异或运算的性质
        for (auto num: nums)
        {
            ans ^= num;
        }

        return ans;
    }
};

// 260.只出现一次的数字Ⅲ
class Solution260
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int ans = 0;
        // 先获取到两个出现一次的数字
        for (auto n: nums)
        {
            ans ^= n;
        }

        // 根据结果ans对原数据进行分组
        vector<int> ret(2);
        // 取出最低位的1所在的位置
        // int pos = ans & (-ans);
        // 注意防止溢出
        int pos = (ans == INT_MIN) ? ans : ans & (-ans);
        // 分组
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

// 力扣137.只出现一次的数字II
// 解法1：双指针
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
