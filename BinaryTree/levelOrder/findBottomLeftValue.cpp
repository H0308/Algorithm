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

// ����513.�������½ǵ�ֵ
// ������
/*
 * ����������������뵽��ֻ��Ҫ�ҵ���ײ�ĵ�һ�����ֵĽڵ㼴�ɣ�Ϊ�˷�ֹ��ͬ��Ľڵ㸲�ǣ�����ʹ��flag���
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

// �ݹ�
class Solution513_2
/*
 * �ݹ鷨����ͨ������ȿ�����ײ㣬�ڻ�ȡ����ײ�ʱ�ͼ�¼�ڵ㣬�����������
 */
{
public:
    int maxDepth = INT_MIN;
    int result = 0;

    void traversalWithDepth(TreeNode *root, int depth)
    {
        // ������Ҷ�ӽڵ�ʱ�ж��ǲ�����ײ��Ҷ��
        if (!root->left && !root->right)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }

        // ����������
        if (root->left)
        {
            depth++;
            traversalWithDepth(root->left, depth);
            // ���ص��ô�ʱ������һ�㷵��
            depth--;
        }

        // ����������
        if (root->right)
        {
            depth++;
            traversalWithDepth(root->right, depth);
            // ���ص��ô�ʱ������һ�㷵��
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
