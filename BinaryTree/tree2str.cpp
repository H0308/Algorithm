//
// Created by 18483 on 2024/12/29.
//
#include <iostream>
#include <string>

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

// 力扣606.根据二叉树创建字符串
/*
 * 基本思路：根据题目的描述可以分出下面的情况
 * 1. 当前节点的左孩子和右孩子均不为空时，正常插入并正确闭合括号
 * 2. 当前节点的左孩子不为空，右孩子为空时，正常插入并正确闭合括号
 * 3. 当前节点的左孩子为空，但是右孩子不为空时，左孩子需要插入空括号对，再插入右节点和括号
 */
class Solution606_1
{
public:
    void _tree2str(TreeNode *root, string &ret)
    {
        ret += "(" + to_string(root->val);
        if (!root->left && root->right)
            ret += "()";

        if (root->left)
            _tree2str(root->left, ret);

        if (root->right)
            _tree2str(root->right, ret);

        // 左右子树都遍历完毕后右括号首尾
        ret += ")";
    }

    string tree2str(TreeNode *root)
    {
        if (!root)
            return "";

        string ret;
        // 单独处理根节点
        ret += to_string(root->val);

        if (root->left)
            _tree2str(root->left, ret);
        else if (!root->left && root->right)
            ret += "()";

        if (root->right)
            _tree2str(root->right, ret);

        return ret;
    }
};

/*
 * 从上面的思路看出，其实只需要考虑最后一种情况，也就是左为空，但是右不为空时就需要额外添加左子树的括号
 * 所以可以考虑先写出加上全部括号的逻辑再使用if划分情况
 * 这两个只是写法上的不同，思路基本一致
 * 但是，第二种写法会在性能上有很大影响，因为每一次递归都会创建一个新的string对象，并且在每一次返回时都需要进行构造，导致额外的时间和空间的开销
 */
// 写法2
class Solution606_2
{
public:
    string tree2str(TreeNode *root)
    {
        string ret;
        if (!root)
            return ret;

        // 插入节点值
        ret += to_string(root->val);

        // 左子树不为空，正常插入左子树和括号
        // 左子树为空，但右子树不为空，正常插入括号
        if (root->left || root->right)
        {
            ret += "(";
            if (root->left)
                ret += tree2str(root->left);
            ret += ")";
        }

        // 右子树不为空时，正常插入右子树和括号
        if (root->right)
        {
            ret += "(";
            ret += tree2str(root->right);
            ret += ")";
        }

        return ret;
    }
};
