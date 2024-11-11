//
// Created by 18483 on 2024/11/11.
//
#include <iostream>
using namespace std;

// 单向链表节点
struct ListNode
{
    // 数据域
    int val;
    ListNode *next;

    // 构造函数
    ListNode(int _val = 0, ListNode *_next = nullptr)
        : val(_val)
        , next(_next)
    {}
};

// 力扣707.设计链表
// 单向链表
namespace singleLinkedList
{
    class MyLinkedList
    {
    public:
        MyLinkedList()
            : _size(0)
        {
            // 使用头结点
            _head = new ListNode;
        }

        int get(int index)
        {
            // 无效下标返回-1
            if (index < 0 || index >= _size)
            {
                return -1;
            }

            // 当前位置
            ListNode *cur = _head->next;
            while (cur && index >= 0)
            {
                if (index == 0)
                {
                    return cur->val;
                }
                cur = cur->next;
                index--;
            }

            return -1;
        }

        void addAtHead(int val)
        {
            // 插入到头结点后
            ListNode *newNode = new ListNode(val);

            if (_head->next == nullptr)
            {
                _head->next = newNode;
            }
            else
            {
                ListNode *cur = _head->next;
                newNode->next = cur;
                _head->next = newNode;
            }

            ++_size;
        }

        void addAtTail(int val)
        {
            ListNode *newNode = new ListNode(val);

            ListNode *cur = _head;
            if (cur->next == nullptr)
            {
                cur->next = newNode;
                ++_size;
                return;
            }

            // 找到尾节点
            while (cur->next)
            {
                cur = cur->next;
            }

            cur->next = newNode;
            ++_size;
        }

        void addAtIndex(int index, int val)
        {
            // 非法下标阻止插入
            if (index < 0 || index > _size)
            {
                return;
            }

            // 刚好等于链表长度时相当于尾插
            if (index == _size)
            {
                addAtTail(val);
                // 注意此处不要再处理_size
                return;
            }

            // 等于0代表头插
            if (index == 0)
            {
                addAtHead(val);
                // 注意此处不要再处理_size
                return;
            }

            // 否则加入到指定节点之前
            // 获取指定元素
            int target = get(index);
            // 没有指定元素，不允许插入
            if (target == -1)
            {
                return;
            }

            ListNode *cur = _head->next;
            ListNode *prev = _head;
            while (cur)
            {
                if (cur->val == target && index == 0)
                {
                    break;
                }
                prev = cur;
                cur = cur->next;
                --index;
            }

            ListNode *newNode = new ListNode(val);

            newNode->next = cur;
            prev->next = newNode;

            ++_size;
        }

        void deleteAtIndex(int index)
        {
            // 非法下标阻止插入
            if (index < 0 || index >= _size)
            {
                return;
            }

            // 获取index对应的元素
            int target = get(index);

            // 找到指定元素删除
            ListNode *prev = _head;
            ListNode *cur = _head->next;

            while (cur)
            {
                if (cur->val == target && index == 0)
                {
                    ListNode *toDelete = cur;
                    prev->next = cur->next;
                    delete toDelete;
                    --_size;
                    break;
                }

                prev = cur;
                cur = cur->next;
                --index;
            }
        }

    private:
        // 创建头结点
        ListNode *_head;
        // 链表有效数据个数
        int _size;
    };
}

// 双向链表
namespace DoubleLinkedList
{
    struct DoubleListNode
    {
        // 数据域
        int val;
        // 指针域
        DoubleListNode *next;
        DoubleListNode *prev;

        DoubleListNode(int _val = 0)
            : val(_val)
            , next(nullptr)
            , prev(nullptr)
        {}
    };

    class MyLinkedList
    {
    public:
        MyLinkedList()
            : _size(0)
        {
            _head = new DoubleListNode;
            _head->next = _head;
            _head->prev = _head;
        }

        int get(int index)
        {
            if (index < 0 || index >= _size)
                return -1;

            DoubleListNode *cur = _head->next;

            for (int i = 1; i <= index; i++)
            {
                cur = cur->next;
            }

            if (cur == _head)
            {
                return -1;
            }

            return cur->val;
        }

        void addAtHead(int val)
        {
            // 创建新节点
            DoubleListNode *newNode = new DoubleListNode(val);
            // 将节点插入到头结点的后方
            if (_head->next == _head)
            {
                // 处理头结点
                _head->next = newNode;
                _head->prev = newNode;

                // 处理新节点
                newNode->prev = _head;
                newNode->next = _head;
            }
            else
            {
                DoubleListNode *cur = _head->next;
                // 处理新节点连接
                newNode->next = cur;
                newNode->prev = _head;
                // 处理旧节点的连接
                cur->prev = newNode;
                _head->next = newNode;
            }

            ++_size;
        }

        void addAtTail(int val)
        {
            // 创建新节点
            DoubleListNode *newNode = new DoubleListNode(val);
            // 找到尾节点
            if (_head->prev == _head)
            {
                // 处理头结点
                _head->prev = newNode;
                _head->next = newNode;

                // 处理新结点
                newNode->prev = _head;
                newNode->next = _head;
            }
            else
            {
                DoubleListNode *cur = _head->prev;
                // 处理新节点
                newNode->prev = cur;
                newNode->next = _head;
                // 处理旧节点
                cur->next = newNode;
                _head->prev = newNode;
            }

            ++_size;
        }

        void addAtIndex(int index, int val)
        {
            // 非法下标阻止插入
            if (index < 0 || index > _size)
            {
                return;
            }

            // 刚好等于链表长度时相当于尾插
            if (index == _size)
            {
                addAtTail(val);
                // 注意此处不要再处理_size
                return;
            }

            // 等于0代表头插
            if (index == 0)
            {
                addAtHead(val);
                // 注意此处不要再处理_size
                return;
            }

            // 创建新节点
            DoubleListNode *newNode = new DoubleListNode(val);

            DoubleListNode *cur = _head->next;

            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }

            DoubleListNode *curPrev = cur->prev;
            // 处理新节点
            newNode->next = cur;
            newNode->prev = curPrev;

            // 处理旧节点
            cur->prev = newNode;
            curPrev->next = newNode;

            ++_size;
        }

        void deleteAtIndex(int index)
        {
            // 非法下标阻止删除
            if (index < 0 || index >= _size)
            {
                return;
            }

            DoubleListNode *cur = _head->next;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }

            // 删除当前cur
            DoubleListNode *toDelete = cur;
            DoubleListNode *curPrev = cur->prev;
            DoubleListNode *curNext = cur->next;

            curPrev->next = curNext;
            curNext->prev = curPrev;

            --_size;
        }

    private:
        // 头结点
        DoubleListNode *_head;
        // 链表大小
        int _size;
    };
}
