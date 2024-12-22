//
// Created by 18483 on 2024/12/22.
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

// 力扣654.最大二叉树
// 本题思路和前序、中序以及后序、中序构建二叉树思路基本一致，只是按照某种特定的规则
// 递归解法
// 本题也可以使用单调栈，具体解法见单调栈（学到再说）
class Solution654
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        // 1. 找出最大值作为根节点
        int maxRootIndex = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > nums[maxRootIndex])
                maxRootIndex = i;

        TreeNode *root = new TreeNode(nums[maxRootIndex]);

        // 2. 根据最大值分割数组（左闭右开）
        vector<int> numsLeft(nums.begin(), nums.begin() + maxRootIndex);
        vector<int> numsRight(nums.begin() + maxRootIndex + 1, nums.end());

        // 3. 构建左子树和右子树
        root->left = constructMaximumBinaryTree(numsLeft);
        root->right = constructMaximumBinaryTree(numsRight);

        return root;
    }
};
