//
// Created by 18483 on 2024/12/15.
//
#include <iostream>
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

// 力扣101.对称二叉树
/*
 * 判断一棵树是否是对称二叉树就是要比较左子树是否可以翻转为对应的右子树
 * 即，判断左子树的值是否等于右子树对应的值（左子树的外侧等于右子树的外侧，左子树的内侧等于右子树的内侧）
 * 以下面的二叉树为例：
 *           1
 *     2           2
 * 3       4   4        3
 * 最基本的思路如下：
 *
 * 1->左->2->左->3
 *  ->右->2->左->3
 *  相等返回true给2节点的函数栈帧
 *        2->右->4
 *        2->左->4
 *  相等返回true给2节点的函数栈帧
 * 左子树的2和右子树的2返回true给1的函数栈帧
 *
 * 从上面的过程可以发现，需要先判断左子树的孩子和右子树的孩子是否对应一致
 * 所以采用的遍历顺序只能是后序（左右中），因为只有后序才能满足先遍历到左右子树获取到结果，再遍历根节点向上层返回结果
 *
 * 并且因为需要同时获取到左孩子和右孩子，仅仅使用一个根节点肯定是不够的，所以还需要额外添加一个函数，在函数内部同时遍历两棵子树
 * 此时就确定了函数的参数为两个，分别是左节点和右节点，因为只需要判断节点是否相等，所以返回值为布尔类型即可
 * 接着考虑递归终止条件：一共有下面几种情况：
 * 1. 左节点为空，右节点不为空->false
 * 2. 左节点不为空，右节点为空->false
 * 3. 左节点和右节点都为空->true
 * 4. 左节点和右节点的值不相等->false
 * 上面4步中的前三步是为了排除左节点和右节点可能为空的情况
 *
 * 最后就是单层处理逻辑：一旦判断了左节点和右节点相等，就可以向上层返回结果，例如基本思路中的「左子树的2和右子树的2返回true给1的函数栈帧」
 */
class Solution101_1
{
public:
    // 同时判断两棵树
    bool _isSymmetric(TreeNode *left, TreeNode *right)
    {
        // 终止条件
        if (!left && right || left && !right)
            return false;
        else if (!left && !right)
            return true;
        else if (left->val != right->val)
            return false;

        // 遍历两棵子树的外侧
        bool outside = _isSymmetric(left->left, right->right);
        // 遍历两棵子树的内侧
        bool inside = _isSymmetric(left->right, right->left);

        // 单层处理逻辑
        return outside && inside;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return _isSymmetric(root->left, root->right);
    }
};

// 迭代法
class Solution101_2
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> que;

        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {
            TreeNode *left = que.front();
            que.pop();
            TreeNode *right = que.front();
            que.pop();
            if (!left && right || left && !right)
                return false;
            else if (!left && !right)
                continue;
            else if (left->val != right->val)
                return false;

            // 先插入外侧
            que.push(left->left);
            que.push(right->right);
            // 再插入内侧
            que.push(left->right);
            que.push(right->left);
        }

        return true;
    }
};
