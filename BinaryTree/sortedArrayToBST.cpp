//
// Created by 18483 on 2024/12/27.
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

// 力扣108.将有序数组转换为二叉搜索树
/*
 * 本题不可以直接使用二叉搜索树的节点插入方法，因为这个方法没有考虑到平衡的情况从而导致二叉树变为单链表
 * 因为本题的数组是升序排序的，所以默认情况下所有的节点也就是二叉搜索树的中序遍历结果
 * 需要注意的是，本题已经提到了二叉搜索树最后的结构可以不同，所以可以直接取中间值作为根节点，这样就可以保证左右子树的高度最大不会超过1
 */
class Solution108
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        // 取出中间值作为根节点
        int mid = (nums.size() - 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        // 根据根节点位置构造左子树和右子树——左闭右开区间
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};
