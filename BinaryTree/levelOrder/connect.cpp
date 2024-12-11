//
// Created by 18483 on 2024/12/11.
//
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node()
        : val(0)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {}

    Node(int _val)
        : val(_val)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next)
    {}
};

// 力扣116.填充每个节点的下一个右侧节点指针
// 除了最后一个节点，其他元素全部连接下一个队头节点即可
class Solution
{
public:
    Node *connect(Node *root)
    {
        int count = 0;

        queue<Node *> que;

        que.push(root);

        while (!que.empty() && root != nullptr)
        {
            count = que.size();

            while (count)
            {
                count--;
                Node *cur = que.front();
                que.pop();
                if (count == 0)
                    cur->next = nullptr;
                else
                    cur->next = que.front();

                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }

        return root;
    }
};

// 同题目：力扣117填充每个节点的下一个右侧节点指针Ⅱ（代码一致）