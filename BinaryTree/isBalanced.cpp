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

// ����110.ƽ�������
/*
 * ����˼·���ǻ�ȡ���������ĸ߶ȣ��жϲ�ֵ�ľ���ֵ�Ƿ����1�������ھͼ����Ƚ�
 */
// ����Ҳ���������ж�AVL�Ƿ�ƽ��
class Solution110
{
public:
    // ��ȡ�������߶�
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
