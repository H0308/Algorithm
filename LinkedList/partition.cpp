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

// 力扣面试题02.04.分割链表
class Solution0204
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // 创建虚拟节点构建新链表
        ListNode *dummy = new ListNode;
        // 保存上一个小的节点
        ListNode *little = dummy;
        // 指针记录新链表的尾节点
        ListNode *tail = dummy;
        // 遍历原链表
        // 小于x的插入到大于等于x的前面，大于等于x的直接尾插
        ListNode *cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                // 小的向前插
                ListNode *newNode = new ListNode(cur->val);
                if (dummy->next == nullptr)
                {
                    dummy->next = newNode;
                    little = newNode;
                }
                else
                {
                    newNode->next = little->next;
                    little->next = newNode;
                    little = little->next;
                }

                if (little->next == nullptr)
                {
                    tail = little;
                }
            }
            else
            {
                // 大的直接尾插
                ListNode *newNode = new ListNode(cur->val);
                if (dummy->next == nullptr)
                {
                    dummy->next = newNode;
                }
                else
                {
                    tail->next = newNode;
                }
                tail = tail->next;
            }
            cur = cur->next;
        }

        return dummy->next;
    }
};