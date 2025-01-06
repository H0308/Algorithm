//
// Created by 18483 on 2025/1/6.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣77.组合
// 回溯思路——需要根据参数决定循环嵌套的层数，所以直接使用循环无法解决
/*
 * 所谓组合，就是枚举所有的可能的情况并且不重复，本题根据参数给一组数，例如1234
 * 那么所有的组合就是：
 * 1:12,13,14
 * 2:23,24
 * 3:34
 * 注意，在2、3开始时不能出现2、3前面的数字，例如不能出现21，因为在组合中21和12是同一组，此时重复，并且同一个数字不能在一组中使用多次
 * 暴力解法很简单，因为只需要取出两个数，所以两层for循环就能解决，但是本题的问题就在于循环的层数是由参数确定的，所以直接写循环就无法做到
 * 但是递归可以，函数执行一层就是一层for循环，在for循环内递归当前函数就可以实现主调函数内继续一层for循环
 * 而任何递归都是都终止条件的，所以本题的终止条件就是层数，因为在上面的例子中一组数的个数只需要两个，所以只需要每一组执行一次函数递归一次即可
 * 但是for循环的起始位置必须是可变的，因为要根据调用者的下标取出其后面的数值，所以可以使用一个参数传递给递归函数，即为start
 * 当递归要返回时，说明此时已经有了一个组合，将该结果插入到结果集再返回即可，返回到主调函数一定要删除上一个组合的最后一个数据，因为for循环还要继续执行，继续向后插入数据
 * 如果不删除上一次的最后一个数字，就会出现一直向后插入的现象
 */
class Solution77_1
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(int n, int k, int start)
    {
        if (path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            // 函数递归回到此处，path中依旧存在着两个元素，因为进入前的现场就是两个元素
            dfs(n, k, i + 1);
            // 恢复现场——path只有一个元素时，进入下一次循环
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return ret;
    }
};

// 剪枝优化——结合画图分析
// 在求取组合的过程中可以发现，如果剩余的元素个数加上当前的元素不足以满足一个组合需要的元素个数，此时就一定不会存在结果
// 根据这个特点也就可以进行剪枝，所谓的「如果剩余的元素个数加上当前的元素不足以满足一个组合需要的元素个数」
// 也就是说元素总个数-（一个组合需要的元素个数-已经拿到的元素个数）+1如果小于当前下标就一定不存在结果
// 其中上面的表达式的意思就是：「一个组合需要的元素个数-已经拿到的元素个数」表示构成一个组合还需要多少元素，总数减去需要的元素个数+1就是算出最多能取到的元素的位置
// 即n-(k-path.size())+1，注意因为左闭右闭，所以需要加1
class Solution77_2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(int n, int k, int start)
    {
        if (path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        // 缩小i的循环范围
        for (int i = start; i <= (n - (k - path.size()) + 1); i++)
        {
            path.push_back(i);
            // 函数递归回到此处，path中依旧存在着两个元素，因为进入前的现场就是两个元素
            dfs(n, k, i + 1);
            // 恢复现场——path只有一个元素时，进入下一次循环
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        dfs(n, k, 1);
        return ret;
    }
};
