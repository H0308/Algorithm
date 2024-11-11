//
// Created by 18483 on 2024/11/11.
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

// 力扣206.反转链表
// 迭代：原地处理
class Solution206_1
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = head;
        ListNode *cur = head;

        while (cur)
        {
            if (cur == head)
            {
                cur = cur->next;
                prev->next = nullptr;
            }
            else
            {
                ListNode *temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
        }

        head = prev;

        return head;
    }
};

// 迭代：异地处理
class Solution206_2
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *copyHead = new ListNode;

        ListNode *curA = head;

        // 头插思路
        while (curA)
        {
            // 创建新节点
            ListNode *newNode = new ListNode(curA->val);
            if (copyHead->next == nullptr)
            {
                copyHead->next = newNode;
            }
            else
            {
                ListNode *cur = copyHead->next;
                newNode->next = cur;
                copyHead->next = newNode;
            }
            curA = curA->next;
        }

        return copyHead->next;
    }
};
