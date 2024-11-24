//
// Created by 18483 on 2024/11/24.
//
#include <iostream>
#include <vector>
using namespace std;

// 力扣283.移动零
class Solution283
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

// 力扣1089.复写零
// 解法1：暴力
class Solution1089_1
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                for (int j = arr.size() - 1; j > i; j--)
                    arr[j] = arr[j - 1];
                i++;
            }
        }
    }
};

// 解法2：异地复写
class Solution1089_2
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> nums(arr.size());

        for (int i = 0, j = 0; i < arr.size() && j < nums.size(); i++, j++)
        {
            if (arr[i] == 0 && j + 1 < nums.size())
            {
                nums[j] = nums[j + 1] = 0;
                j++;
            }
            else
                nums[j] = arr[i];
        }

        arr = nums;
    }
};

// 解法3：双指针
class Solution1089_3
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int left = 0;
        int right = -1;

        // 找到待复写的位置
        while (left < arr.size())
        {
            if (arr[left])
                right++;
            else
                right += 2;

            if (right >= arr.size() - 1)
                break;
            left++;
        }

        // 修正边界情况
        if (right == arr.size())
        {
            arr[right - 1] = 0;
            left--;
            right -= 2;
        }

        // 复写
        while (left >= 0)
        {
            if (arr[left])
                arr[right--] = arr[left--];
            else
            {
                arr[right--] = 0;
                arr[right--] = 0;
                left--;
            }
        }
    }
};

// 力扣202.快乐数
// 解法1：哈希表（见哈希表部分）
// 解法2：双指针
class Solution202
{
public:
    int calQrt(int n)
    {
        int temp = n;
        int sum = 0;
        while (temp)
        {
            int r = temp % 10;
            temp /= 10;

            sum += (r * r);
        }

        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        while (slow != 1)
        {
            slow = calQrt(slow);
            fast = calQrt(calQrt(fast));

            if (slow == fast && slow != 1)
                return false;
        }

        return true;
    }
};

// 力扣11.盛最多水的容器
