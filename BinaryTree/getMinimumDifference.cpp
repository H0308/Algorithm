//
// Created by 18483 on 2024/12/24.
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

// ����530.��������������С���Բ�
// ����˼·����ǰ�ڵ�ֵ��ȥǰһ���ڵ�ֵ��ȡminVal�͸�ֵ����Сֵ���ɣ�������ʽ��������
class Solution530
{
public:
    int minVal = INT_MAX;
    TreeNode *prev = nullptr;

    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return 0;

        getMinimumDifference(root->left);
        if (prev && prev->val != root->val)
            minVal = min(minVal, abs(root->val - prev->val));
        prev = root;
        getMinimumDifference(root->right);

        return minVal;
    }
};
