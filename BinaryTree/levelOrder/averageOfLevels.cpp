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

// ����637.�������Ĳ�ƽ��ֵ
// �������+�����ܺ���ƽ��ֵ
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        // ��¼ÿһ����ܺ�
        double sum = 0;
        // ��¼ÿһ��ڵ�ĸ���
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

            // ����ƽ��ֵ
            ret.push_back(sum / count);

            sum = 0;
        }

        return ret;
    }
};
