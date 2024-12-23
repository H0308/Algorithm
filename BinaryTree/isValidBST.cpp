//
// Created by 18483 on 2024/12/23.
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

// 力扣98.验证二叉搜索树
// 额外空间
/*
 * 本题最直接的思路就是根据题目给出的规则模拟，但是不能仅仅只判断单棵子树是否满足二叉搜索树的条件，例如下面的一棵树：
 *
 *       5
 *   4      6
 *        3    7
 * 这棵树根节点为5，其左子树是4，4<5，右子树为6，6>5，当前子树满足二叉搜索树的条件
 * 再看根节点为6的子树，左子树为3，3<6，右子树为7，7>6，当前子树满足二叉搜索树的条件
 * 但是二叉搜索树除了叫「搜索树」，还叫「排序树」，即其中序遍历的结果是一个升序排序
 * 很明显，当前子树如果进行中序遍历，结果是45367，不满足排序树的特点，所以其不是二叉搜索树
 * 通过上面的例子可以看成，仅仅只判断每一棵子树是否是二叉搜索树不一定保证本题可以通过
 * 最简单的做法就是将二叉树的中序遍历结果插入到数组中，判断数组中的元素是否是升序，如果是那么当前树就是二叉搜索树，否则就不是
 */
class Solution98_1
{
public:
    void traversal(TreeNode* root, vector<int>& ret)
    {
        if(!root)
            return;

        traversal(root->left, ret);
        ret.push_back(root->val);
        traversal(root->right, ret);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> ret;

        traversal(root, ret);

        for(int i = 0; i < ret.size() - 1; i++)
            if(ret[i] >= ret[i + 1])
                return false;

        return true;
    }
};

// 使用一个节点记录前一个节点的数值，在遍历二叉树的过程中直接进行比较
class Solution98_2
{
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode *root)
    {
        if(!root)
            return true;

        bool left = isValidBST(root->left);
        if(pre && pre->val >= root->val)
            return false;

        // 更新pre为前一个节点
        pre = root;
        bool right = isValidBST(root->right);

        return left && right;
    }
};
