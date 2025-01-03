//
// Created by 18483 on 2025/1/3.
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
/*
 * 本题思路与反转链表中的节点思路基本一致，以为无法确定两个节点交换后的第二个节点下一个指针指向哪一个节点，所以依旧需要后序遍历
 * 处理完后面的部分再返回新的头结点
 */
class Solution24
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *newHead = swapPairs(head->next->next);
        ListNode *ret = head->next;
        // 交换逻辑
        head->next->next = head;
        head->next = newHead;

        // 返回新的头结点
        return ret;
    }
};