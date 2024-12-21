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

// 力扣106.从中序与后序遍历序列构造二叉树
/*
 * 基本思路：根据后序遍历找出根节点，再根据根节点分别切割前序遍历数组和后序遍历数组重复调用函数直到数组为空时代表遍历完成
 */
class Solution106
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
            return nullptr;
        // 1. 根据后序遍历获取根节点
        int rootVal = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootVal);

        // 2. 根据根节点在中序中分左区间数组和右区间数组
        int rootIndex = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }

        // 左闭右开原则分割
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> inorderRight(inorder.begin() + rootIndex + 1, inorder.end());

        // 3. 根据根节点在后序中分左区间数组和右区间数组
        // 先舍去后序的最后一个元素
        postorder.resize(postorder.size() - 1);
        // 左闭右开原则分割
        vector<int> postorderLeft(postorder.begin(), postorder.begin() + inorderLeft.size());
        vector<int> postorderRight(postorder.begin() + inorderLeft.size(), postorder.end());

        // 4. 根据左中和左后、右中和右后重复上述步骤
        root->left = buildTree(inorderLeft, postorderLeft);
        root->right = buildTree(inorderRight, postorderRight);

        // 5. 返回根节点
        return root;
    }
};
