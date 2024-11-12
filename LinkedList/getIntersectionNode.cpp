//
// Created by 18483 on 2024/11/12.
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

// 力扣面试题02.07.链表相交
class Solution0207
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 获取两个链表的长度
        int lengthA = 0;
        ListNode *curA = headA;
        while (curA)
        {
            lengthA++;
            curA = curA->next;
        }
        int lengthB = 0;
        ListNode *curB = headB;
        while (curB)
        {
            lengthB++;
            curB = curB->next;
        }

        // 获取差值
        int diff = lengthA > lengthB ? lengthA - lengthB : lengthB - lengthA;

        ListNode *longList = headA;
        ListNode *shortList = headB;
        if (lengthA < lengthB)
        {
            longList = headB;
            shortList = headA;
        }
        // 让长链表先走diff步
        while (diff--)
        {
            longList = longList->next;
        }

        // 再让二者一起走直到相遇
        while (longList && shortList)
        {
            if (longList == shortList)
            {
                return longList;
            }

            longList = longList->next;
            shortList = shortList->next;
        }

        return nullptr;
    }
};
