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

// 力扣450.删除二叉搜索树中的节点
class Solution450
{
public:
    // 判断查找的节点是否存在于BST中
    bool find(TreeNode *root, int key)
    {
        TreeNode *cur = root;
        while (cur)
        {
            // 当前节点偏大，走左子树
            if (cur->val > key)
                cur = cur->left;
            else if (cur->val < key) // 当前节点偏小，走右子树
                cur = cur->right;
            else
                return true; // 找到返回true
        }

        return false; // 循环走完说明没找到
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 根节点为空不执行或者不存在指定的key则返回空删除
        if (!root)
            return nullptr;

        if (!find(root, key))
            return root;

        // 先查找到指定节点
        TreeNode *cur = root;
        TreeNode *prev = nullptr;

        while (cur)
        {
            prev = cur;
            if (cur->val > key)
            {
                cur = cur->left;
            }
            else if (cur->val < key)
            {
                cur = cur->right;
            }
            else // 相等时执行删除
            {
                // 如果删除的节点只有一个孩子，那么直接让父亲链接该孩子即可
                // 找到，删除
                if (cur->right == nullptr)
                {
                    // 考虑根节点的情况
                    if (cur == root)
                    {
                        root = cur->left;
                    }
                    else
                    {
                        if (prev->right == cur)
                        {
                            prev->right = cur->left;
                        }
                        else if (prev->left == cur)
                        {
                            prev->left = cur->left;
                        }
                    }
                    delete cur;
                    break;
                }
                else if (cur->left == nullptr)
                {
                    // 考虑根节点的情况
                    if (cur == root)
                    {
                        root = cur->right;
                    }
                    else
                    {
                        // 找到孩子的位置后链接
                        if (prev->left == cur)
                        {
                            prev->left = cur->right;
                        }
                        else if (prev->right == cur)
                        {
                            prev->right = cur->right;
                        }
                    }
                    delete cur;
                    break;
                }
                else
                {
                    // 两个孩子节点
                    // 找出适合的替代节点，选择右子树的最左孩子
                    TreeNode *replaceNodeP = cur;
                    TreeNode *replaceNode = cur->right;

                    // 一直向左子树走直到找到替代节点
                    while (replaceNode->left)
                    {
                        replaceNodeP = replaceNode;
                        replaceNode = replaceNode->left;
                    }

                    // 将replaceNode的值覆盖需要删除的节点
                    cur->val = replaceNode->val;
                    // 将replaceNode的父亲指向替换节点的孩子
                    if (replaceNodeP->left == replaceNode)
                    {
                        // 找的右子树的最左节点，一定没有左孩子
                        replaceNodeP->left = replaceNode->right;
                    }
                    else
                    {
                        // replaceNodeP与待删除节点时同一个节点
                        replaceNodeP->right = replaceNode->right;
                    }
                    delete replaceNode;
                    break;
                }
            }
        }

        return root;
    }
};
