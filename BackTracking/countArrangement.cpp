//
// Created by 18483 on 2025/1/20.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣526.优美的排列
/*
 * 本题的基本思路就是根据优美排列的规则枚举所有可能的情况，但是需要注意，根据给定个数n，第一个位置有n种情况，第二个位置有n-1种情况，以此类推
 * 所以此时就需要涉及到树枝去重，防止在同一个优美排列结果中出现一个数字使用两次的情况
 * 另外，当一个数值无法满足优美排列的条件，就需要枚举后面的值而不是直接跳出循环
 */
class Solution526
{
public:
    int count = 0;

    void backtracking(int n, int index, vector<bool> &used)
    {
        // index大于n时说明已经到达叶子节点
        if (index > n)
        {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            // 判断当前值是否可以满足优美排列条件之一
            // 满足就可以继续进行递归，否则当前条件直接排除
            if (i % index == 0 || index % i == 0)
            {
                if (used[i])
                    continue;

                used[i] = true;
                backtracking(n, index + 1, used);
                used[i] = false;
            }
            else
                continue; // 当前值不满足优美排列，继续枚举后面的值
        }
    }

    int countArrangement(int n)
    {
        vector<bool> used(n + 1, false);
        backtracking(n, 1, used);

        return count;
    }
};
