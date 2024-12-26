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
        TreeNode *prev = prev;

        while (cur)
        {
            // 记录当前节点
            if (cur->val > key)
            {
                // 注意prev的位置要在if里面
                // 防止出现下一次cur为待删除的节点时，prev也变成了当前待删除的节点
                prev = cur;
                cur = cur->left;
            }
            else if (cur->val < key)
            {
                prev = cur;
                cur = cur->right;
            }
            else // 相等时执行删除
            {
                // 第一种和第二种情况
                // 如果当前节点的左孩子为空
                if (!cur->left)
                {
                    // 注意根节点为待删除的数值时需要单独考虑
                    if(cur == root)
                        root = cur->right;
                    else if (prev->left == cur) // 判断当前节点是其父亲节点的左孩子还是右孩子
                        prev->left = cur->right;
                    else if (prev->right == cur)
                        prev->right = cur->right;
                    delete cur;
                }
                else if (!cur->right)
                {
                    // 注意根节点为待删除的数值时需要单独考虑
                    if(cur == root)
                        root = cur->left;
                    else if (prev->left == cur)
                        prev->left = cur->left;
                    else if (prev->right == cur)
                        prev->right = cur->left;
                    delete cur;
                }
                else
                {
                    // 第三种情况
                    // 先找到待删除节点的右孩子的最左孩子
                    TreeNode *replaceNode = cur->right;
                    TreeNode *replaceNodePrev = cur;

                    while (replaceNode->left)
                    {
                        replaceNodePrev = replaceNode;
                        replaceNode = replaceNode->left;
                    }

                    // 将待删除节点的值替换为右孩子的最左孩子的值
                    cur->val = replaceNode->val;
                    if (replaceNode == replaceNodePrev->left)
                        replaceNodePrev->left = replaceNode->right;
                    else if (replaceNode == replaceNodePrev->right)
                        replaceNodePrev->right = replaceNode->right;

                    delete replaceNode;
                }
                break;
            }
        }

        return root;
    }
};