//
// Created by 18483 on 2024/12/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}
};

// 力扣501.二叉搜索树中的众数
/*
 * 最直观的思路：遍历二叉搜索树，将元素依次插入vector，遍历vector使用哈希表统计元素出现的次数，找出出现次数最大的所有元素
 */
// 二叉树遍历+哈希表
class Solution501_1
{
public:
    void traversal(TreeNode *root, unordered_map<int, int> &countMap)
    {
        if (!root)
            return;

        traversal(root->left, countMap);
        // 统计出现频率
        countMap[root->val]++;
        traversal(root->right, countMap);
    }

    vector<int> findMode(TreeNode *root)
    {

        unordered_map<int, int> countMap;
        traversal(root, countMap);

        int maxCount = 0;
        vector<int> ret;
        for (auto &kv: countMap)
        {
            if (kv.second > maxCount)
                maxCount = kv.second;
        }

        for (auto &kv: countMap)
        {
            if (kv.second == maxCount)
                ret.push_back(kv.first);
        }

        for (auto &kv: countMap)
        {
            // 注意使用find确保当前插入的元素不存在于结果集中
            if (kv.second == maxCount && kv.first != ret[0] && find(ret.begin(), ret.end(), kv.first) == ret.end())
                ret.push_back(kv.first);
        }

        return ret;
    }
};

// 解法2：常量空间，使用前驱指针+代码技巧处理结果集
class Solution501_2
{
public:
    // 记录最大频率
    int maxCount = 0;
    // 记录当前元素出现的频率
    int count = 0;
    // 结果集
    vector<int> ret;
    // 上一个节点
    TreeNode *prev = nullptr;

    void traversal(TreeNode *root)
    {
        if (!root)
            return;

        // 中序遍历
        traversal(root->left);

        // 中间处理
        // 统计当前元素出现频率
        if (prev == nullptr) // 前一个为空元素，说明当前元素一定为新出现的元素，count更新为1
            count = 1;
        else if (prev->val == root->val) // 前一个元素和当前元素相等，说明一定是重复元素
            count++;
        else
            count = 1; // 前一个元素和当前元素不相等，说明遇到新元素，count更新为1
        // 更新prev
        prev = root;

        // 如果count与maxCount相等，说明此时找到了最大出现频率的元素
        // 更新结果集
        // 使用if确保只插入一次满足最大出现频率的元素
        if (count == maxCount)
            ret.push_back(root->val);

        // 如果count大于maxCount说明前面已经更新的结果集有误，此时更新maxCount和结果集
        // 通过第二次的更新一定可以满足在当前状态下结果集中是当前出现频率最大的
        // 如果下一次有不同的值但是出现频率与最大频率相同，那么会因为上面的if插入到结果集而不会更新结果集
        if (count > maxCount)
        {
            maxCount = count;
            // 清空上一次的结果集
            ret.clear();
            // 重新更新结果集
            ret.push_back(root->val);
        }

        traversal(root->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        traversal(root);

        return ret;
    }
};
