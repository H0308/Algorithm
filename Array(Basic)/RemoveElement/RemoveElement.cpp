//
// Created by 18483 on 2024/10/20.
//

#include <vector>
#include <algorithm>
#include <string>
// 力扣27.移除元素
// 暴力解法，见网站
// 双指针解法
class Solution27
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        // 双指针解法
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
        // 也可以不用计数器，直接返回slow
        return slow;
    }
};

// 力扣26.删除有序数组中的重复项
class Solution26
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        // 双指针解法
        int size = nums.size();
        int slow = 0;
        int fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow])
            {
                // slow+1防止越界
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

// 力扣283.移动零
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

// 力扣844.比较含退格的字符
// 暴力解法——注意string类也有尾删操作
class Solution844_1
{
public:
    std::string remove(std::string s)
    {
        // 暴力解法
        std::string ret;
        for (auto str: s)
        {
            if (str != '#')
            {
                ret.push_back(str);
            }
            else if (!ret.empty())
            {
                // string的尾删方法pop_back
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

// 双指针算法
/*
 * 为什么：判断两个数组内容是否相等，可以定义指向两个数组的指针依次比较每一个字符
 * 如何用：本题涉及到退格符#，所以需要额外遇到#时候的情况，因为#只会影响左侧的字符而不会影响右侧的字符
 * 所以考虑从后往前遍历，但是考虑到#可能与下一个要删除的字符不是紧挨着，所以需要考虑使用一个计数器记录#的个数
 * 在遍历过程中，分为三种情况：
 * 1. 当#计数器为0，直接判断两个数组中的当前字符是否相等，不等则直接返回false，这里需要考虑其中一个可能是空数组
 * 2. 当有一方#计数器不为0，则让该方的下标指针向前移动，直到移动到计数器为0为止
 * 3. 如果当前字符是#，则#计数器加1，并且下标指针向前移动
 */
class Solution844_2
{
public:
    bool backspaceCompare(std::string s, std::string t)
    {
        int si = s.size() - 1, ti = t.size() - 1;
        int skips = 0, skipt = 0;

        // 确保至少有一方有内容
        while (si >= 0 || ti >= 0)
        {
            // 遍历第一个字符数组
            while (si >= 0)
            {
                if (s[si] == '#')
                {
                    // 第三种情况
                    skips++;
                    si--;
                }
                else if (skips > 0)
                {
                    // 第二种情况
                    si--;
                    skips--;
                }
                else
                {
                    // 第一种情况
                    break;
                }
            }
            // 遍历第二个字符数组
            while (ti >= 0)
            {
                if (t[ti] == '#')
                {
                    // 第三种情况
                    skipt++;
                    ti--;
                }
                else if (skipt > 0)
                {
                    // 第二种情况
                    ti--;
                    skipt--;
                }
                else
                {
                    // 第一种情况
                    break;
                }
            }

            // 判断两个字符串当前字符是否相等
            // 必须确保两个字符串都有字符才进行当前字符是否相等的比较
            if (si >= 0 && ti >= 0)
            {
                if (s[si] != t[ti])
                {
                    return false;
                }
            }
            else
            {
                // 如果有一个字符数组为空，则直接返回false
                if (si >= 0 || ti >= 0)
                {
                    return false;
                }
            }
            si--;
            ti--;
        }

        // 循环全部走完说明相同
        return true;
    }
};

// 力扣977.有序数组的平方
// 尾插+排序
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

// 双指针算法（但非原地处理）
/*
 * 为什么：本题中存在负数，并且数组是非递减顺序，
 * 所以最大值只有可能出现在最左侧（负数数值越小，平方后越大）和最右侧（正数数值越大，平方后越大）
 * 并且平方值向数组中间依次减小
 * 怎么做：考虑双指针异地处理，比较左指针和右指针对应的值的平方，大的就尾插到异地的数组中
 * 为了避免使用insert函数产生额外的时间复杂度，可以考虑提前开辟空间，并使用一个指针，起始位置指向异地数组的最后一个元素的位置
 */
// 左闭右闭区间
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

// 左闭右开区间
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
