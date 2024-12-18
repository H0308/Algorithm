//
// Created by 18483 on 2024/12/18.
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

// 力扣110.平衡二叉树
/*
 * 基本思路就是获取左右子树的高度，判断差值的绝对值是否大于1，不大于就继续比较
 */
// 本题也可以用于判断AVL是否平衡
class Solution110
{
public:
    // 获取二叉树高度
    int getHeight(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(rightHeight - leftHeight) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
