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

// 力扣230.二叉搜索树中第K小的元素
// 解法1：TopK问题

// 不可以使用Lambda作为模版参数
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

        // 弹出k个元素，再取出堆顶元素
        for (int i = 1; i < k; i++)
            pq.pop();

        return pq.top()->val;
    }
};

// 解法2：利用二叉搜索树中序遍历有序
class Solution
{
public:
    int minVal = INT_MAX;
    int count = 0;

    void dfs(TreeNode *root)
    {
        // 如果节点为空或者count为0就不需要向后遍历
        if (!root || !count)
            return;

        dfs(root->left);
        count--;
        // count为0时，说明找到了第k小的元素
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
