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

// ����������02.07.�����ཻ
class Solution0207
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // ��ȡ��������ĳ���
        int lengthA = 0;
        ListNode *curA = headA;
        while (curA)
        {
            lengthA++;
            curA = curA->next;
        }
        int lengthB = 0;
        ListNode *curB = headB;
        while (curB)
        {
            lengthB++;
            curB = curB->next;
        }

        // ��ȡ��ֵ
        int diff = lengthA > lengthB ? lengthA - lengthB : lengthB - lengthA;

        ListNode *longList = headA;
        ListNode *shortList = headB;
        if (lengthA < lengthB)
        {
            longList = headB;
            shortList = headA;
        }
        // �ó���������diff��
        while (diff--)
        {
            longList = longList->next;
        }

        // ���ö���һ����ֱ������
        while (longList && shortList)
        {
            if (longList == shortList)
            {
                return longList;
            }

            longList = longList->next;
            shortList = shortList->next;
        }

        return nullptr;
    }
};
