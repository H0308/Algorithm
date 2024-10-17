#include <iostream>
#include <vector>

// 左闭右开原则
// 返回指定元素的下标
int BinarySearch(std::vector<int> &nums, int target)
{
    // 左闭右开原则：[left, right]区间中所有值均在vector内有效
    int left = 0;
    int right = nums.size() - 1;

    // left <= right, 因为当left==right时，nums[left] == nums[right]有效，此时是最后一次判断
    while (left <= right)
    {
        // 计算出中间值
        int mid = (left + right) / 2;
        // 判断是否取到指定值
        if (nums[mid] == target) // 相等——返回
        {
            return mid; // 返回指定值下标
        }
        else if (nums[mid] > target) // 中间值较大——target一定在中间值左边
        {
            // 左闭右开原则，此时nums[mid]一定不是target
            right = mid - 1;
        }
        else if (nums[mid] < target) // 中间值较小——target一定在中间值右边
        {
            // 左闭右开原则，此时nums[mid]一定不是target
            left = mid + 1;
        }
    }

    // 约定没找到返回-1
    return -1;
}

int main()
{
    int target = 0;
    std::cin >> target;
    std::vector<int> v{2, 3, 34, 23, 90, 36, 22, 123, 45};
    int pos = BinarySearch(v, target);
    if (pos != -1)
        std::cout << "数值不存在" << std::endl;
    else
        std::cout << "数值存在" << std::endl;

    return 0;
}
