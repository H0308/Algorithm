//
// Created by 18483 on 2024/11/13.
//
#include <iostream>
using namespace std;

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

// ����21.�ϲ���������
// �����½ڵ�
class Solution21_1
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // �������ͷ���
        ListNode *mergeHead = new ListNode;
        // ��������ͷ����ǰ�������
        ListNode *curA = list1;
        ListNode *curB = list2;
        // ����һ���ڵ�ָ���������β���
        ListNode *tail = mergeHead;

        // ��һ���ڵ㵽��β��ֹͣ
        while (curA && curB)
        {
            if (curA->val > curB->val)
            {
                // curBСβ�嵽������
                ListNode *newNode = new ListNode(curB->val);

                if (mergeHead->next == nullptr)
                {
                    mergeHead->next = newNode;
                }
                else
                {
                    tail->next = newNode;
                }
                curB = curB->next;
            }
            else
            {
                // curA��С������curB���
                ListNode *newNode = new ListNode(curA->val);

                if (mergeHead->next == nullptr)
                {
                    mergeHead->next = newNode;
                }
                else
                {
                    tail->next = newNode;
                }
                curA = curA->next;
            }
            tail = tail->next;
        }

        // ����ѭ����϶�����һ������δ����
        while (curA)
        {
            ListNode *newNode = new ListNode(curA->val);

            if (mergeHead->next == nullptr)
            {
                mergeHead->next = newNode;
            }
            else
            {
                tail->next = newNode;
            }
            tail = tail->next;

            curA = curA->next;
        }

        while (curB)
        {
            ListNode *newNode = new ListNode(curB->val);

            if (mergeHead->next == nullptr)
            {
                mergeHead->next = newNode;
            }
            else
            {
                tail->next = newNode;
            }
            tail = tail->next;

            curB = curB->next;
        }

        return mergeHead->next;
    }
};

// �������½ڵ�
class Solution21_2
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // �������ͷ���
        ListNode *mergeHead = new ListNode;
        // ��������ͷ����ǰ�������
        ListNode *curA = list1;
        ListNode *curB = list2;
        // ����һ���ڵ�ָ���������β���
        ListNode *tail = mergeHead;

        // ��һ���ڵ㵽��β��ֹͣ
        while (curA && curB)
        {
            if (curA->val > curB->val)
            {
                // curBСβ�嵽������
                tail->next = curB;
                curB = curB->next;
            }
            else
            {
                // curA��С������curB���
                tail->next = curA;
                curA = curA->next;
            }
            tail = tail->next;
        }

        // ����ѭ����϶�����һ������δ����
        if (curA)
        {
            tail->next = curA;
        }
        else if (curB)
        {
            tail->next = curB;
        }

        return mergeHead->next;
    }
};

// �ݹ�д������ǰ��д���Ľ��װ�
class Solution21_3
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // ��������ͷ����ǰ�������
        ListNode *curA = list1;
        ListNode *curB = list2;
        if(curA == nullptr)
        {
            return curB;
        }
        else if(curB == nullptr)
        {
            return curA;
        }
        else
        {
            if (curA->val > curB->val)
            {
                curB->next = mergeTwoLists(curA, curB->next);
                return curB;
            }
            else
            {
                curA->next = mergeTwoLists(curA->next, curB);
                return curA;
            }
        }
    }
};