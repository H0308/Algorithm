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
    // 二分查找，左闭右闭
    // flag在二分查找中没有意义，只是为了区分左闭右闭和左闭右开
    int BinarySearch(std::vector<int> &nums, int target, int flag);
    // 二分查找，左闭右开
    int BinarySearch(std::vector<int>& nums, int target);
}

#endif //BINARYSEARCH_H
