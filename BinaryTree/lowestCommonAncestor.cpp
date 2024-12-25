//
// Created by 18483 on 2024/12/25.
//
#include <iostream>
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

// 力扣236.二叉树的最近公共祖先
/*
 * 基本思路：
 * 1. 同一个子树中存在p，q，则此时p或者q其中一个可能是公共祖先
 * 2. 不同子树中存在p，q，则此时二者的公共父亲就是公共祖先
 *
 * 所以现在的问题就演变为如何判断在一棵子树下：
 * 1. 如果在p中找到q，则说明p是公共祖先，否则q是公共祖先
 * 2. 如果p和q都是叶子节点，则找他们的公共祖先
 *
 * 下面的写法中需要注意返回值的控制，如果函数有返回值，并且需要向上返回这个返回值就必须接受函数的返回值并将其返回
 */
class Solution236_1
{
public:
    // 判断是否在同一棵子树下
    bool isUnder(TreeNode *root, TreeNode *target)
    {
        if (!root)
            return false;

        if (root->val == target->val)
            return true;
        // 在该子树中找到了就返回true
        return isUnder(root->left, target) || isUnder(root->right, target);
    }

    // 遍历查找节点
    TreeNode *traversal(TreeNode *root, TreeNode *target)
    {
        if (!root)
            return nullptr;

        if (root->val == target->val)
            return root;

        TreeNode *left = traversal(root->left, target);
        TreeNode *right = traversal(root->right, target);

        if (left)
            return left;

        if (right)
            return right;

        return nullptr;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 找到两个节点
        TreeNode *node1 = traversal(root, p);
        TreeNode *node2 = traversal(root, q);

        // 判断p和q是否在同一棵子树下
        if (isUnder(node1, node2)) // q在p的子树中
            return p;
        else if (isUnder(node2, node1)) // p在q的子树中
            return q;

        // 如果既不在q也不再p，直接二者共有的父亲节点
        // 思路如下：
        // 从根节点开始遍历，如果在cur->left中找到了node1和node2，说明node1和node2在cur的左子树中
        // 继续向下遍历，直到cur->left不存在node1和node2，此时cur就是共有的父亲节点
        // 如果在cur->right中找到了node1和node2，说明node1和node2在cur的右子树中
        // 继续向下遍历，直到cur->right不存在node1和node2，此时cur就是共有的父亲节点
        TreeNode *cur = root;
        while (cur)
        {
            if (isUnder(cur->left, node1) && isUnder(cur->left, node2))
                cur = cur->left;
            else if (isUnder(cur->right, node1) && isUnder(cur->right, node2))
                cur = cur->right;
            else
                break;
        }

        return cur;
    }
};

// 写法2
/*
 * 思路基本一致：即找到最近的祖先就一直向上返回
 * 但是上面的思路针对两种情况都进行了单独处理，过程有点复杂，下面的写法做到了在处理一般情况的同时处理了p或者q为最近公共祖先的情况
 * 因为情况2的本质就是p和q在p或者q的子树下，那么在遍历二叉树的过程中，一定会优先查找到p或者q，此时就会返回p或者q
 * 因为p或者q一直是q或者p的孩子，所以在返回left或者right时，只会走第二种和第三种if分支
 */
class Solution236_2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 如果当前节点为p或者q，则直接返回当前节点
        if (root == p || root == q || root == nullptr)
            return root;

        // 后序遍历
        // 先在左子树中找p和q，如果找到了p就会一直向上返回而不会继续找q
        // 对于一般情况（即p或者q都不是最近公共祖先）来说，p和q不会存在于同一条路径下
        // 所以也就不会出现遍历左子树和右子树都遍历的是同一个值p或者q
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // 遍历右子树找p和q
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 处理
        // 如果左孩子不为空，右孩子也不为空，说明当前函数栈帧的root的值就是最近公共祖先
        if (left && right)
            return root;
        else if (!left && right) // 如果左为空，右不为空，说明还没有找到最近公共祖先，只找到了一棵子树的根
            return right;
        else if (left && !right) // 同上面的情况
            return left;

        return nullptr;
    }
};

// 力扣235.二叉搜索树的最近公共祖先
// 写法1
/*
 * 本题可以直接使用上题的代码完成，因为二叉搜索树本质也是二叉树
 */
class Solution235_1
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q || root == nullptr)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 如果左孩子不为空，右孩子也不为空，说明当前函数栈帧的root的值就是最近公共祖先
        if (left && right)
            return root;
        else if (!left && right) // 如果左为空，右不为空，说明还没有找到最近公共祖先，只找到了一棵子树的根
            return right;
        else if (left && !right) // 同上面的情况
            return left;

        return nullptr;
    }
};

// 写法2
/*
 * 利用二叉搜索树的特性：左子树所有节点均小于根节点，右子树所有节点均大于根节点可以分出下面的三种情况：
 * 1. 当前节点大于p和q，说明最近公共祖先在左子树
 * 2. 当前节点小于p和q，说明最近公共祖先在右子树
 * 3. 当前节点介于p和q，说明当前节点就是最近公共祖先
 *
 * 注意，不会出现「当前节点介于p和q，说明当前节点不是最近公共祖先」的情况
 * 因为一旦当前节点介于p和q，则左子树一定小于当前节点，右子树一定大于当前节点
 * 那么当前节点不论是向左遍历还是向右遍历都会出现错过一个节点的情况
 */
class Solution235_2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;

        // 如果当前节点的值在p值和q值之间，则说明一定是最进公共祖先，因为如果p和q不在同一个子树
        // 那么根据二叉搜索树定义就会出现：
        // 1. p和q都在当前节点左侧
        // 2. p和q都在当前节点右侧

        // 当前节点比p和q都大，走左子树继续找
        if (root->val > p->val && root->val > q->val)
        {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (left)
                return left;
        }

        // 当前节点比p和q都小，走右子树继续找
        if (root->val < p->val && root->val < q->val)
        {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right)
                return right;
        }

        // 如果不满足上面三个if，说明当前节点就在p和q中间，即为最近公共祖先
        return root;
    }
};
