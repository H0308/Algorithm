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
    // ���ֲ���ʹ��ǰ�᣺������Ԫ��Ψһ��Ԫ�ز�Ψһ���ܷ��ص��±겻Ψһ��
    std::sort(v.begin(), v.end());
    // ��flag����ֵʱ��������ұ�ԭ��Ķ��ֲ���
    int pos = Array_Basic::BinarySearch(v, target);
    if (pos == -1)
        std::cout << "not exist" << std::endl;
    else
        std::cout << "exist" << std::endl;

    return 0;
}