//
// Created by 18483 on 2024/11/11.
//
#include <iostream>
using namespace std;

// ��������ڵ�
struct ListNode
{
    // ������
    int val;
    ListNode *next;

    // ���캯��
    ListNode(int _val = 0, ListNode *_next = nullptr)
        : val(_val)
        , next(_next)
    {}
};

// ����707.�������
// ��������
namespace singleLinkedList
{
    class MyLinkedList
    {
    public:
        MyLinkedList()
            : _size(0)
        {
            // ʹ��ͷ���
            _head = new ListNode;
        }

        int get(int index)
        {
            // ��Ч�±귵��-1
            if (index < 0 || index >= _size)
            {
                return -1;
            }

            // ��ǰλ��
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
            // ���뵽ͷ����
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

            // �ҵ�β�ڵ�
            while (cur->next)
            {
                cur = cur->next;
            }

            cur->next = newNode;
            ++_size;
        }

        void addAtIndex(int index, int val)
        {
            // �Ƿ��±���ֹ����
            if (index < 0 || index > _size)
            {
                return;
            }

            // �պõ���������ʱ�൱��β��
            if (index == _size)
            {
                addAtTail(val);
                // ע��˴���Ҫ�ٴ���_size
                return;
            }

            // ����0����ͷ��
            if (index == 0)
            {
                addAtHead(val);
                // ע��˴���Ҫ�ٴ���_size
                return;
            }

            // ������뵽ָ���ڵ�֮ǰ
            // ��ȡָ��Ԫ��
            int target = get(index);
            // û��ָ��Ԫ�أ����������
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
            // �Ƿ��±���ֹ����
            if (index < 0 || index >= _size)
            {
                return;
            }

            // ��ȡindex��Ӧ��Ԫ��
            int target = get(index);

            // �ҵ�ָ��Ԫ��ɾ��
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
        // ����ͷ���
        ListNode *_head;
        // ������Ч���ݸ���
        int _size;
    };
}

// ˫������
namespace DoubleLinkedList
{
    struct DoubleListNode
    {
        // ������
        int val;
        // ָ����
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
            // �����½ڵ�
            DoubleListNode *newNode = new DoubleListNode(val);
            // ���ڵ���뵽ͷ���ĺ�
            if (_head->next == _head)
            {
                // ����ͷ���
                _head->next = newNode;
                _head->prev = newNode;

                // �����½ڵ�
                newNode->prev = _head;
                newNode->next = _head;
            }
            else
            {
                DoubleListNode *cur = _head->next;
                // �����½ڵ�����
                newNode->next = cur;
                newNode->prev = _head;
                // ����ɽڵ������
                cur->prev = newNode;
                _head->next = newNode;
            }

            ++_size;
        }

        void addAtTail(int val)
        {
            // �����½ڵ�
            DoubleListNode *newNode = new DoubleListNode(val);
            // �ҵ�β�ڵ�
            if (_head->prev == _head)
            {
                // ����ͷ���
                _head->prev = newNode;
                _head->next = newNode;

                // �����½��
                newNode->prev = _head;
                newNode->next = _head;
            }
            else
            {
                DoubleListNode *cur = _head->prev;
                // �����½ڵ�
                newNode->prev = cur;
                newNode->next = _head;
                // ����ɽڵ�
                cur->next = newNode;
                _head->prev = newNode;
            }

            ++_size;
        }

        void addAtIndex(int index, int val)
        {
            // �Ƿ��±���ֹ����
            if (index < 0 || index > _size)
            {
                return;
            }

            // �պõ���������ʱ�൱��β��
            if (index == _size)
            {
                addAtTail(val);
                // ע��˴���Ҫ�ٴ���_size
                return;
            }

            // ����0����ͷ��
            if (index == 0)
            {
                addAtHead(val);
                // ע��˴���Ҫ�ٴ���_size
                return;
            }

            // �����½ڵ�
            DoubleListNode *newNode = new DoubleListNode(val);

            DoubleListNode *cur = _head->next;

            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }

            DoubleListNode *curPrev = cur->prev;
            // �����½ڵ�
            newNode->next = cur;
            newNode->prev = curPrev;

            // ����ɽڵ�
            cur->prev = newNode;
            curPrev->next = newNode;

            ++_size;
        }

        void deleteAtIndex(int index)
        {
            // �Ƿ��±���ֹɾ��
            if (index < 0 || index >= _size)
            {
                return;
            }

            DoubleListNode *cur = _head->next;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }

            // ɾ����ǰcur
            DoubleListNode *toDelete = cur;
            DoubleListNode *curPrev = cur->prev;
            DoubleListNode *curNext = cur->next;

            curPrev->next = curNext;
            curNext->prev = curPrev;

            --_size;
        }

    private:
        // ͷ���
        DoubleListNode *_head;
        // �����С
        int _size;
    };
}
