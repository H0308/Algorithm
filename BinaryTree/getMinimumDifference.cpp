//
// Created by 18483 on 2024/12/24.
//
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {}

    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x)
        , left(left)
        , right(right)
    {}
};

// 力扣530.二叉搜索树的最小绝对差
// 基本思路：当前节点值减去前一个节点值，取minVal和该值的最小值即可，遍历方式采用中序
class Solution530
{
public:
    int minVal = INT_MAX;
    TreeNode *prev = nullptr;

    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return 0;

        getMinimumDifference(root->left);
        if (prev && prev->val != root->val)
            minVal = min(minVal, abs(root->val - prev->val));
        prev = root;
        getMinimumDifference(root->right);

        return minVal;
    }
};
