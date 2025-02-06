//
// Created by 18483 on 2025/2/6.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣55.跳跃游戏
/*
 * 本题的基本思路就是找到可以走到结尾的步数，为了可以走到结尾，所以步数要尽可能得大，而要使步数尽可能大，局部最优就是每一次走的步数尽可能大
 * 从第一步开始，如果下一个元素大于剩余的步数，就直接更新步数，否则就继续向下走
 * 如果走到元素为0的位置时，存在三种情况：
 * 1. 已经是最后一个元素
 * 2. 步数没有走完
 * 3. 步数走完并且没有到最后一个元素
 * 根据上面三种情况可以得出只有最后一种情况是需要返回false的，其他均返回true
 */
class Solution55
{
public:
    bool canJump(vector<int> &nums)
    {
        int last = nums.size() - 1;
        int step = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            step--;

            // 每次贪较大的步数，使可以走的步数尽可能多
            if (nums[i] > step)
                step = nums[i];

            // 步数走完并且没有到最后一个元素
            if (step <= 0 && i < last)
                return false;
        }

        return true;
    }
};
