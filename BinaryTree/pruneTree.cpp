//
// Created by 18483 on 2025/1/5.
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

// 力扣814.二叉树剪枝
/*
 * 本题的思路很简单，根据题目的题意分析：如果遇到0且为叶子节点，就删除该节点，否则不处理
 * 因为要判断一个节点是否是叶子节点，就必须先获取到左右子树的信息，所以就需要后序遍历
 * 删除节点后，向上层返回空，上层需要使用节点的left或者right接收
 * 注意，本题不要使用delete，面试时一定要询问面试官树的节点是否是在堆上开辟的空间
 */
class Solution814
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (!root->left && !root->right && root->val == 0)
        {
            // delete root; 注意是否需要释放内存要看具体情况（一定要确定是否是在堆上开出的空间），本题不能释放
            return nullptr;
        }

        // 如果为1就返回当前子树的根
        return root;
    }
};