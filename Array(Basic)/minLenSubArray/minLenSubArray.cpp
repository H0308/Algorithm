//
// Created by 18483 on 2024/10/22.
//
#include <iostream>
#include <vector>
// 力扣209.长度最小的子数组
// 暴力解法，见网站
/*
 * 暴力解法基本思路：
 * 外层循环固定为起始位置，内层循环固定为终止位置
 * 通过内层循环的不断进行一直计算sum以及子数组长度
 * 当sum>=target时就跳出内层循环更新外层循环，内层循环再从外层循环下标位置继续寻找
 * 这里内层循环不要从头开始，否则内层循环和外层循环构成的区间并不是有效区间，例如i=1,j=0，构成的区间为[1,0]
 */
// 双指针——滑动窗口算法
/*
 * 滑动窗口的本质还是双指针，之所以叫滑动窗口本质就是通过终止位置的不断移动，
 * 满足条件时不断更新起始位置直到条件重新不成立，再继续更新终止位置
 * 对于本题而言，暴力解法中的循环主要以起始位置为主，所以导致循环复杂度增加
 */
class Solution209 {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int start = 0;
        int len = INT_MAX; // 定义为最大值可以确保比较时一定可以取到最小值
        int sum = 0;
        for(int end = 0; end < nums.size(); end++)
        {
            // 通过end移动计算起始位置和终止位置区间的和sum
            sum += nums[end];
            // 如果sum大于等于target，说明已经找到符合条件的子数组，可以更新sum和start，准备下一次寻找子数组
            // 此处需要循环判断sum是否在start更新时依旧满足sum>=target，不满足时再更新end继续计算和
            // 否则就相当于移出窗口
            while(sum >= target)
            {
                // 先计算当前满足条件时的下标
                len = std::min(len, end - start + 1);
                // 更新start和sum
                sum -= nums[start];
                start++;
            }
        }

        // 如果不存在指定的子数组，则返回0
        if(len == INT_MAX)
        {
            return 0;
        }

        return len;
    }
};