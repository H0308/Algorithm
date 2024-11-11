//
// Created by 18483 on 2024/11/11.
//
#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
        : val(0)
        , next(nullptr)
    {}

    ListNode(int x)
        : val(x)
        , next(nullptr)
    {}

    ListNode(int x, ListNode *next)
        : val(x)
        , next(next)
    {}
};

// ����203.�Ƴ�����Ԫ��
// �ⷨ1��ֱ��ɾ��
// ʹ��ͷ���
class Solution203_1_1
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // ɾ��ͷ���
        while (head != NULL && head->val == val)
        {
            // ע�����ﲻ��if
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        // ɾ����ͷ���
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};

// ��ʹ��ͷ���
// ע�⣬�˴���head��������ͷ��㣬����ʵ�ʴ洢��Ч���ݵĽڵ�
class Solution203_1_2
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }

        // �����½ڵ�ָ��ͷ�ڵ�
        ListNode *dummy = new ListNode;
        dummy->next = head;


        // ����ǰ���ڵ�
        ListNode *prev = dummy;
        // ������ʼ�ڵ�
        ListNode *cur = dummy->next;

        while (cur)
        {
            if (cur->val == val)
            {
                // ɾ���ڵ�
                ListNode *toDelete = cur;
                prev->next = cur->next;
                delete toDelete;
            }
            else
            {
                prev = cur;
            }
            cur = prev->next;
        }


        return dummy->next;
    }
};

// �ⷨ2����ش���
class Solution203_2
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *copyHead = new ListNode;
        ListNode *curA = head;
        ListNode *curB = copyHead;
        while (curA)
        {
            if (curA->val != val)
            {
                ListNode *newNode = new ListNode(curA->val);
                curB->next = newNode;
                curB = curB->next;
            }
            curA = curA->next;
        }

        return copyHead->next;
    }
};