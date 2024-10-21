//
// Created by 18483 on 2024/10/20.
//

#include <vector>
#include <algorithm>
#include <string>
// ����27.�Ƴ�Ԫ��
// �����ⷨ������վ
// ˫ָ��ⷨ
class Solution27
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        // ˫ָ��ⷨ
        // int count = 0;
        int fast = 0, slow = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        // return count;
        // Ҳ���Բ��ü�������ֱ�ӷ���slow
        return slow;
    }
};

// ����26.ɾ�����������е��ظ���
class Solution26
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        // ˫ָ��ⷨ
        int size = nums.size();
        int slow = 0;
        int fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow])
            {
                // slow+1��ֹԽ��
                if (slow + 1 < nums.size())
                {
                    nums[slow + 1] = nums[fast];
                }
                slow++;
            }
            fast++;
        }

        return slow + 1;
    }
};

// ����283.�ƶ���
class Solution283
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int prev = 0, cur = 0;
        while (cur < nums.size())
        {
            if (nums[cur])
                std::swap(nums[cur++], nums[prev++]);
            else
                cur++;
        }
    }
};

// ����844.�ȽϺ��˸���ַ�
// �����ⷨ����ע��string��Ҳ��βɾ����
class Solution844_1
{
public:
    std::string remove(std::string s)
    {
        // �����ⷨ
        std::string ret;
        for (auto str: s)
        {
            if (str != '#')
            {
                ret.push_back(str);
            }
            else if (!ret.empty())
            {
                // string��βɾ����pop_back
                ret.pop_back();
            }
        }

        return ret;
    }

    bool backspaceCompare(std::string s, std::string t)
    {
        return remove(s) == remove(t);
    }
};

// ˫ָ���㷨
/*
 * Ϊʲô���ж��������������Ƿ���ȣ����Զ���ָ�����������ָ�����αȽ�ÿһ���ַ�
 * ����ã������漰���˸��#��������Ҫ��������#ʱ����������Ϊ#ֻ��Ӱ�������ַ�������Ӱ���Ҳ���ַ�
 * ���Կ��ǴӺ���ǰ���������ǿ��ǵ�#��������һ��Ҫɾ�����ַ����ǽ����ţ�������Ҫ����ʹ��һ����������¼#�ĸ���
 * �ڱ��������У���Ϊ���������
 * 1. ��#������Ϊ0��ֱ���ж����������еĵ�ǰ�ַ��Ƿ���ȣ�������ֱ�ӷ���false��������Ҫ��������һ�������ǿ�����
 * 2. ����һ��#��������Ϊ0�����ø÷����±�ָ����ǰ�ƶ���ֱ���ƶ���������Ϊ0Ϊֹ
 * 3. �����ǰ�ַ���#����#��������1�������±�ָ����ǰ�ƶ�
 */
class Solution844_2
{
public:
    bool backspaceCompare(std::string s, std::string t)
    {
        int si = s.size() - 1, ti = t.size() - 1;
        int skips = 0, skipt = 0;

        // ȷ��������һ��������
        while (si >= 0 || ti >= 0)
        {
            // ������һ���ַ�����
            while (si >= 0)
            {
                if (s[si] == '#')
                {
                    // ���������
                    skips++;
                    si--;
                }
                else if (skips > 0)
                {
                    // �ڶ������
                    si--;
                    skips--;
                }
                else
                {
                    // ��һ�����
                    break;
                }
            }
            // �����ڶ����ַ�����
            while (ti >= 0)
            {
                if (t[ti] == '#')
                {
                    // ���������
                    skipt++;
                    ti--;
                }
                else if (skipt > 0)
                {
                    // �ڶ������
                    ti--;
                    skipt--;
                }
                else
                {
                    // ��һ�����
                    break;
                }
            }

            // �ж������ַ�����ǰ�ַ��Ƿ����
            // ����ȷ�������ַ��������ַ��Ž��е�ǰ�ַ��Ƿ���ȵıȽ�
            if (si >= 0 && ti >= 0)
            {
                if (s[si] != t[ti])
                {
                    return false;
                }
            }
            else
            {
                // �����һ���ַ�����Ϊ�գ���ֱ�ӷ���false
                if (si >= 0 || ti >= 0)
                {
                    return false;
                }
            }
            si--;
            ti--;
        }

        // ѭ��ȫ������˵����ͬ
        return true;
    }
};

// ����977.���������ƽ��
// β��+����
class Solution977_1
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        std::vector<int> ret;
        for (auto num: nums)
        {
            ret.push_back(num * num);
        }
        std::sort(ret.begin(), ret.end());
        return ret;
    }
};

// ˫ָ���㷨������ԭ�ش���
/*
 * Ϊʲô�������д��ڸ��������������Ƿǵݼ�˳��
 * �������ֵֻ�п��ܳ���������ࣨ������ֵԽС��ƽ����Խ�󣩺����Ҳࣨ������ֵԽ��ƽ����Խ��
 * ����ƽ��ֵ�������м����μ�С
 * ��ô��������˫ָ����ش����Ƚ���ָ�����ָ���Ӧ��ֵ��ƽ������ľ�β�嵽��ص�������
 * Ϊ�˱���ʹ��insert�������������ʱ�临�Ӷȣ����Կ�����ǰ���ٿռ䣬��ʹ��һ��ָ�룬��ʼλ��ָ�������������һ��Ԫ�ص�λ��
 */
// ����ұ�����
class Solution977_2
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        std::vector<int> ret(nums.size());
        int reti = ret.size() - 1;
        while (left <= right)
        {
            int num1 = nums[left] * nums[left];
            int num2 = nums[right] * nums[right];
            if (num1 < num2)
            {
                ret[reti--] = num2;
                right--;
            }
            else
            {
                ret[reti--] = num1;
                left++;
            }
        }

        return ret;
    }
};

// ����ҿ�����
class Solution977_3
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        int left = 0, right = nums.size();
        std::vector<int> ret(nums.size());
        int reti = ret.size() - 1;
        while (left < right)
        {
            int num1 = nums[left] * nums[left];
            int num2 = nums[right - 1] * nums[right - 1];
            if (num1 < num2)
            {
                ret[reti--] = num2;
                right--;
            }
            else
            {
                ret[reti--] = num1;
                left++;
            }
        }

        return ret;
    }
};
