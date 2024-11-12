//
// Created by 18483 on 2024/11/12.
//
#include <iostream>
using namespace std;

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

// 力扣19.删除链表的倒数第 N 个结点
class Solution19
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 获取链表的长度
        int sz = 0;
        ListNode *cur = head;
        while (cur)
        {
            cur = cur->next;
            sz++;
        }

        // 获取下标
        int index = sz - n;

        // 根据下标删除对应的节点
        ListNode *dummy = new ListNode;

        dummy->next = head;
        ListNode *prev = dummy;
        cur = dummy->next;

        for (int i = 0; i < index; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        // 删除节点
        if (index == 0)
        {
            // 如果index为0，说明删除的是第一个节点
            dummy->next = head->next;
            delete head;
        }
        else
        {
            prev->next = cur->next;
            delete cur;
        }

        return dummy->next;
    }
};
