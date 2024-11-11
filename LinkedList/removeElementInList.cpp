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

// 力扣203.移除链表元素
// 解法1：直接删除
// 使用头结点
class Solution203_1_1
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 删除头结点
        while (head != NULL && head->val == val)
        {
            // 注意这里不是if
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头结点
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

// 不使用头结点
// 注意，此处的head不代表是头结点，而是实际存储有效数据的节点
class Solution203_1_2
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }

        // 引入新节点指向头节点
        ListNode *dummy = new ListNode;
        dummy->next = head;


        // 定义前驱节点
        ListNode *prev = dummy;
        // 定义起始节点
        ListNode *cur = dummy->next;

        while (cur)
        {
            if (cur->val == val)
            {
                // 删除节点
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

// 解法2：异地处理
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