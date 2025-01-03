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

// ����206.��ת����
// �ݹ�˼·
/*
 * �˴εݹ��˼·��֮ǰ����ѭ��ת�ݹ��˼·��ͬ�����εݹ��˼·��
 * Ҫֱ�ӷ�ת��һ���ڵ�͵ڶ����ڵ㣬�ͻᶪʧ�������ڵ㣬�����ȷ�ת����Ľڵ㣬��ת����Ľڵ��˼·�뷭ת��һ���͵ڶ�������ͬ�ģ����Ծ����ظ���������
 * ʹ�ú�������ҵ����һ���ڵ㣬�����ǰ�ڵ����һ���ڵ�Ϊ��ʱ��˵�������һ���ڵ㣬������ڵ㷵����Ϊ�������ͷ���
 * �ٷ�ת��ǰ�ڵ㣨�����ڶ����ڵ㣩�͵�ǰ�ڵ����һ���ڵ㣨���һ���ڵ㣩��ע�ⷭת��ɺ󽫵�ǰ�ڵ��next��Ϊ�գ�
 * �����ͳһ������Ϊ��ת�����������һ���ڵ��next��Ҫָ��գ����������Ϸ��ط�ת��������ͷ���
 */
class Solution206
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
