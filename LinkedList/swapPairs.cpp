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

// ����24.�������������еĽڵ�
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
            // ����
            ListNode *curNext = cur->next;
            // curNextΪ�գ�˵��ʣ��Ľڵ�����Ϊ����
            // ֱ���˳�
            if (curNext == nullptr)
                break;
            prev->next = curNext;
            cur->next = curNext->next;
            curNext->next = cur;
            // �ƶ�ǰ����
            cur = prev->next;
            // �ƶ�
            prev = prev->next->next;
            cur = cur->next->next;
        }

        return dummy->next;
    }
};
