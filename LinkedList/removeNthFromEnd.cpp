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

// ����19.ɾ������ĵ����� N �����
class Solution19
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // ��ȡ����ĳ���
        int sz = 0;
        ListNode *cur = head;
        while (cur)
        {
            cur = cur->next;
            sz++;
        }

        // ��ȡ�±�
        int index = sz - n;

        // �����±�ɾ����Ӧ�Ľڵ�
        ListNode *dummy = new ListNode;

        dummy->next = head;
        ListNode *prev = dummy;
        cur = dummy->next;

        for (int i = 0; i < index; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        // ɾ���ڵ�
        if (index == 0)
        {
            // ���indexΪ0��˵��ɾ�����ǵ�һ���ڵ�
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
