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

// 力扣21.合并两个有序链表
// 递归解法
/*
 * 要想使用递归进行解决就必须找到重复的子问题，可以先从主问题入手，主问题是合并链表，
 * 而合并的本质就是在两个链表中找到较大的尾插，即将较小的节点作为前驱节点，
 * 那么此时较小节点所在的链表剩余节点构成的链表和另外一个链表的合并就构成了和主问题相同的一个子问题
 * 找到重复的子问题后就可以设计函数头：因为合并链表需要用到两个链表的头，所以参数需要两个链表的头指针，并且函数需要返回一个头结点
 * 接着设计函数体：将较小的作为链表头，本质就是将较小节点的next指向下一个较大的节点，所以分为两种情况：
 * 1. list1较小，向后移动list1，将此时的list1和list2再重复合并操作，合并完成后返回较小的节点作为新链表的头结点
 * 2. list2较小，向后移动list2，将此时的list1和list2再重复合并操作，合并完成后返回较小的节点作为新链表的头结点
 */
class Solution21
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 递归出口——其中一个走到空就返回另外一个链接到结尾
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        // 较小的作为前驱节点链接
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

        // 不可达的return，但是为了防止编译器报错
        return nullptr;
    }
};
