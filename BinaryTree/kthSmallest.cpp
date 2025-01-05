//
// Created by 18483 on 2025/1/5.
//
#include <iostream>
#include <queue>
#include <functional>

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

// ����230.�����������е�KС��Ԫ��
// �ⷨ1��TopK����

// ������ʹ��Lambda��Ϊģ�����
// auto compare = [](TreeNode* root1, TreeNode* root2)->bool{return root1->val > root2->val;};
// using compare = function<bool(TreeNode* root1, TreeNode* root2)>;
// compare cmp = [](TreeNode* root1, TreeNode* root2)->bool{return root1->val > root2->val;};
struct Compare
{
    bool operator()(TreeNode *root1, TreeNode *root2)
    {
        return root1->val > root2->val;
    }
};

class Solution230
{
public:
    void dfs(TreeNode *root, priority_queue<TreeNode *, vector<TreeNode *>, Compare> &pq)
    {
        if (!root)
            return;

        pq.push(root);
        dfs(root->left, pq);
        dfs(root->right, pq);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        priority_queue<TreeNode *, vector<TreeNode *>, Compare> pq;
        dfs(root, pq);

        // ����k��Ԫ�أ���ȡ���Ѷ�Ԫ��
        for (int i = 1; i < k; i++)
            pq.pop();

        return pq.top()->val;
    }
};

// �ⷨ2�����ö��������������������
class Solution
{
public:
    int minVal = INT_MAX;
    int count = 0;

    void dfs(TreeNode *root)
    {
        // ����ڵ�Ϊ�ջ���countΪ0�Ͳ���Ҫ������
        if (!root || !count)
            return;

        dfs(root->left);
        count--;
        // countΪ0ʱ��˵���ҵ��˵�kС��Ԫ��
        if (count == 0)
            minVal = root->val;
        dfs(root->right);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        count = k;
        dfs(root);

        return minVal;
    }
};
