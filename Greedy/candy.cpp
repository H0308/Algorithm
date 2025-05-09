//
// Created by 18483 on 2025/2/7.
//
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 力扣135.分发糖果
/*
 * 本题的基本思路可以说是根据题目要求进行模拟更改糖果的数量，但是需要注意，本题因为既要考虑当前位置比其左侧孩子大时，当前位置的糖果较多，也要考虑当前位置比其右侧孩子大时，当前位置的糖果较多
 * 所以本题实际上要考虑两边的情况，对于这种需要考虑两边的情况时，不建议一次性同时考虑两边，而是先考虑一边，再利用已经考虑过的结果反向遍历考虑另一边
 * 这里需要注意，考虑第二边不可以是正向遍历，因为第二边本质是要找到最右侧不符合条件的情况，如果依旧是正向遍历，就相当于从第一边考虑第二种情况
 * 例如[1,2,2,5,4,3,2]
 * 第一遍计算糖果如下
 * 原始：[1,2,2,5,4,3,2]
 * 计算：[1,2,1,2,1,1,1]
 * 第二遍计算糖果如下
 * 正向：[1,2,1,2,2,2,1]
 * 逆向：[1,2,1,4,3,2,1]
 * 很明显，在第二边正向中，因为5>4，所以5的位置需要更新到4的糖果数量+1的结果，也就是2，同理可得后面的元素，但是如果是逆向，就是先处理第一个不满足条件的情况，再依次处理第二个乃至最后一个
 * 另外还需要注意，在考虑第二边时，需要取计算糖果和原始糖果的最大值作为新糖果值，防止出现例如[1,3,4,5,2]，第一边处理结果为[1,2,3,4,1]，因为此时在第二边没处理，如果没有取最大值就会导致[...5,2]时，5的位置被覆盖为2的糖果数量1+1覆盖第一边的4的情况导致错误
 */
class Solution135
{
public:
    int candy(vector<int> &ratings)
    {
        // 先给每个孩子都发一颗糖，总糖量即为数组长度
        vector<int> totalCandy(ratings.size(), 1);

        // 先正向遍历，考虑左侧比右侧大的情况
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                totalCandy[i] = totalCandy[i - 1] + 1;
        }

        // 再反向遍历，考虑右侧比左侧小的情况
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                totalCandy[i] = max(totalCandy[i + 1] + 1, totalCandy[i]);
        }

        return accumulate(totalCandy.begin(), totalCandy.end(), 0);
    }
};
