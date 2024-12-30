//
// Created by 18483 on 2024/12/11.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// ����429.N�����Ĳ������
// ��������Ļ���˼·������ע�⣬��ʱ��N������ÿ���ڵ�ĺ��Ӵ�����һ��vector��
class Solution
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        int count = 0;

        vector<vector<int>> ret;
        queue<Node*> que;
        que.push(root);

        while(!que.empty() && root != nullptr)
        {
            count = que.size();
            vector<int> temp;
            while(count--)
            {
                Node* cur = que.front();
                que.pop();

                temp.push_back(cur->val);
                for(auto node : cur->children)
                    que.push(node);
            }

            ret.push_back(temp);
        }

        return ret;
    }
};