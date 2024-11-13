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

// 力扣21.合并两个链表
// 创建新节点
class Solution21_1
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 新链表的头结点
        ListNode *mergeHead = new ListNode;
        // 定义两个头结点从前往后遍历
        ListNode *curA = list1;
        ListNode *curB = list2;
        // 定义一个节点指向新链表的尾结点
        ListNode *tail = mergeHead;

        // 有一个节点到结尾就停止
        while (curA && curB)
        {
            if (curA->val > curB->val)
            {
                // curB小尾插到新链表
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
                // curA较小或者与curB相等
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

        // 走完循环后肯定存在一个链表未走完
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

// 不创建新节点
class Solution21_2
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 新链表的头结点
        ListNode *mergeHead = new ListNode;
        // 定义两个头结点从前往后遍历
        ListNode *curA = list1;
        ListNode *curB = list2;
        // 定义一个节点指向新链表的尾结点
        ListNode *tail = mergeHead;

        // 有一个节点到结尾就停止
        while (curA && curB)
        {
            if (curA->val > curB->val)
            {
                // curB小尾插到新链表
                tail->next = curB;
                curB = curB->next;
            }
            else
            {
                // curA较小或者与curB相等
                tail->next = curA;
                curA = curA->next;
            }
            tail = tail->next;
        }

        // 走完循环后肯定存在一个链表未走完
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

// 递归写法——前面写法的进阶版
class Solution21_3
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 定义两个头结点从前往后遍历
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