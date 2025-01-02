//
// Created by 18483 on 2025/1/2.
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

// ����21.�ϲ�������������
// �ݹ�ⷨ
/*
 * Ҫ��ʹ�õݹ���н���ͱ����ҵ��ظ��������⣬�����ȴ����������֣��������Ǻϲ�����
 * ���ϲ��ı��ʾ����������������ҵ��ϴ��β�壬������С�Ľڵ���Ϊǰ���ڵ㣬
 * ��ô��ʱ��С�ڵ����ڵ�����ʣ��ڵ㹹�ɵ����������һ������ĺϲ��͹����˺���������ͬ��һ��������
 * �ҵ��ظ����������Ϳ�����ƺ���ͷ����Ϊ�ϲ�������Ҫ�õ����������ͷ�����Բ�����Ҫ���������ͷָ�룬���Һ�����Ҫ����һ��ͷ���
 * ������ƺ����壺����С����Ϊ����ͷ�����ʾ��ǽ���С�ڵ��nextָ����һ���ϴ�Ľڵ㣬���Է�Ϊ���������
 * 1. list1��С������ƶ�list1������ʱ��list1��list2���ظ��ϲ��������ϲ���ɺ󷵻ؽ�С�Ľڵ���Ϊ�������ͷ���
 * 2. list2��С������ƶ�list2������ʱ��list1��list2���ظ��ϲ��������ϲ���ɺ󷵻ؽ�С�Ľڵ���Ϊ�������ͷ���
 */
class Solution21
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // �ݹ���ڡ�������һ���ߵ��վͷ�������һ�����ӵ���β
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        // ��С����Ϊǰ���ڵ�����
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else if (list1->val > list2->val)
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

        // ���ɴ��return������Ϊ�˷�ֹ����������
        return nullptr;
    }
};
