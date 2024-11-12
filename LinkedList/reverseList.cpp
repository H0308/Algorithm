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
// 写法1
class Solution206_1_1
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

// 写法2
class Solution206_1_2
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        // 直接将prev初始化为nullptr
        // 使cur每一次更改next时指向prev即可
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
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

// 递归版本——双指针变型
class Solution206_3
{
public:
    ListNode *_reverseList(ListNode *cur, ListNode *prev)
    {
        // 递归终止条件——循环终止条件
        if (cur == nullptr)
            // 循环结束后的步骤
            return prev;

        // 反转——循环中的过程
        ListNode *temp = cur->next;
        cur->next = prev;
        // 再次的赋值操作相当于为下一次的循环做准备
        // 在递归中相当于再次调用翻转函数
        return _reverseList(temp, cur);
    }

    ListNode *reverseList(ListNode *head)
    {
        // 相当于双指针中创建cur和prev并初始化
        return _reverseList(head, nullptr);
    }
};
