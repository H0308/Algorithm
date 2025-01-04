//
// Created by 18483 on 2025/1/4.
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

// 力扣2331.计算布尔二叉树的值
/*
 * 基本思路：
 * 使用后序遍历计算出左子树的布尔值和右子树的布尔值，根据当前节点是2还是3决定何种逻辑运算符
 */
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val;

        bool left = 0;
        bool right = 0;
        if (root->left)
            left = evaluateTree(root->left);
        if (root->right)
            right = evaluateTree(root->right);

        if (root->val == 2)
            return (left || right);
        else if (root->val == 3)
            return (left && right);

        // 不可达，防止编译器报错
        return 0;
    }
};
