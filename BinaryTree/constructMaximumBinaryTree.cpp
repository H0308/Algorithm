//
// Created by 18483 on 2024/12/22.
//
#include <iostream>
#include <vector>
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

// ����654.��������
// ����˼·��ǰ�������Լ��������򹹽�������˼·����һ�£�ֻ�ǰ���ĳ���ض��Ĺ���
// �ݹ�ⷨ
// ����Ҳ����ʹ�õ���ջ������ⷨ������ջ��ѧ����˵��
class Solution654
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        // 1. �ҳ����ֵ��Ϊ���ڵ�
        int maxRootIndex = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > nums[maxRootIndex])
                maxRootIndex = i;

        TreeNode *root = new TreeNode(nums[maxRootIndex]);

        // 2. �������ֵ�ָ����飨����ҿ���
        vector<int> numsLeft(nums.begin(), nums.begin() + maxRootIndex);
        vector<int> numsRight(nums.begin() + maxRootIndex + 1, nums.end());

        // 3. ������������������
        root->left = constructMaximumBinaryTree(numsLeft);
        root->right = constructMaximumBinaryTree(numsRight);

        return root;
    }
};
