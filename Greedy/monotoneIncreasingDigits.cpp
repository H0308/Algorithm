//
// Created by 18483 on 2025/2/9.
//
#include <iostream>

using namespace std;

// 力扣738.单调递增的数字
/*
 * 本题的思路就是判断当前位置的值是否比前一位值大或者相等，如果不满足这个条件说明需要更新
 * 更新的方式就是前一位减小1个单位，当前位修改为9，之所以当前位需要修改为9是因为如果不满足单调递增，就需要取出小于等于当前数值的最大数值
 * 需要注意本题的细节：
 * 1. 将数值转换为字符串而非取出每个数字插入到数组中，这样可以快速地得到可以用下标操作的字符串数组
 * 2. 逆序遍历字符串数组，这样可以确保从后向前，让下一次的比较可以利用到上一次的比较结果
 * 3. 在找到需要修改为9的位置时并不是直接修改，而是先标记需要修改为9的起始位置，这样可以确保遇到类似1000的数值时可以正确处理，因为后两位满足小于等于的条件，但是10不满足，如果直接修改为9，就会出现最后值为900而不是999
 * 4. 用于标记9的起始位置变量初始化为字符串数组的长度而不是其他值，防止出现本身已经满足单调递增的条件的数值全部被覆盖为9
 */
class Solution738
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // 将数值转换为字符串方便当做数组处理
        string str = to_string(n);

        // 记录需要转换为9的起始位置标记
        // 初始化为数组长度是为了防止n已经满足单调递增的条件而误操作填充为9
        int start = str.size();

        for (int i = str.size() - 1; i > 0; i--)
        {
            // 如果当前位比上一位小，说明当前没有满足单调递增的条件
            if (str[i - 1] > str[i])
            {
                // 前一位直接减1操作
                // 注意这里减1一定是合法的，因为如果不满足单调递增条件，那么前一位一定是大于0的值，并且小于等于9
                // 所以肯定不会减到非数值字符
                str[i - 1]--;
                // 更新起始需要替换为字符9的起始位置
                start = i;
            }
        }

        // 从标记位开始，将对应的字符替换为9
        for (int i = start; i < str.size(); i++)
            str[i] = '9';

        return stoi(str);
    }
};
