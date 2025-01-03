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

// ����24.�������������еĽڵ�
/*
 * ����˼·�뷴ת�����еĽڵ�˼·����һ�£���Ϊ�޷�ȷ�������ڵ㽻����ĵڶ����ڵ���һ��ָ��ָ����һ���ڵ㣬����������Ҫ�������
 * ���������Ĳ����ٷ����µ�ͷ���
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
        // �����߼�
        head->next->next = head;
        head->next = newHead;

        // �����µ�ͷ���
        return ret;
    }
};