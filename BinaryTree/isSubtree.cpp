//
// Created by 18483 on 2024/12/15.
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

// 力扣572.另一棵树的子树
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && q || p && !q)
            return false;
        else if (!p && !q)
            return true;
        else if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        // 先判断根是否与子树相同
        if (isSameTree(root, subRoot))
            return true;

        // 再判断左子树或者右子树是否与子树相同
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
