//
// Created by 18483 on 2025/2/17.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣509.斐波那契数
/*
 * 常规解法：递归
 */
class Solution509_1
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

/*
 * 动态规划5步思考：
 * 1. 确定dp数组每一个元素和其对应下标的含义：在本题中，dp数组就是保存了所有斐波那契数的数组，每一个下标i表示第i个位置的斐波那契数
 * 2. 确定递推公式：本题已经给定了递推公式：dp[i] = dp[i - 1] + dp[i - 2]
 * 3. 确定如何初始化：本题已经给定了dp[0] = 0，dp[1] = 1，并且根据递推公式只需要初始化dp[0]和dp[1]这两个即可求出剩余的斐波那契数
 * 4. 确定遍历顺序：因为要求第n个斐波那契数，所以只需要正向从第三个元素开始遍历到n即可求出第n个位置的斐波那契数，对应地此时dp数组就应该初始化为n + 1，而不是n，不然会出现越界问题
 * 5. 打印dp数组确保dp数组符合预期
 */
class Solution509_2
{
public:
    int fib(int n)
    {
        // 边界处理
        if (n == 0)
            return 0;

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

/*
 * 空间优化：
 *
 * 通过本题的含义可以发现当前位置的状态可以通过该位置的前两个状态推出，并且前两个状态之前的状态可以忽略时，可以考虑使用滚动数组进行空间优化
 * 即通过3个变量，分别表示当前位置的值cur，前一个位置的值prev和前一个位置的前一个位置的值prevPrev
 * 通过这三个变量的不断改变就可以得到当前位置
 */
class Solution509_3
{
public:
    int fib(int n)
    {
        // 边界处理
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;

        int cur = 0;
        int prev = 1;
        int prevPrev = 0;

        for (int i = 2; i <= n; i++)
        {
            // 计算当前位置值
            cur = prev + prevPrev;
            // 更新前一个位置的前一个位置
            prevPrev = prev;
            // 更新前一个位置
            prev = cur;
        }

        return cur;
    }
};
