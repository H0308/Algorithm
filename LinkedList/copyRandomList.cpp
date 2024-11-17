//
// Created by 18483 on 2024/11/15.
//
#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 力扣138.随机链表的复制
/*
 * 解法1：
 * 三步走：
 * 1. 拷贝链表节点并将对应的节点链接到原链表
 * 2. 拷贝random节点
 * 3. 断开新链表和原链表的链接
 */
class Solution138_1
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        // 1. 拷贝链表节点并将对应的节点链接到原链表
        Node *cur = head;
        while (cur)
        {
            // 创建新链表
            Node *newNode = new Node(cur->val);
            // 新链表节点链接到原链表
            newNode->next = cur->next;
            Node *next = cur->next;
            cur->next = newNode;

            // 移动
            cur = next;
        }

        // 2. 拷贝random节点
        cur = head;
        while (cur && cur->next)
        {
            if (cur->random == nullptr)
                cur->next->random = nullptr;
            else
                cur->next->random = cur->random->next;

            cur = cur->next->next;
        }

        // 3. 断开新链表和原链表的链接
        cur = head;
        Node *copyHead = cur->next;
        while (cur)
        {
            Node *copy = cur->next;
            Node *next = copy->next;
            if (next == nullptr)
            {
                copy->next = nullptr;
            }
            else
            {
                copy->next = next->next;
            }
            cur->next = next;

            cur = cur->next;
        }

        return copyHead;
    }
};

// 解法2：
/*
 * 优化：使用map建立原节点和拷贝节点的链接
 */

class Solution138_2
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        // 使用map建立连接
        map<Node*, Node*> ori_copy;
        // 1. 拷贝链表节点并将拷贝的节点和原链表节点建立连接
        // 目的是在链接random时通过原链表节点中random的指向找到拷贝后的节点
        Node *cur = head;
        Node* copyHead = new Node(0);
        Node* curCopy = copyHead;
        while (cur)
        {
            // 创建新链表
            Node *copyNode = new Node(cur->val);
            if(copyHead->next == nullptr)
                copyHead->next = copyNode;
            else
                curCopy->next = copyNode;

            // 新链表节点和原链表节点建立连接
            ori_copy.insert({cur, copyNode});

            // 移动
            // cur = next;
            cur = cur->next;
            curCopy = curCopy->next;
        }

        // 2. 拷贝random节点
        cur = head;
        while (cur)
        {
            if (cur->random == nullptr)
                // cur->next->random = nullptr;
                    ori_copy[cur]->random = nullptr;
            else
                // 找到原链表中random的指向
                ori_copy[cur]->random = ori_copy[cur->random];

            // cur = cur->next->next;
            cur = cur->next;
        }

        return copyHead->next;
    }
};