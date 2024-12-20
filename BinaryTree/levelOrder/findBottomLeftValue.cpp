//
// Created by 18483 on 2024/12/20.
//
#include <iostream>
#include <queue>

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

// 力扣513.找树左下角的值
// 迭代法
/*
 * 本题迭代法最容易想到，只需要找到最底层的第一个出现的节点即可，为了防止被同层的节点覆盖，可以使用flag标记
 */
class Solution513_1
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val;
        queue<TreeNode *> que;
        que.push(root);

        TreeNode *ret = nullptr;

        while (!que.empty())
        {
            int count = que.size();
            bool floor = true;
            while (count--)
            {
                TreeNode *cur = que.front();
                que.pop();

                if (cur->left && !cur->left->left && !cur->left->right && floor)
                {
                    ret = cur->left;
                    floor = false;
                }
                else if (cur->right && !cur->right->left && !cur->right->right && floor)
                {
                    ret = cur->right;
                    floor = false;
                }

                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }

        return ret->val;
    }
};

// 递归
class Solution513_2
/*
 * 递归法就是通过求深度控制最底层，在获取到最底层时就记录节点，否则继续遍历
 */
{
public:
    int maxDepth = INT_MIN;
    int result = 0;

    void traversalWithDepth(TreeNode *root, int depth)
    {
        // 遍历到叶子节点时判断是不是最底层的叶子
        if (!root->left && !root->right)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }

        // 遍历左子树
        if (root->left)
        {
            depth++;
            traversalWithDepth(root->left, depth);
            // 返回调用处时会向上一层返回
            depth--;
        }

        // 遍历右子树
        if (root->right)
        {
            depth++;
            traversalWithDepth(root->right, depth);
            // 返回调用处时会向上一层返回
            depth--;
        }

        return;
    }

    int findBottomLeftValue(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val;

        int depth = 0;
        traversalWithDepth(root, depth);

        return result;
    }
};
