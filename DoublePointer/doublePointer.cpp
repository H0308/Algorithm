//
// Created by 18483 on 2024/11/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 力扣80.删除有序数组中的重复项Ⅱ
// 双指针，根据下标相差为2控制只保留两个重复数字
class Solution80
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() <= 2)
            return nums.size();
        int slow = 2, fast = 2;

        while(fast < nums.size())
        {
            if(nums[slow - 2] != nums[fast])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};

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
class Solution11
{
public:
    int maxArea(vector<int> &height)
    {
        int maxV = 0;
        for (int left = 0, right = height.size() - 1; left < right;)
        {
            while (left < right && height[left] <= height[right])
            {
                // 必须先计算体积，防止漏计算
                maxV = max(maxV, (right - left) * height[left]);
                left++;
            }

            while (left < right && height[left] > height[right])
            {
                maxV = max(maxV, (right - left) * height[right]);
                right--;
            }
        }

        return maxV;
    }
};

// 力扣611.有效三角形的个数
// 先排序使其具有单调性
// 固定一个第三边，但是这个第三边不能是起始位置的值
// 固定到起始位置就无法使用单调性解决
class Solution611
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int left = 0, right = i - 1; left <= right;)
            {
                if (nums[right] + nums[left] > nums[i])
                {
                    count += right - left;
                    right--;
                }
                else
                    left++;
            }
        }

        return count;
    }
};

// 力扣LCR179.查找总价格为目标值的两个商品
// 放在两数之和下面，属于两数之和双指针思路解法的正确性判断
class SolutionLCR179
{
public:
    vector<int> twoSum(vector<int> &price, int target)
    {
        for (int left = 0, right = price.size() - 1; left < right;)
        {
            if (price[left] + price[right] > target)
                right--;
            else if (price[left] + price[right] < target)
                left++;
            else
                return {price[left], price[right]};
        }

        return {};
    }
};

// 力扣15.三数之和
// 本题与前面有效三角形的思路一致，但是需要进行去重
// 因为已经排序，所以对于和为0的三个数来说，一旦出现重复
// 则一定在一起，所以可以一直跳过直到不出现重复数值
class Solution15
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 记录结果
        vector<vector<int>> ret;
        // 排序数组
        sort(nums.begin(), nums.end());

        // 枚举最大值
        for (int i = nums.size() - 1; i >= 0;)
        {
            for (int left = 0, right = i - 1; left < right;)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else
                {
                    ret.push_back({nums[left], nums[right], nums[i]});
                    // 更新到新加数
                    left++;
                    right--;
                    // 对left和right区间中去重，注意越界问题的处理
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (right > left && nums[right] == nums[right + 1])
                        right--;
                }
            }

            i--;
            // 对基数去重，注意越界问题的处理
            while (i >= 0 && nums[i] == nums[i + 1])
                i--;
        }

        return ret;
    }
};

// 力扣18.四数之和
// 本题和上题思路一致，但是因为是四个数，所以需要通过i和j枚举两个值
// nums[i] + nums[j] = -(nums[left] + nums[right])
class Solution18
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz;)
        {
            //  三数之和思路
            for (int j = i + 1; j < sz;)
            {
                // 注意整型范围
                long long rest = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = sz - 1;
                // 两数之和思路
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum > rest)
                        right--;
                    else if (sum < rest)
                        left++;
                    else
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
                j++;
                while (j < sz && nums[j] == nums[j - 1])
                    j++;
            }
            i++;
            while (i < sz && nums[i] == nums[i - 1])
                i++;
        }
        return ret;
    }
};