//
// Created by 18483 on 2024/12/16.
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

// 力扣222.完全二叉树的节点个数
// 后序遍历
// 普通二叉树的解法——直接遍历所有节点累加
class Solution222_1
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);

        return leftNum + rightNum + 1;
    }
};

// 完全二叉树的解法——如果在完全二叉树的前提下还是满二叉树，直接按照公式返回
class Solution222_2
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        // 是满二叉树时直接返回2^深度-1
        // 如果左子树和右子树深度相等说明当前子树是满二叉树（以完全二叉树为前提）
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;
        while (leftNode)
        {
            leftHeight++;
            leftNode = leftNode->left;
        }
        while (rightNode)
        {
            rightHeight++;
            rightNode = rightNode->right;
        }

        if (leftHeight == rightHeight)
        {
            // 说明是满二叉树
            // 注意运算优先级
            return (2 << leftHeight) - 1;
        }

        // 遍历剩余子树
        leftHeight = countNodes(root->left);
        rightHeight = countNodes(root->right);

        return leftHeight + rightHeight + 1;
    }
};