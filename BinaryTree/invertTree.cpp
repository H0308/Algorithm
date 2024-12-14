//
// Created by 18483 on 2024/12/14.
//
#include <iostream>
#include <stack>
#include <queue>
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

// 力扣226.翻转二叉树
/*
 * 本题的基本思路的是遍历二叉树并翻转当前节点的左右孩子节点
 * 关键的问题就是使用哪一种递归方式
 * 首先考虑最直观的思路：先获取到左节点和右节点再进行交换
 * 根据上面的思路可以看出，获取到左节点和右节点就是递归遍历二叉树的过程
 * 而交换节点就是单层递归函数需要处理的逻辑
 * 所以整体就是一个后序遍历
 *
 * 基本的思路如下：
 *
 * 以下面的二叉树为例
 *        4                              4
 *    2        7         -->        7          2
 * 1     3  6      8          8         6  3        1
 *
 * 后序遍历交换过程如下：
 *
 * 4->左->2->左->1->左->nullptr，返回nullptr到1的函数栈帧中
 *              1->右->nullptr，返回nullptr到1的函数栈帧中
 *              交换左和右，返回当前的1节点到2的函数栈帧中
 *        2->右->3->左->nullptr，返回nullptr到3的函数栈帧中
 *               3->右->nullptr，返回nullptr到3的函数栈帧中
 *               交换左和右，返回当前3节点到2的函数栈帧中
 *        交换1和3，返回当前2节点到4的函数栈帧中
 *        至此，左子树的子树全部翻转完毕
 * 4->右->7->左->6->左->nullptr，返回nullptr到6的函数栈帧中
 *              6->右->nullptr，返回nullptr到6的函数栈帧中
 *              交换左和右，返回当前6到7的函数栈帧中
 *        7->右->8->左->nullptr，返回nullptr到8的函数栈帧中
 *               8->右->nullptr，返回nullptr到8的函数栈帧中
 *               交换左和右，返回8到7的函数栈帧中
 *        交换左和右，返回7到4的函数栈帧中
 *        至此，右子树的子树全部翻转完毕
 * 交换左和右，返回4结束函数
 * 至此，整棵树翻转完毕
 */
// 后序遍历——不使用swap
class Solution226_1_1
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        // 单层函数处理逻辑
        root->left = right;
        root->right = left;

        return root;
    }
};

// 后序遍历——使用swap
// 使用swap就不可以使用变量记录左右节点，否则交换的是局部变量
class Solution226_1_2
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        invertTree(root->left);
        invertTree(root->right);

        // 单层函数处理逻辑
        swap(root->left, root->right);

        return root;
    }
};

// 前序遍历
/*
 * 接着考虑在前序遍历过程中进行翻转
 * 前序遍历过程中，先处理当前节点再获取左右节点
 * 本质和后序遍历基本一致，只不过是先交换再遍历之后的子树再交换
 */
class Solution226_2_1
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// 中序遍历
/*
 * 本题也可以考虑使用中序遍历，但是需要注意的是
 * 中序遍历的顺序是左中右，在本题中也就是先遍历到左节点，接着就进行交换
 * 但是在接下来遍历右子树的时候就不难发现，上一步交换已经将原来的左节点和右节点进行了交换
 * 此时的右子树就是原来的左子树，如果再进行交换就会回到原来的子树形式
 * 所以下一次遍历不能遍历右子树而应该继续遍历左子树
 */
class Solution226_3
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        invertTree(root->left);
        swap(root->left, root->right);
        invertTree(root->left);

        return root;
    }
};

// 迭代写法——以前序为例
class Solution226_2_2
{
public:
    TreeNode *invertTree(TreeNode *root)
    {

        stack<TreeNode*> st;

        st.push(root);
        while(!st.empty() && root != nullptr)
        {
            TreeNode* cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if(cur->left)
                st.push(cur->left);
            if(cur->right)
                st.push(cur->right);
        }

        return root;
    }
};

// 层序遍历
class Solution226_4
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode*> que;

        que.push(root);
        while(!que.empty() && root != nullptr)
        {
            int count = que.size();
            while(count--)
            {
                TreeNode* cur = que.front();
                que.pop();
                swap(cur->left, cur->right);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
        }

        return root;
    }
};