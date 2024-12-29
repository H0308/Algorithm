//
// Created by 18483 on 2024/12/29.
//
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node()
    {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 力扣LCR155.将二叉搜索树转化为排序的双向链表
// 异地操作
class SolutionLCR155_1
{
public:
    void traversal(Node *root, vector<Node *> &nodes)
    {
        if (!root)
            return;

        traversal(root->left, nodes);
        nodes.push_back(root);
        traversal(root->right, nodes);
    }

    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return nullptr;

        vector<Node *> nodes;
        traversal(root, nodes);

        // 构建链表
        Node *prev = nullptr;
        Node *dummy = new Node(0);
        for (auto &node: nodes)
        {
            if (!dummy->right)
            {
                dummy->right = node;
                if (nodes.size() == 1)
                {
                    node->left = node;
                    node->right = node;
                    return node;
                }
            }
            else
            {
                dummy->right->left = node;
                node->right = dummy->right;
            }

            if (prev)
            {
                prev->right = node;
                node->left = prev;
            }

            prev = node;
        }

        return dummy->right;
    }
};

// 原地操作
/*
 * 原地操作就需要一个节点单独prev记录之前的一个节点，中序遍历过程中，将当前节点的前驱指针指向prev，prev的后继指向当前节点即可完成链接
 * 注意prev不为空的情况
 */
class SolutionLCR155_2
{
public:
    Node *prev = nullptr;

    void _treeToDoublyList(Node *root)
    {
        if (!root)
            return;

        _treeToDoublyList(root->left);

        root->left = prev;
        if (prev)
            prev->right = root;
        prev = root;

        _treeToDoublyList(root->right);
    }

    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return nullptr;

        // 找到最左节点作为头节点
        Node *head = root;
        while (head->left)
        {
            head = head->left;
        }

        // 找到头结点后再修改
        // 也可以考虑在找到头结点之前修改
        // 此时就是通过链表向前遍历找到头结点head，而不是通过树的遍历
        _treeToDoublyList(root);

        // 头尾相连
        head->left = prev;
        prev->right = head;

        return head;
    }
};
