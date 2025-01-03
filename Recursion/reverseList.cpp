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

// 力扣206.反转链表
// 递归思路
/*
 * 此次递归的思路与之前根据循环转递归的思路不同，本次递归的思路：
 * 要直接反转第一个节点和第二个节点，就会丢失第三个节点，考虑先翻转后面的节点，翻转后面的节点的思路与翻转第一个和第二个是相同的，所以就是重复的子问题
 * 使用后序遍历找到最后一个节点，如果当前节点的下一个节点为空时，说明是最后一个节点，将这个节点返回作为新链表的头结点
 * 再翻转当前节点（倒数第二个节点）和当前节点的下一个节点（最后一个节点），注意翻转完成后将当前节点的next置为空，
 * 这个是统一处理，因为翻转后的链表的最后一个节点的next需要指向空，最后继续向上返回反转后的链表的头结点
 */
class Solution206
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
