//
// Created by 18483 on 2025/1/4.
//
#include <iostream>
#include <vector>
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

// ����129.����ڵ㵽Ҷ�ڵ�����֮��
/*
 * ˼·1��ͨ����ȡ����·�����뵽·�������У���ÿһ��·�������е�ֵ��ϳ�Ϊһ�����������μ���ͼ��ɣ�ȱ�㣺���õ���O(N)�Ŀռ临�Ӷ�
 */
class Solution129_1
{
public:
    void traversal(TreeNode *root, vector<vector<int>> &paths, vector<int> &ret)
    {
        if (!root)
            return;

        ret.push_back(root->val);
        if (!root->left && !root->right)
        {
            paths.push_back(ret);
            ret.pop_back();
            return;
        }

        traversal(root->left, paths, ret);
        traversal(root->right, paths, ret);

        // ����������������ȫ�������ص����ڵ�
        ret.pop_back();
    }

    int calculate(vector<int> &path)
    {
        int ans = 0;
        int base = 0;
        for (auto num: path)
        {
            ans = base * 10 + num;
            base = ans;
        }

        return ans;
    }

    int _sumNumbers(vector<vector<int>> &paths)
    {
        int sum = 0;
        for (auto &path: paths)
        {
            int num = calculate(path);
            sum += num;
        }

        return sum;
    }

    int sumNumbers(TreeNode *root)
    {
        vector<vector<int>> paths;
        vector<int> ret;
        traversal(root, paths, ret);

        return _sumNumbers(paths);
    }
};

// ˼·2��������Ļ�ȡ·�������޸�Ϊ����·��ֵ
class Solution129_2
{
public:
    int traversal(TreeNode *root, int prev)
    {
        if (!root)
            return 0;

        // ����·��ֵ
        prev = prev * 10 + root->val;
        // ����Ҷ�ӽڵ㣬���ص�ǰ·��ֵ
        if (!root->left && !root->right)
            return prev;

        int sumLeft = traversal(root->left, prev);
        int sumRight = traversal(root->right, prev);

        return sumLeft + sumRight;
    }

    int sumNumbers(TreeNode *root)
    {
        int prev = 0;
        int sum = traversal(root, prev);

        return sum;
    }
};
