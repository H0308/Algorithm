//
// Created by 18483 on 2024/12/18.
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

// 力扣257.二叉树的所有路径
/*
 * 基本思路：遍历一个节点就向temp插入该节点，记录当前节点被遍历到
 * 如果遇到一个节点左孩子为空，右孩子也为空，则一定是叶子节点，此时就要将temp中的字符依次构成路径字符串插入到结果集中
 * 插入完成后需要弹出当前的叶子，继续遍历右子树
 * 细节：如果当前就是右子树，那么需要继续弹出temp中的最后一个元素，所以需要将弹出逻辑单独作为一条语句，作为向上返回前一定要执行的语句
 *
 * 以下面的二叉树为例
 *
 *       1
 *    2     3
 *  4   5
 *
 *  结果集：["1->2->4", "1->2->5", "1->3"]
 *  基本思路如下：
 *  1->左->2->左->4->左->nullptr，返回到4的函数栈帧。temp=["1", "2", "4"]
 *               4->右->nullptr，返回到4的函数栈帧
 *               判断4左右均为空，说明是叶子节点，此时将temp中的内容构成结果：1->2->4
 *               弹出最后一个元素。temp=["1", "2"]
 *               返回到2的函数栈帧
 *         2->右->5->左->nullptr，返回到5的函数栈帧。temp=["1", "2", "5"]
 *                5->右->nullptr，返回到5的函数栈帧
 *                判断5左右均为空，说明是叶子节点，此时将temp中的内容构成结果：1->2->5
 *                弹出最后一个元素。temp=["1", "5"]
 *                返回到2的函数栈帧
 *         弹出最后一个元素。temp=["1"]
 *         返回到1的函数栈帧
 *  1->右->3->左->nullptr，返回到3的函数栈帧。temp=["1", "3"]
 *         3->右->nullptr，返回到3的函数栈帧
 *         判断3左右均为空，说明是叶子节点，此时将temp中的内容构成结果：1->3
 *         弹出最后一个元素。temp=["1"]
 *         返回到1的函数栈帧
 *  弹出最后一个元素。temp=[]
 *  回到主调函数，结束
 */
class Solution257
{
public:
    void addchar(TreeNode *root, vector<string> &ret, vector<string> &temp)
    {
        if (!root)
            return;

        temp.push_back(to_string(root->val));
        addchar(root->left, ret, temp);
        addchar(root->right, ret, temp);

        if (!root->left && !root->right)
        {
            string backup = "";
            for (int i = 0; i < temp.size(); i++)
            {
                backup += temp[i];
                if (i != temp.size() - 1)
                    backup += "->";
            }
            ret.push_back(backup);
        }
        temp.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        vector<string> temp;

        addchar(root, ret, temp);

        return ret;
    }
};

// 去掉引用，通过函数返回完成回溯，省去手动pop_back()
class Solution257_2
{
public:
    void addchar(TreeNode *root, vector<string> &ret, vector<string> temp)
    {
        if (!root)
            return;

        temp.push_back(to_string(root->val));
        addchar(root->left, ret, temp);
        addchar(root->right, ret, temp);

        if (!root->left && !root->right)
        {
            string backup = "";
            for (int i = 0; i < temp.size(); i++)
            {
                backup += temp[i];
                if (i != temp.size() - 1)
                    backup += "->";
            }
            ret.push_back(backup);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        vector<string> temp;

        addchar(root, ret, temp);

        return ret;
    }
};

// string代替中间变量vector<string>
class Solution257_3
{
public:
    void addchar(TreeNode *root, vector<string> &ret, string temp)
    {
        if (!root)
            return;

        temp += to_string(root->val);
        // 叶子节点单独处理
        if(!root->left && !root->right)
        {
            ret.push_back(temp);
            // 直接返回不需要加上->
            return;
        }
        temp += "->";

        addchar(root->left, ret, temp);
        addchar(root->right, ret, temp);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        string temp;

        addchar(root, ret, temp);

        return ret;
    }
};