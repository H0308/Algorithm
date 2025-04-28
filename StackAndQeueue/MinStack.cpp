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
        // 调用栈结构的构造函数初始化
    }

    void push(int val)
    {
        // 如果当前最小数据栈为空或者插入的数据小于当前最小数据栈的栈顶元素就插入到最小数据栈
        // 相等最小元素也要插入，防止后续统一数据弹栈出现异常
        if(min_st_.empty() || min_st_.top() >= val)
            min_st_.push(val);
        // 其他元素正常插入到普通数据栈
        st_.push(val);
    }

    void pop()
    {
        // 弹出普通数据栈的元素
        // 一旦遇到了与最小数据栈相同的元素也需要弹出该元素
        // 便于下一次入栈
        if(!min_st_.empty() && min_st_.top() == st_.top())
            min_st_.pop();

        // 直接弹出普通数据栈
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
    stack<int> st_; // 普通数据栈
    stack<int> min_st_; // 存储最小数据栈
};