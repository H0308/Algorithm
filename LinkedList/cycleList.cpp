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

// 力扣141.环形链表
// Floyd判圈算法
class Solution141
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};

// 力扣142.环形链表Ⅱ
// Floyd判圈算法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next)
        {

            if(fast == slow)
            {
                ListNode* index1 = head;
                ListNode* index2 = slow;

                while(index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }

                return index1;
            }

            fast = fast->next->next;
            slow = slow->next;
        }

        return nullptr;
    }
};