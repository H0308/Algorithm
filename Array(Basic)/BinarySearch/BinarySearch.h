//
// Created by 18483 on 2024/10/18.
//

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <iostream>
#include <vector>
#include <numeric>
namespace Array_Basic
{
    // ���ֲ��ң�����ұ�
    // flag�ڶ��ֲ�����û�����壬ֻ��Ϊ����������ұպ�����ҿ�
    int BinarySearch(std::vector<int> &nums, int target, int flag);
    // ���ֲ��ң�����ҿ�
    int BinarySearch(std::vector<int>& nums, int target);
}

#endif //BINARYSEARCH_H
