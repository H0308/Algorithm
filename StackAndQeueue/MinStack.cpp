//
// Created by 18483 on 2025/4/28.
//
#include <stack>
using namespace std;
class MinStack
{
public:
    MinStack()
    {
        // ����ջ�ṹ�Ĺ��캯����ʼ��
    }

    void push(int val)
    {
        // �����ǰ��С����ջΪ�ջ��߲��������С�ڵ�ǰ��С����ջ��ջ��Ԫ�ؾͲ��뵽��С����ջ
        // �����СԪ��ҲҪ���룬��ֹ����ͳһ���ݵ�ջ�����쳣
        if(min_st_.empty() || min_st_.top() >= val)
            min_st_.push(val);
        // ����Ԫ���������뵽��ͨ����ջ
        st_.push(val);
    }

    void pop()
    {
        // ������ͨ����ջ��Ԫ��
        // һ������������С����ջ��ͬ��Ԫ��Ҳ��Ҫ������Ԫ��
        // ������һ����ջ
        if(!min_st_.empty() && min_st_.top() == st_.top())
            min_st_.pop();

        // ֱ�ӵ�����ͨ����ջ
        st_.pop();
    }

    int top()
    {
        return st_.top();
    }

    int getMin()
    {
        return min_st_.top();
    }

private:
    stack<int> st_; // ��ͨ����ջ
    stack<int> min_st_; // �洢��С����ջ
};