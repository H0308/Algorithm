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

// 力扣129.求根节点到叶节点数字之和
/*
 * 思路1：通过获取所有路径插入到路径数组中，将每一条路径数组中的值组合成为一个整数，依次计算和即可，缺点：利用到了O(N)的空间复杂度
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

        // 遍历完所有子树后全部弹出回到根节点
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

// 思路2：将上面的获取路径步骤修改为计算路径值
class Solution129_2
{
public:
    int traversal(TreeNode *root, int prev)
    {
        if (!root)
            return 0;

        // 计算路径值
        prev = prev * 10 + root->val;
        // 遇到叶子节点，返回当前路径值
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
