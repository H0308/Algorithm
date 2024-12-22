//
// Created by 18483 on 2024/12/21.
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

// 力扣105.从前序与中序遍历序列构造二叉树
/*
 * 本题和上题思路基本一致，只是使用的数组不同而已
 * 注意，可以使用前序或者后序+中序构建二叉树，但是不能使用前序+后序构建二叉树，因为此时构建的二叉树不唯一
 */
class Solution105
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 检查输入数组的有效性
        if (preorder.size() == 0)
            return nullptr;

        // 获取根节点值
        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal);

        // 在中序遍历中查找根节点位置
        int rootIndex = -1;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }

        // 分割中序数组 - 左子树
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + rootIndex);
        // 分割中序数组 - 右子树
        vector<int> inorderRight(inorder.begin() + rootIndex + 1, inorder.end());

        // 分割前序数组时确保不会越界
        if (inorderLeft.size() > preorder.size() - 1)
            return nullptr;

        // 分割前序数组 - 左子树
        vector<int> preorderLeft(preorder.begin() + 1,preorder.begin() + 1 + inorderLeft.size());
        // 分割前序数组 - 右子树
        vector<int> preorderRight(preorder.begin() + 1 + inorderLeft.size(),preorder.end());

        // 递归构建左右子树
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};
