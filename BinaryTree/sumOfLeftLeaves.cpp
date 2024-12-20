//
// Created by 18483 on 2024/12/20.
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

// 力扣404.左叶子之和
/*
 * 本题最直观的思路就是遍历到左孩子时再处理左孩子，但是这里会陷入一个误区：不遍历右孩子
 * 实际上，本题除了要遍历左子树的左孩子外，也需要遍历左子树的右孩子的左孩子、右子树的左孩子和右子树的右孩子的左孩子
 * 所以本题的思路是：遍历整棵树，但是只处理是左孩子的情况
 * 以下面的实例为例：
 *            3
 *      9           20
 *  11     21    15      7
 *       5
 *
 * 计算结果为：11+5+15=31
 * 基本思路为：
 * 3->左->9->左->11->左->nullptr，返回0到11的函数栈帧
 *               11->右->nullptr，返回0到11的函数栈帧
 *               返回0到9的函数栈帧
 *        判断11为9的左叶子，更新左叶子结果
 *        9->右->21->左->5->左->nullptr，返回0到5的函数栈帧
 *                      5->右->nullptr，返回0到5的函数栈帧
 *                      返回0到21的函数栈帧
 *              判断5为左孩子，更新左孩子结果
 *              21->右->nullptr，返回0到21的函数栈帧
 *              返回5到9的函数栈帧
 *         返回16到3的函数栈帧
 * 3->右->20->左->15->左->nullptr，返回0到15的函数栈帧
 *               15->右->nullptr，返回0到15的函数栈帧
 *               返回0到20的函数栈帧
 *        判断15为20的左叶子，更新左叶子结果
 *        20->右->7->左->nullptr，返回0到7的函数栈帧
 *                7->右->nullptr，返回0到7的函数栈帧
 *                返回0到20的函数栈帧
 *        返回15到3的函数栈帧
 * 返回31
 *
 *
 */
class Solution404
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            // 左孩子和右孩子都会空，无法判断当前孩子一定为左孩子
            // 所以直接返回0即可
            return 0;

        // 遍历左子树
        int leftNum = sumOfLeftLeaves(root->left);
        // 判断是否是左孩子，是就处理
        if (root->left && (!root->left->left && !root->left->right))
            leftNum = root->left->val;

        // 遍历右子树
        int rightNum = sumOfLeftLeaves(root->right);
        // 虽然遍历右子树，但是右孩子都不做处理

        return leftNum + rightNum;
    }
};