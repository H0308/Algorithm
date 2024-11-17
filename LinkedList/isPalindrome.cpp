//
// Created by 18483 on 2024/11/14.
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

// 力扣234.回文链表
// 创建新链表
class Solution234_1
{
public:
    bool isPalindrome(ListNode *head)
    {
        // 计算链表长度
        int count = 0;
        ListNode *cur = head;
        while (cur)
        {
            count++;
            cur = cur->next;
        }
        // 先找到中间结点
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 根据中间结点遍历链表
        ListNode *front = head;
        ListNode *back = count % 2 == 0 ? slow : slow->next;

        // 将后部分的链表构建为新的链表——头插
        ListNode *copyHead = new ListNode;
        cur = copyHead;
        while (cur && back)
        {
            ListNode *newNode = new ListNode(back->val);
            if (copyHead->next == nullptr)
            {
                copyHead->next = newNode;
            }
            else
            {
                newNode->next = cur;
                copyHead->next = newNode;
            }
            cur = newNode;
            back = back->next;
        }

        back = copyHead->next;

        while (front && back)
        {
            if (front->val != back->val)
                return false;

            front = front->next;
            back = back->next;
        }

        return true;
    }
};