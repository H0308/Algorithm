//
// Created by 18483 on 2024/11/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

// 力扣260.只出现一次的数字Ⅲ
class Solution260_1
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        size_t ans = 0;
        // 先获取到两个出现一次的数字
        for (auto n: nums)
        {
            ans ^= n;
        }

        // 根据结果ans对原数据进行分组
        vector<int> ret(2);
        // 取出最低位的1所在的位置
        int pos = ans & (-ans);
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

// 写法2
class Solution260_2
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        size_t ans = 0;
        // 先获取到两个出现一次的数字
        for (auto n: nums)
        {
            ans ^= n;
        }

        // 根据结果ans对原数据进行分组
        vector<int> ret(2);
        // 取出最低位的1所在的位置
        int pos = ans & (-ans);
        // 分组
        for (auto n: nums)
        {
            ret[(n & pos) != 0] ^= n;
        }

        return ret;
    }
};

// 力扣137.只出现一次的数字II
// 解法1：双指针
class Solution137_1
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

// 解法2：位运算
class Solution137_2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        // 枚举32次依次填充ret使得ret中存储只出现一次的元素
        for (int i = 0; i < 32; i++)
        {
            // 计算每一位的和
            int sum = 0;
            for (auto n: nums)
            {
                if ((n >> i) & 1)
                {
                    sum++;
                }
            }

            // 取出只出现一次的元素的比特位
            sum %= 3;

            // 将ret对应的位置标记为sum的值
            // 如果sum为1，代表只出现一次的元素当前位为1
            if (sum)
            {
                ret |= (1 << i);
            }
        }

        // ret中存储的就是结果
        return ret;
    }
};

// 力扣面试题01.01.判定字符是否唯一
// 解法1：哈希表
// 写法1
class Solution0101_1_1
{
public:
    bool isUnique(string astr)
    {
        int hash[128] = {0};
        // 统计个数
        for (auto ch: astr)
        {
            hash[ch]++;
        }

        // 判断是否存在某一个字符出现个数大于1
        for (auto num: hash)
        {
            if (num > 1)
            {
                return false;
            }
        }

        return true;
    }
};

// 写法2
class Solution0101_1_2
{
public:
    bool isUnique(string astr)
    {
        int hash[26] = {0};

        for (auto ch: astr)
        {
            if (hash[ch - 'a'] != 0)
            {
                return false;
            }
            hash[ch - 'a']++;
        }

        return true;
    }
};

// 解法2：位运算
class Solution0101_2_1
{
public:
    bool isUnique(string astr)
    {
        int ans = 0;

        // 位图思想
        for (auto ch: astr)
        {
            // 判断指定位置是否已经为1
            if ((ans >> ((int) (ch - 'a'))) & 1)
            {
                return false;
            }
            // 将指定位置置为1
            ans |= (1 << (int) (ch - 'a'));
        }

        return true;
    }
};

// 优化版本
// 使用鸽巢原理优化
class Solution0101_2_2
{
public:
    bool isUnique(string astr)
    {
        // 使用鸽巢原理
        // 字符串长度大于26一定存在重复
        if (astr.size() > 26)
        {
            return false;
        }
        int ans = 0;

        // 位图思想
        for (auto ch: astr)
        {
            // 判断指定位置是否已经为1
            if ((ans >> ((int) (ch - 'a'))) & 1)
            {
                return false;
            }
            // 将指定位置置为1
            ans |= (1 << (int) (ch - 'a'));
        }

        return true;
    }
};

// 力扣268.丢失的数字
// 解法1：哈希表
class Solution268_1
{
public:
    int missingNumber(vector<int> &nums)
    {
        // 数组哈希
        vector<int> hash(nums.size() + 1);
        for (auto n: nums)
        {
            hash[n]++;
        }

        int index = 0;
        for (int i = 0; i <= nums.size() + 1; i++)
        {
            if (!hash[i])
            {
                index = i;
                break;
            }
        }

        return index;
    }
};

// 解法2：等差数列
class Solution268_2
{
public:
    int missingNumber(vector<int> &nums)
    {
        // 等差数列
        int sum = (0 + nums.size()) * (nums.size() + 1) / 2;

        return sum - accumulate(nums.begin(), nums.end(), 0);
    }
};

// 异或运算
class Solution268_3
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xorSum = 0;
        // 异或运算结合律
        for (auto n: nums)
        {
            xorSum ^= n;
        }

        // 枚举长度个数字
        for (int i = 0; i <= nums.size(); i++)
        {
            xorSum ^= i;
        }

        return xorSum;
    }
};

// 力扣371.两整数之和
// 不讲武德
class Solution371_1
{
public:
    int getSum(int a, int b)
    {
        return a + b;
    }
};

// 异或运算（无进位相加）+按位与+左移一位（获取进位）
class Solution371_2
{
public:
    int getSum(int a, int b)
    {
        // 异或运算：无进位相加
        int xorSum = a ^ b;
        // 获取进位
        // int carry = (a & b) << 1;
        // 防止移动负数左移未定义行为可以将原数值类型改为无符号
        size_t carry = size_t(a & b) << 1;
        while (carry)
        {
            a = xorSum;
            b = carry;
            xorSum = a ^ b;
            carry = size_t(a & b) << 1;
        }

        return xorSum;
    }
};

// 力扣面试题17.19.消失的两个数字
// 解法1：哈希表
// 需要注意，因为缺失两个数值，所以开辟的空间至少是原数组的长度+3，原因画图分析
class Solution17_19_1
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        int sz = nums.size();
        vector<int> hash(sz + 3);
        vector<int> ret;

        for (auto n: nums)
        {
            hash[n]++;
        }

        for (int i = 1; i < sz + 3; i++)
        {
            if (!hash[i])
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};

// 解法2：位运算
// 向原数组添加完整区间的数值，题目转换为：丢失的数字+只出现一次的数字Ⅲ
class Solution17_19_2
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        int sz = nums.size();
        int ans = 0;
        for (int i = 1; i <= sz + 2; i++)
        {
            nums.push_back(i);
        }
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

// 版本2：不修改原数组
class Solution17_19_2_1
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        int sz = nums.size();
        int ans = 0;
        // 先获取到两个出现一次的数字
        for (auto n: nums)
        {
            ans ^= n;
        }
        for (int i = 1; i <= nums.size() + 2; i++)
        {
            ans ^= i;
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

        for (int i = 1; i <= nums.size() + 2; i++)
        {
            if (i & pos)
            {
                ret[0] ^= i;
            }
            else
            {
                ret[1] ^= i;
            }
        }

        return ret;
    }
};
