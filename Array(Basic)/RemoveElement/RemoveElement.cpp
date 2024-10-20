//
// Created by 18483 on 2024/10/20.
//

#include <vector>
#include <algorithm>
// 力扣27.移除元素
// 暴力解法，见网站
// 双指针解法
class Solution27 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // 双指针解法
        // int count = 0;
        int fast = 0, slow = 0;
        while(fast < nums.size())
        {
            if(nums[fast] != val)
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
class Solution26 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // 双指针解法
        int size = nums.size();
        int slow = 0;
        int fast = 0;
        while(fast < nums.size())
        {
            if(nums[fast] != nums[slow])
            {
                // slow+1防止越界
                if(slow + 1 < nums.size())
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
class Solution283 {
public:
    void moveZeroes(std::vector<int>& nums) {
        int prev = 0, cur = 0;
        while(cur < nums.size())
        {
            if(nums[cur])
                std::swap(nums[cur++], nums[prev++]);
            else
                cur++;
        }
    }
};

// 力扣844.比较含退格的字符


// 力扣977.有序数组的平方
class Solution977_1 {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        // 尾插+排序
        std::vector<int> ret;
        for(auto num : nums)
        {
            ret.push_back(num * num);
        }
        std::sort(ret.begin(), ret.end());
        return ret;
    }
};