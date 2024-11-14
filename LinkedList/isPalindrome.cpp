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

// ����234.��������
// ����������
class Solution234_1
{
public:
    bool isPalindrome(ListNode *head)
    {
        // ����������
        int count = 0;
        ListNode *cur = head;
        while (cur)
        {
            count++;
            cur = cur->next;
        }
        // ���ҵ��м���
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // �����м����������
        ListNode *front = head;
        ListNode *back = count % 2 == 0 ? slow : slow->next;

        // ���󲿷ֵ�������Ϊ�µ�������ͷ��
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

// ������������
class Solution234_2
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return true;
        }

        // �ҵ�ǰ�벿�������β�ڵ㲢��ת��벿������
        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

        // �ж��Ƿ����
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // ��ԭ�������ؽ��
        firstHalfEnd->next = reverseList(secondHalfStart);
        return result;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *nextTemp = curr->next;
            // ͷ��
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode *endOfFirstHalf(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
