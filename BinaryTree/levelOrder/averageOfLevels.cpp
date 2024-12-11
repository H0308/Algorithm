//
// Created by 18483 on 2024/12/11.
//
#include <iostream>
#include <vector>
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

// 力扣637.二叉树的层平均值
// 层序遍历+计算总和求平均值
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        // 记录每一层的总和
        double sum = 0;
        // 记录每一层节点的个数
        int count = 0;

        vector<double> ret;
        queue<TreeNode *> que;

        que.push(root);

        while (!que.empty())
        {
            count = que.size();
            int temp = count;
            while (temp--)
            {
                TreeNode *cur = que.front();
                que.pop();

                sum += cur->val;

                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }

            // 计算平均值
            ret.push_back(sum / count);

            sum = 0;
        }

        return ret;
    }
};
