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

// 力扣24.两两交换链表中的节点
class Solution24
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode;
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *cur = dummy->next;

        while (prev && cur)
        {
            // 交换
            ListNode *curNext = cur->next;
            // curNext为空，说明剩余的节点数量为奇数
            // 直接退出
            if (curNext == nullptr)
                break;
            prev->next = curNext;
            cur->next = curNext->next;
            curNext->next = cur;
            // 移动前修正
            cur = prev->next;
            // 移动
            prev = prev->next->next;
            cur = cur->next->next;
        }

        return dummy->next;
    }
};
