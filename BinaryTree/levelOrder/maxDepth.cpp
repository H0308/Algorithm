//
// Created by 18483 on 2024/12/11.
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

// ����104.��������������
// �������˼·
/*
 * ��������������ʵ����Ӧ����ǰ�����������⣬���������һ��������������ĸ߶�
 * ������Ϊ�������������Ⱦ��Ǹ��ڵ�ĸ߶�
 * �����������˼·���ǽ���ǰ��ĸ߶ȷ��ظ���һ�㣬����һ��ͳ�Ƶ�ǰ�߶ȣ�һֱ�����ڵ�
 * ��ʱ���ڵ�ĸ߶Ⱦ��Ƕ�������������
 */
class Solution104_1
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (!root->left && !root->right)
            return 1;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
};

// �������˼·
class Solution104_2
{
public:
    int maxDepth(TreeNode *root)
    {
        int floor = 0;
        int count = 0;
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty() && root != nullptr)
        {
            count = que.size();

            while (count--)
            {
                TreeNode *cur = que.front();
                que.pop();

                if (cur->left)
                    que.push(cur->left);

                if (cur->right)
                    que.push(cur->right);
            }

            floor++;
        }

        return floor;
    }
};
