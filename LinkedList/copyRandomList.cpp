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

// ����138.�������ĸ���
/*
 * �ⷨ1��
 * �����ߣ�
 * 1. ��������ڵ㲢����Ӧ�Ľڵ����ӵ�ԭ����
 * 2. ����random�ڵ�
 * 3. �Ͽ��������ԭ���������
 */
class Solution138_1
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        // 1. ��������ڵ㲢����Ӧ�Ľڵ����ӵ�ԭ����
        Node *cur = head;
        while (cur)
        {
            // ����������
            Node *newNode = new Node(cur->val);
            // ������ڵ����ӵ�ԭ����
            newNode->next = cur->next;
            Node *next = cur->next;
            cur->next = newNode;

            // �ƶ�
            cur = next;
        }

        // 2. ����random�ڵ�
        cur = head;
        while (cur && cur->next)
        {
            if (cur->random == nullptr)
                cur->next->random = nullptr;
            else
                cur->next->random = cur->random->next;

            cur = cur->next->next;
        }

        // 3. �Ͽ��������ԭ���������
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

// �ⷨ2��
/*
 * �Ż���ʹ��map����ԭ�ڵ�Ϳ����ڵ������
 */

class Solution138_2
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        // ʹ��map��������
        map<Node*, Node*> ori_copy;
        // 1. ��������ڵ㲢�������Ľڵ��ԭ����ڵ㽨������
        // Ŀ����������randomʱͨ��ԭ����ڵ���random��ָ���ҵ�������Ľڵ�
        Node *cur = head;
        Node* copyHead = new Node(0);
        Node* curCopy = copyHead;
        while (cur)
        {
            // ����������
            Node *copyNode = new Node(cur->val);
            if(copyHead->next == nullptr)
                copyHead->next = copyNode;
            else
                curCopy->next = copyNode;

            // ������ڵ��ԭ����ڵ㽨������
            ori_copy.insert({cur, copyNode});

            // �ƶ�
            // cur = next;
            cur = cur->next;
            curCopy = curCopy->next;
        }

        // 2. ����random�ڵ�
        cur = head;
        while (cur)
        {
            if (cur->random == nullptr)
                // cur->next->random = nullptr;
                    ori_copy[cur]->random = nullptr;
            else
                // �ҵ�ԭ������random��ָ��
                ori_copy[cur]->random = ori_copy[cur->random];

            // cur = cur->next->next;
            cur = cur->next;
        }

        return copyHead->next;
    }
};