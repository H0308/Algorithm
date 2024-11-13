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

// ����������02.04.�ָ�����
class Solution0204
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        // ��������ڵ㹹��������
        ListNode *dummy = new ListNode;
        // ������һ��С�Ľڵ�
        ListNode *little = dummy;
        // ָ���¼�������β�ڵ�
        ListNode *tail = dummy;
        // ����ԭ����
        // С��x�Ĳ��뵽���ڵ���x��ǰ�棬���ڵ���x��ֱ��β��
        ListNode *cur = head;
        while (cur)
        {
            if (cur->val < x)
            {
                // С����ǰ��
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
                // ���ֱ��β��
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