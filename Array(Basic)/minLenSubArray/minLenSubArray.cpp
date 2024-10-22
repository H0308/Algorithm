//
// Created by 18483 on 2024/10/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
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
class Solution209
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int start = 0;
        int len = INT_MAX; // 定义为最大值可以确保比较时一定可以取到最小值
        int sum = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            // 通过end移动计算起始位置和终止位置区间的和sum
            sum += nums[end];
            // 如果sum大于等于target，说明已经找到符合条件的子数组，可以更新sum和start，准备下一次寻找子数组
            // 此处需要循环判断sum是否在start更新时依旧满足sum>=target，不满足时再更新end继续计算和
            // 否则就相当于移出窗口
            while (sum >= target)
            {
                // 先计算当前满足条件时的下标
                len = std::min(len, end - start + 1);
                // 更新start和sum
                sum -= nums[start];
                start++;
            }
        }

        // 如果不存在指定的子数组，则返回0
        if (len == INT_MAX)
        {
            return 0;
        }

        return len;
    }
};

// 力扣904.水果成篮
/*
 * 根据题目的描述，可以联想出本题涉及到一个窗口的进入和更新
 * 窗口进入：当前元素不存在时，插入到当前容器
 * 窗口更新：当元素个数超过两个时，考虑更新窗口直到重新满足条件
 * 本题并没有提到每一个元素只出现一次，但是需要确保容器中只有两个元素，所以需要用到可以去重的容器
 * 可以选择的结构：红黑树，容器对应的就是set和map，也可以考虑使用unordered_map或者unordered_set
 * 但是在更新窗口时，如果直接删除容器中的元素可能会因为每一个元素不止出现一次导致提前更新窗口
 * 例如[3,3,3,1,2,1,1,2,3,3,4]，如果直接使用一个红黑树容器，在插入时3,1,2，此时size为3需要更新窗口
 * 进入循环更新逻辑时，因为没有对元素进行计数，导致set直接删除start指向的第一个3，现在size重新回到2，循环提前结束
 * 所以可以考虑使用map或者unordered_map，如果元素不存在直接插入，否则只更新计数器
 * 最后，更新计数器不可以在更新窗口中更新，因为不能确定一定会出现3种水果
 */
class Solution904
{
public:
    int totalFruit(std::vector<int> &fruits)
    {
        int start = 0;
        int len = 0;
        std::unordered_map<int, int> m;  // 使用unordered_map，查找的时间复杂度为O(1)
        for (int end = 0; end < fruits.size(); end++)
        {
            // 确定元素是否存在，不存在就添加
            m[fruits[end]]++;
            // 当不满足条件：两个篮子中的水果种类大于2种时调整窗口
            while (m.size() > 2)
            {
                // 直到指定元素的计数器为0时才删除，否则一直减少计数器
                if ((--(m.find(fruits[start])->second)) == 0)
                {
                    m.erase(fruits[start]);
                }
                // 更新窗口
                start++;
            }

            // 更新长度
            len = std::max(len, end - start + 1);
        }

        return len;
    }
};

// 力扣76.最小覆盖子串
