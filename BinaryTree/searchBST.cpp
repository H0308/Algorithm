//
// Created by 18483 on 2024/12/23.
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

// ����700.�����������е�����
/*
 * ����˼·�����ݶ��������������Խ����۰����
 */
class Solution700
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;

        else if (root->left && val < root->val)
            return searchBST(root->left, val);
        else if (root->right && val > root->val)
            return searchBST(root->right, val);

        return root->val == val ? root : nullptr;
    }
};