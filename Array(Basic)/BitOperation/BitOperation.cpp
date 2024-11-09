//
// Created by 18483 on 2024/11/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

// ����260.ֻ����һ�ε����֢�
class Solution260_1
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        size_t ans = 0;
        // �Ȼ�ȡ����������һ�ε�����
        for (auto n: nums)
        {
            ans ^= n;
        }

        // ���ݽ��ans��ԭ���ݽ��з���
        vector<int> ret(2);
        // ȡ�����λ��1���ڵ�λ��
        int pos = ans & (-ans);
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

// д��2
class Solution260_2
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        size_t ans = 0;
        // �Ȼ�ȡ����������һ�ε�����
        for (auto n: nums)
        {
            ans ^= n;
        }

        // ���ݽ��ans��ԭ���ݽ��з���
        vector<int> ret(2);
        // ȡ�����λ��1���ڵ�λ��
        int pos = ans & (-ans);
        // ����
        for (auto n: nums)
        {
            ret[(n & pos) != 0] ^= n;
        }

        return ret;
    }
};

// ����137.ֻ����һ�ε�����II
// �ⷨ1��˫ָ��
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

// �ⷨ2��λ����
class Solution137_2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        // ö��32���������retʹ��ret�д洢ֻ����һ�ε�Ԫ��
        for (int i = 0; i < 32; i++)
        {
            // ����ÿһλ�ĺ�
            int sum = 0;
            for (auto n: nums)
            {
                if ((n >> i) & 1)
                {
                    sum++;
                }
            }

            // ȡ��ֻ����һ�ε�Ԫ�صı���λ
            sum %= 3;

            // ��ret��Ӧ��λ�ñ��Ϊsum��ֵ
            // ���sumΪ1������ֻ����һ�ε�Ԫ�ص�ǰλΪ1
            if (sum)
            {
                ret |= (1 << i);
            }
        }

        // ret�д洢�ľ��ǽ��
        return ret;
    }
};

// ����������01.01.�ж��ַ��Ƿ�Ψһ
// �ⷨ1����ϣ��
// д��1
class Solution0101_1_1
{
public:
    bool isUnique(string astr)
    {
        int hash[128] = {0};
        // ͳ�Ƹ���
        for (auto ch: astr)
        {
            hash[ch]++;
        }

        // �ж��Ƿ����ĳһ���ַ����ָ�������1
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

// д��2
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

// �ⷨ2��λ����
class Solution0101_2_1
{
public:
    bool isUnique(string astr)
    {
        int ans = 0;

        // λͼ˼��
        for (auto ch: astr)
        {
            // �ж�ָ��λ���Ƿ��Ѿ�Ϊ1
            if ((ans >> ((int) (ch - 'a'))) & 1)
            {
                return false;
            }
            // ��ָ��λ����Ϊ1
            ans |= (1 << (int) (ch - 'a'));
        }

        return true;
    }
};

// �Ż��汾
// ʹ�ø볲ԭ���Ż�
class Solution0101_2_2
{
public:
    bool isUnique(string astr)
    {
        // ʹ�ø볲ԭ��
        // �ַ������ȴ���26һ�������ظ�
        if (astr.size() > 26)
        {
            return false;
        }
        int ans = 0;

        // λͼ˼��
        for (auto ch: astr)
        {
            // �ж�ָ��λ���Ƿ��Ѿ�Ϊ1
            if ((ans >> ((int) (ch - 'a'))) & 1)
            {
                return false;
            }
            // ��ָ��λ����Ϊ1
            ans |= (1 << (int) (ch - 'a'));
        }

        return true;
    }
};

// ����268.��ʧ������
// �ⷨ1����ϣ��
class Solution268_1
{
public:
    int missingNumber(vector<int> &nums)
    {
        // �����ϣ
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

// �ⷨ2���Ȳ�����
class Solution268_2
{
public:
    int missingNumber(vector<int> &nums)
    {
        // �Ȳ�����
        int sum = (0 + nums.size()) * (nums.size() + 1) / 2;

        return sum - accumulate(nums.begin(), nums.end(), 0);
    }
};

// �������
class Solution268_3
{
public:
    int missingNumber(vector<int> &nums)
    {
        int xorSum = 0;
        // �����������
        for (auto n: nums)
        {
            xorSum ^= n;
        }

        // ö�ٳ��ȸ�����
        for (int i = 0; i <= nums.size(); i++)
        {
            xorSum ^= i;
        }

        return xorSum;
    }
};

// ����371.������֮��
// �������
class Solution371_1
{
public:
    int getSum(int a, int b)
    {
        return a + b;
    }
};

// ������㣨�޽�λ��ӣ�+��λ��+����һλ����ȡ��λ��
class Solution371_2
{
public:
    int getSum(int a, int b)
    {
        // ������㣺�޽�λ���
        int xorSum = a ^ b;
        // ��ȡ��λ
        // int carry = (a & b) << 1;
        // ��ֹ�ƶ���������δ������Ϊ���Խ�ԭ��ֵ���͸�Ϊ�޷���
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

// ����������17.19.��ʧ����������
// �ⷨ1����ϣ��
// ��Ҫע�⣬��Ϊȱʧ������ֵ�����Կ��ٵĿռ�������ԭ����ĳ���+3��ԭ��ͼ����
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

// �ⷨ2��λ����
// ��ԭ������������������ֵ����Ŀת��Ϊ����ʧ������+ֻ����һ�ε����֢�
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

// �汾2�����޸�ԭ����
class Solution17_19_2_1
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        int sz = nums.size();
        int ans = 0;
        // �Ȼ�ȡ����������һ�ε�����
        for (auto n: nums)
        {
            ans ^= n;
        }
        for (int i = 1; i <= nums.size() + 2; i++)
        {
            ans ^= i;
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
