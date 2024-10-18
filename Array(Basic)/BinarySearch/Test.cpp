//
// Created by 18483 on 2024/10/18.
//
#include <algorithm>

#include "BinarySearch.h"

int main()
{
    int target = 0;
    std::cin >> target;
    std::vector<int> v{2, 3, 34, 23, 90, 36, 22, 123, 45};
    // 二分查找使用前提：有序且元素唯一（元素不唯一可能返回的下标不唯一）
    std::sort(v.begin(), v.end());
    // 给flag传递值时调用左闭右闭原则的二分查找
    int pos = Array_Basic::BinarySearch(v, target);
    if (pos == -1)
        std::cout << "not exist" << std::endl;
    else
        std::cout << "exist" << std::endl;

    return 0;
}