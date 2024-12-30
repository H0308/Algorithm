//
// Created by 18483 on 2024/12/30.
//
#include <iostream>
#include <queue>
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

// 力扣965.单值二叉树
// 前序遍历
class Solution965_1
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
            return true;

        if (root->left && root->val != root->left->val)
            return false;

        if (root->right && root->val != root->right->val)
            return false;

        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

// 层序遍历
class Solution965_2
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        queue<TreeNode *> que;

        que.push(root);

        while (!que.empty())
        {
            TreeNode *cur = que.front();
            que.pop();

            if (cur->left && cur->val != cur->left->val)
                return false;
            if (cur->right && cur->val != cur->right->val)
                return false;

            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }

        return true;
    }
};
