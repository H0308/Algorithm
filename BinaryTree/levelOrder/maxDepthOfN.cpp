//
// Created by 18483 on 2024/12/15.
//
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node()
    {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// 力扣559.N叉树的最大深度
// 后序遍历
class Solution559_1
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;

        int depth = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            depth = max(depth, maxDepth(root->children[i]));
        }

        return depth + 1;
    }
};

// 层序遍历
class Solution559_2
{
public:
    int maxDepth(Node *root)
    {
        queue<Node *> que;
        int floor = 0, count = 0;
        que.push(root);

        while (!que.empty() && root)
        {
            count = que.size();
            while (count--)
            {
                Node *cur = que.front();
                que.pop();

                for (int i = 0; i < cur->children.size(); i++)
                {
                    que.push(cur->children[i]);
                }
            }

            floor++;
        }

        return floor;
    }
};
