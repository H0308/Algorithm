//
// Created by 18483 on 2024/12/10.
//
#include <iostream>
#include <vector>
#include <stack>
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

// 力扣94.二叉树的中序遍历
// 递归写法
class Solution
{
public:
    void _inorderTraversal(TreeNode *cur, vector<int> &ret)
    {
        if (cur == nullptr)
            return;

        _inorderTraversal(cur->left, ret);
        ret.push_back(cur->val);
        _inorderTraversal(cur->right, ret);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _inorderTraversal(root, ret);

        return ret;
    }
};
