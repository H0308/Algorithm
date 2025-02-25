#include "BinarySearch.h"

// 左闭右闭原则
// 返回指定元素的下标
int Array_Basic::BinarySearch(std::vector<int> &nums, int target, int flag)
{
    // 使用(void)强制转换防止编译器警告，flag在二分查找中没有意义
    (void) flag;
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
        // int mid = left + ((right - left) >> 1);
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
int Array_Basic::BinarySearch(std::vector<int> &nums, int target)
{
    std::cout << "[left, right)" << std::endl;
    // 左闭右开原则：[left, right)，此时当left==right时就是无效区间
    int left = 0;
    int right = nums.size();

    // 因为left==right是无效区间，所以left不可以等于right
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target) // 相等——返回
        {
            return mid;
        }
        else if (nums[mid] > target) // 中间值较大，则目标值一定在中间值右边
        {
            // 左闭右开原则，此时mid的值是下一次的右边界，不包括mid的值
            right = mid;
        }
        else if (nums[mid] < target) // 中间值较小，则目标值一定在中间值左边
        {
            // 左边右开原则，此时mid的值是下一次的左边界，包括mid的值
            left = mid + 1;
        }
    }

    // 没找到指定值返回-1
    return -1;
}

// 力扣35.搜索插入位置
class Solution35
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
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

// 力扣69.x的平方根
/*
 * 二分查找：
 * 为什么：在枚举小于x的每一个整数时，最小的算术平方根是0，依次增大，满足二分查找的调节：有序且严格递增
 * 怎么用：最小的算术平方根是0，所以起点为0，而需要判断的是当前枚举的数值是否为k*k<=x，
 * 而因为x的算术平方根肯定在[0, x]区间中，所以需要枚举0到x中的数值。
 * 假设将0到x个数值看做一个数组，则取出当前数组的中间元素，
 * 判断中间元素mid*mid是否<=x，小于说明需要移动left，否则移动right
 * 怎么写：
 */
class Solution69
{
public:
    int mySqrt(int x)
    {
        // 暴力解法
        // size_t ans = 0;
        // for(;ans * ans <= x; ans++);
        // return (ans - 1);
        size_t left = 0;
        size_t right = x;
        size_t ans = 0;
        // 左闭右闭区间
        while (left <= right)
        {
            size_t mid = left + ((right - left) >> 1);
            // 可能无法刚刚好等于
            // if(ans == x)
            // {
            //     ans = mid;
            //     break;
            // }
            if (mid * mid <= x) // 中间值较小
            {
                ans = mid;
                left = mid + 1;
            }
            else if (mid * mid > x) // 中间值较大
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};

// 类似69题型：力扣367.有效的完全平方数
class Solution367
{
public:
    bool isPerfectSquare(int num)
    {
        size_t left = 0;
        size_t right = num;
        size_t ans = 0;
        // 左闭右闭区间
        while (left <= right)
        {
            size_t mid = left + ((right - left) >> 1);
            if (mid * mid <= num)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans * ans == num;
    }
};

// 力扣34.在排序数组中查找元素的第一个和最后一个位置
/*
 * 本题思路：
 * 二分查找
 * 为什么：题目提到数组是升序但非递减，所以直接找target肯定结果不唯一，但是本题需要找的是第一个和最后一个位置对应的下标
 * 所以可以考虑设定两个一定不存在的边界值，使用二分查找设定边界，因为是整型数组，所以一定不存在的值肯定是浮点数
 * 怎么找：首先判断target是否存在于原数组，不存在返回{-1, -1}，此处就可以直接使用二分查找，至少找到一个有效位置即可，
 * 如果存在则继续使用两次二分查找，第一次二分查找找左边界，第二次找右边界即可
 */
class Solution34_1
{
public:
    // 二分查找
    int BinarySearch(std::vector<int> &nums, double target)
    {
        int left = 0;
        int right = nums.size();

        // 左闭右开区间
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        // 存在则继续
        // 找左边界
        int leftHand = BinarySearch(nums, target - 0.5);
        // 找右边界
        int rightHand = BinarySearch(nums, target + 0.5);
        // 判断target是否存在于nums中

        // if(leftHand >= nums.size() || nums[leftHand] != target)
        // {
        //     return {-1, -1};
        // }
        // return {leftHand, rightHand - 1};

        // 上面的代码也可以按照下面的形式写，但是注意不可以省略指定类型的vector<int>，因为此时编译器无法确定{-1, -1}和{leftHand, rightHand - 1}是否是同一个类型
        return leftHand >= nums.size() || nums[leftHand] != target
                   ? std::vector<int>{-1, -1}
                   : std::vector<int>{leftHand, rightHand - 1};
    }
};

// 直接找到左右边界
class Solution34_2
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();

        // 左闭右开区间找左端点
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // <target和>=target
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        // 判断当前left是否为目标值以及是否存在越界
        if (left >= nums.size() || nums[left] != target)
        {
            return {-1, -1};
        }
        // 否则记录当前left
        int begin = left;

        // 左闭右开区间找右端点
        left = 0;
        right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // <=target和>target
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        // 记录右端点的位置
        int last = left - 1;

        return {begin, last};
    }
};

// 牛客类似题目：JZ53 数字在升序数组中出现的次数
#include <vector>

class SolutionJZ53
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param k int整型
     * @return int整型
     */
    // 二分查找
    int BinarySearch(std::vector<int> &nums, double target)
    {
        int left = 0;
        int right = nums.size() - 1;
        // 左闭右闭区间
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }

    int GetNumberOfK(std::vector<int> &nums, int k)
    {
        // 左边界
        int leftHand = BinarySearch(nums, k - 0.5);
        // 右边界
        int rightHand = BinarySearch(nums, k + 0.5);

        return rightHand - leftHand;
    }
};

// C语言版本
namespace solutionJZ53
{
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型一维数组
     * @param numsLen int nums数组长度
     * @param k int整型
     * @return int整型
     */
    //二分查找
    int BinarySearch(int *nums, int numsLen, double k)
    {
        int left = 0;
        int right = numsLen - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > k)
            {
                right = mid - 1;
            }
            else if (nums[mid] < k)
            {
                left = mid + 1;
            }
        }
        //返回 left 而不是 mid
        return left;
    }

    int GetNumberOfK(int *nums, int numsLen, int k)
    {
        return BinarySearch(nums, numsLen, k + 0.5) - BinarySearch(nums, numsLen, k - 0.5);
    }
}

// 力扣852.山脉数组的峰顶索引
// 暴力解法
// 找数组最大值
class Solution852_1
{
public:
    int peakIndexInMountainArray(std::vector<int> &nums)
    {
        int maxIndex = 0;
        for (size_t i = 0; i < nums.size(); i++)
            if (nums[i] > nums[maxIndex])
                maxIndex = i;

        return maxIndex;
    }
};

// 二分查找
class Solution852_2
{
public:
    int peakIndexInMountainArray(std::vector<int> &nums)
    {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

// 力扣162.寻找峰值
// 暴力解法
class Solution162_1
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        // 找数组最小值
        int maxIndex = 0;
        for (size_t i = 0; i < nums.size(); i++)
            if (nums[i] > nums[maxIndex])
                maxIndex = i;

        return maxIndex;
    }
};

// 二分查找
class Solution162_2
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

// 力扣153.寻找旋转排序数组中的最小值
// 暴力解法
class Solution153_1 {
public:
    int findMin(std::vector<int>& nums) {
        // 找数组最小值
        int minIndex = 0;
        for(size_t i = 0 ; i < nums.size(); i++)
            if(nums[i] < nums[minIndex])
                minIndex = i;

        return nums[minIndex];
    }
};

// 二分查找
class Solution153_2 {
public:
    int findMin(const std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size();
        int last = nums[right - 1];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > last)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return nums[left];
    }
};

// LCR 173.点名
// 暴力解法
class SolutionLCR173_1
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        size_t i = 0;
        for(; i <= records.size(); i++)
        {
            // 缺失最后一个值
            if(i == records.size())
            {
                return records.size();
            }
            else if(records[i] != i)
            {
                break;
            }
        }

        return i;
    }
};

// 位运算
class SolutionLRC173_2
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        int ret = 0;
        for(size_t i = 0; i <= records.size(); i++)
        {
            if(i == records.size())
            {
                return records.size();
            }
            else if(records[i] ^ i)
            {
                ret = i;
                break;
            }
        }

        return ret;
    }
};

// 哈希表
class SolutionLCR173_3
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        int hash[10001] = {0};

        for(auto num : records)
        {
            hash[num]++;
        }

        // 遍历哈希表找到为0位置的下标
        int ret = 0;
        for(size_t i = 0; i < 10001; i++)
        {
            if(!hash[i])
            {
                ret = i;
                break;
            }
        }

        return ret;
    }
};

// 等差数列
class SolutionLCR173_4
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        return [&]() -> int{
            int sum = (records.size() + 0) * (records.size() + 1)/2;
            return sum;
        }() -
        std::accumulate(records.begin(), records.end(), 0);
    }
};

// 二分查找
class SolutionLCR173_5
{
public:
    int takeAttendance(std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size();

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};