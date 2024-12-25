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

// ����701.�����������еĲ������
class Solution701
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // ���ڵ�Ϊ�գ���ǰ�ڵ���Ϊ���ڵ�
        if (!root)
            return new TreeNode(val);

        TreeNode *cur = root;
        // ��¼ǰһ���ڵ�
        TreeNode *prev = nullptr;
        while (cur)
        {
            // ��ǰ�ڵ��ֵС��val���ߵ�������
            prev = cur;
            if (cur->val < val)
                cur = cur->right;
            else if (cur->val > val) // ��ǰ�ڵ��ֵС��val���ߵ�������
                cur = cur->left;
        }

        if (val < prev->val)
            prev->left = new TreeNode(val);
        else if (val > prev->val)
            prev->right = new TreeNode(val);

        return root;
    }
};
