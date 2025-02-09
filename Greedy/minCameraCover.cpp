//
// Created by 18483 on 2025/2/9.
//
#include <iostream>

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

// 力扣968.监控二叉树
/*
 * 本题分析题意可以发现，一个有摄像头的节点可以覆盖其父亲节点和其孩子节点，所以可以推出节点的三种状态：
 * 0. 无覆盖
 * 1. 已经安装摄像头
 * 2. 有覆盖
 * 根据上面节点的三种状态可以推出三种情况：
 * 1. 当前节点没有摄像头，但是其孩子节点是被全覆盖的情况，此时说明这两个节点已经被这两个节点的孩子节点覆盖，那么当前节点就是无覆盖的情况，属于情况0，所以此时需要告诉其父亲节点需要添加摄像头
 * 2. 当前节点至少存在一个孩子没有被覆盖，此时尽管另外一个孩子被覆盖了，但是因为有一个孩子没有被覆盖，所以当前节点需要添加一个摄像头，并向上层返回情况1表示已经添加了摄像头
 * 3. 当前节点至少存在一个孩子有摄像头，此时不论是哪个孩子有摄像头，当前节点一定是被覆盖的情况，所以向上层返回情况2即可
 *
 * 针对上面三种情况可以看出，首先就是要确定孩子节点的状态，所以需要使用到后序遍历，根据左孩子和右孩子的状态确定当前节点的状态，再决定是否要安装摄像头
 *
 * 需要额外注意一种特殊情况，就是根节点刚好处于没有覆盖的情况，此时就需要单独处理，如果根节点是情况0，那么就需要再添加一个摄像头
 */
class Solution968
{
public:
    int count = 0;

    int getStatus(TreeNode *root)
    {
        // 走到空节点表示有覆盖的状态
        if (!root)
            return 2;

        // 后序遍历
        int left = getStatus(root->left);
        int right = getStatus(root->right);

        // 三种情况
        // 1. 当前节点的左孩子和右孩子都是有覆盖状态
        // 2. 当前节点的左孩子或者右孩子是没有覆盖的状态
        // 3. 当前节点的左孩子或者右孩子至少有一个有摄像头
        if (left == 2 && right == 2)
            return 0;
        else if (left == 0 || right == 0)
        {
            // 更新计数器，说明此时需要一个摄像头覆盖另外一个没有被覆盖的孩子
            count++;
            return 1;
        }
        else if (left == 1 || right == 1)
            return 2;

        return -1;
    }

    int minCameraCover(TreeNode *root)
    {
        // 如果根节点没有被覆盖，就还需要一个摄像头
        if (getStatus(root) == 0)
            count++;

        return count;
    }
};
