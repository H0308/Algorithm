//
// Created by 18483 on 2024/12/22.
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

// 力扣617.合并二叉树
/*
 * 基本思路：
 * 1. 遍历两个树，如果两个树的同一个位置都有节点，直接累加，再遍历左子树和右子树，将结果节点链接到一棵树即可
 * 2. 如果其中一个树节点为空，返回另外一棵树即可
 * 3. 如果两个树都为空，直接返回空指针
 */
class Solution617
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return nullptr;
        else if (!root1)
            return root2;
        else if (!root2)
            return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
