//
// Created by 18483 on 2025/1/9.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 力扣40.组合总和Ⅱ
/*
 * 本题的基本思路还是计算总和sum等于target的组合，但是因为本题给定的数组存在重复的元素，
 * 所以不但需要注意每一个组合在不考虑元素顺序的情况下不重复以外，还要考虑在获取到不同位置的元素但是元素值前面已经出现过时再次选取导致的组合重复
 * 本题的去重方式可以从两个方面考虑：
 * 1. 树层去重：针对同一层的元素进行去重
 * 2. 树枝去重：针对同一条路径的元素进行去重
 *
 * 以[10,1,2,7,6,1,5]为例，target为8
 *
 * 为了实现上面的去重逻辑，需要一个数组used，表示每一个元素是否被使用，值只有true或者false，并且需要对给定集合进行排序
 * 即[1,1,2,5,6,7,10]，used=[false,false,false,false,false,false,false]
 * 因为本题可以做到不同位置但是值相同的元素出现在同一个组合中，此时例如[1,1,6]在used数组中就会出现[true, true, true]，
 * 而对于这种情况来说，不需要也不可以进行去重，一旦去重就会忽略后面的6导致缺少一个组合结果，所以可以不需要考虑进行树枝去重
 *
 * 但是需要考虑树层去重，因为存在两个1，如果使用第一个1，此时在同一层下，第二个1就是未使用状态，此时used就是[true,false...]
 * 对于这种情况，第一次搜索1，一定会搜索到[1,7]，但是因为7也存在与第二个1的后面，所以第二个1遍历也会搜索到[1,7]，虽然使用的是不同位置的1
 * 但是最后的组合结果是一样的，所以此时就需要去重
 * 去重的思路就是跳过当前情况，例如跳过第二个1的遍历
 *
 * 之所以需要使用到排序，就是为了确保相同的元素可以出现在一起
 */
class Solution40
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int start, vector<bool> &used)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            // 去重逻辑-树层去重但不进行树枝去重，判断used[i - 1] == false就是为了防止对树枝也进行了去重
            if (i - 1 >= 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;

            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);

        return ret;
    }
};
