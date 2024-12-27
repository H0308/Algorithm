//
// Created by 18483 on 2024/12/27.
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

// 力扣669.修剪二叉搜索树
/*
 * 本题不可以使用二叉树删除节点的逻辑，因为题目提到了不能修改二叉树的父子关系，而在二叉树删除节点的过程中会涉及到挪动节点
 * 从而导致父子关系改变
 * 本题可以考虑最直观的做法：根据题目要求进行删除节点
 * 如果当前节点不在要求的[low, high]中，就找到其对应的子树继续遍历：
 * 1. 如果当前节点小于low，因为是二叉搜索树，所以其左子树的全部节点一定也小于low，此时只需要向右子树递归判断找到满足条件的子树返回
 * 2. 如果当前节点大于high，因为是二叉搜索树，所以其左子树的全部节点一定也大于high，此时只需要向左子树递归判断找到满足条件的子树返回
 */
class Solution669
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // 如果节点为空，直接返回空
        if (!root)
            return nullptr;

        // 如果当前节点小于low，因为是二叉搜索树，所以其左子树的全部节点一定也小于low
        // 此时只需要向右子树递归判断找到满足条件的子树返回
        if (root->val < low)
            return trimBST(root->right, low, high); // 直接返回子树给当前节点的父亲节点相当于删除当前节点
        else if (root->val > high) // 否则向左遍历
            return trimBST(root->left, low, high);

        // 链接子树
        // 如果不满足上面的条件，说明当前节点在[low, high]之内，继续向下遍历
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
