//
// Created by 18483 on 2024/12/25.
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

// 力扣701.二叉搜索树中的插入操作
class Solution701
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 根节点为空，则当前节点作为根节点
        if (!root)
            return new TreeNode(val);

        TreeNode *cur = root;
        // 记录前一个节点
        TreeNode *prev = nullptr;
        while (cur)
        {
            // 当前节点的值小于val，走到右子树
            prev = cur;
            if (cur->val < val)
                cur = cur->right;
            else if (cur->val > val) // 当前节点的值小于val，走到左子树
                cur = cur->left;
        }

        if (val < prev->val)
            prev->left = new TreeNode(val);
        else if (val > prev->val)
            prev->right = new TreeNode(val);

        return root;
    }
};
