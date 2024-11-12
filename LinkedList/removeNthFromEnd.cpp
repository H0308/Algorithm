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
// 解法1：计算链表长度反向找到倒数第n个节点
class Solution19_1
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

// 解法2：快慢指针
/* 定义fast指针和slow指针
 * 倒数第n个节点，说明该节点距离最后一个节点相差n-1节点，
 * 所以先让fast指针走n步，保证在slow和fast同时走时，fast到链表结尾，slow和fast相差n-1个节点
 *
 * 为了便于删除，依旧是引入虚拟头节点指向链表的第一个节点，并且因为在单链表中删除节点时，
 * 获取到待删除节点的前一个节点会更加方便，所以让slow和fast在一开始就相差1
 */
class Solution19_2
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode;
        dummy->next = head;

        ListNode *fast = dummy->next;
        ListNode *slow = dummy;
        // 先让fast走n步
        while (n)
        {
            fast = fast->next;
            --n;
        }

        // slow和fast同时走
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // slow指向待删除节点的前一个节点
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};
