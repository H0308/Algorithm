#include "BinarySearch.h"

// 左闭右闭原则
// 返回指定元素的下标
int Array_Basic::BinarySearch(std::vector<int> &nums, int target, int flag)
{
    // 使用(void)强制转换防止编译器警告，flag在二分查找中没有意义
    (void)flag;
    std::cout << "[left, right]" << std::endl;
    // 左闭右闭原则：[left, right]区间中所有值均在vector内有效
    int left = 0;
    int right = nums.size() - 1;

    // left <= right, 因为当left==right时，nums[left] == nums[right]有效，此时是最后一次判断
    while (left <= right)
    {
        // 计算出中间值
        // int mid = (left + right) / 2;
        int mid = left + ((right - left) / 2); // 防止溢出——结果等效于上面的写法
        // 除以2也可以使用右移>>
        // int mid = left + ((right - left) >> 2);
        /*
         * 上面的步骤先算出固定不变的间隔值，再通过起始位置加上间隔值间接算出中间值位置
         *  具体步骤如下：
         *  1. 计算 right - left，得到区间的长度
         *  2. 将区间长度除以 2，得到中间值相对于 left 的偏移量
         *  3. 将偏移量加到 left 上，得到中间值的位置
         */
        // 判断是否取到指定值
        if (nums[mid] == target) // 相等——返回
        {
            return mid; // 返回指定值下标
        }
        else if (nums[mid] > target) // 中间值较大——target一定在中间值左边
        {
            // 左闭右闭原则，此时nums[mid]一定不是target
            right = mid - 1;
        }
        else if (nums[mid] < target) // 中间值较小——target一定在中间值右边
        {
            // 左闭右闭原则，此时nums[mid]一定不是target
            left = mid + 1;
        }
    }

    // 约定没找到返回-1
    return -1;
}

// 左闭右开原则
// 返回指定元素的下标
int Array_Basic::BinarySearch(std::vector<int>& nums, int target)
{
    std::cout << "[left, right)" << std::endl;
    // 左闭右开原则：[left, right)，此时当left==right时就是无效区间
    int left = 0;
    int right = nums.size();

    // 因为left==right是无效区间，所以left不可以等于right
    while (left < right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target) // 相等——返回
        {
            return mid;
        }
        else if(nums[mid] > target) // 中间值较大，则目标值一定在中间值右边
        {
            // 左闭右开原则，此时mid的值是下一次的右边界，不包括mid的值
            right = mid;
        }
        else if(nums[mid] < target) // 中间值较小，则目标值一定在中间值左边
        {
            // 左边右开原则，此时mid的值是下一次的左边界，包括mid的值
            left = mid + 1;
        }
    }

    // 没找到指定值返回-1
    return -1;
}

// 力扣35.搜索插入位置
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + ((right - left) >> 1);
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
        }

        // 没找到返回中间值的下一个位置，需要修正数组中存在的位置，如果不存在的位置，则新增的一定是在数组长度位置的元素
        // return target < nums[mid] ? mid: mid + 1;
        // 左闭右闭不能返回right
        // return right;
        return left;
    }
};