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

// ����LCR155.������������ת��Ϊ�����˫������
// ��ز���
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

        // ��������
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

// ԭ�ز���
/*
 * ԭ�ز�������Ҫһ���ڵ㵥��prev��¼֮ǰ��һ���ڵ㣬������������У�����ǰ�ڵ��ǰ��ָ��ָ��prev��prev�ĺ��ָ��ǰ�ڵ㼴���������
 * ע��prev��Ϊ�յ����
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

        // �ҵ�����ڵ���Ϊͷ�ڵ�
        Node *head = root;
        while (head->left)
        {
            head = head->left;
        }

        // �ҵ�ͷ�������޸�
        // Ҳ���Կ������ҵ�ͷ���֮ǰ�޸�
        // ��ʱ����ͨ��������ǰ�����ҵ�ͷ���head��������ͨ�����ı���
        _treeToDoublyList(root);

        // ͷβ����
        head->left = prev;
        prev->right = head;

        return head;
    }
};
