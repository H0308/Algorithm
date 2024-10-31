//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;

// 卡码网KamaCoder.区间和：暴力解法
int main1()
{
    // 解除同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 输入数组长度
    int len = 0;
    cin >> len;

    vector<int> arr(len);

    for(int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int a = 0, b = 0;
    int sum = 0;
    while(cin >> a >> b)
    {
        for(int i = a; i <= b; i++)
        {
            sum += arr[i];
        }
        cout << sum << endl;

        sum = 0;
    }

    return 0;
}

// 卡码网KamaCoder.区间和：前缀和解法——写法1
int main2()
{
    // 解除同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 输入数组长度
    int len = 0;
    cin >> len;

    vector<int> arr(len);
    // 前缀和数组
    vector<int> prefixSum(len + 1, 0);

    for(int i = 0; i < len; i++)
    {
        cin >> arr[i];
        // 计算前缀和：前i个元素的和
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    int a = 0, b = 0;
    while(cin >> a >> b)
    {
        // 输出区间和
        cout << prefixSum[b + 1] - prefixSum[a] << endl;
    }

    return 0;
}

// 卡码网KamaCoder.区间和：前缀和解法——写法2
int main3()
{
    // 解除同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 输入数组长度
    int len = 0;
    cin >> len;

    // 元素数组
    vector<int> arr(len);
    // 前缀和数组
    vector<int> sum(len);

    int preSum = 0;
    for(int i = 0; i < len; i++)
    {
        cin >> arr[i];

        // 计算前缀和
        preSum += arr[i];
        sum[i] = preSum;
    }

    int a = 0, b = 0;
    while(cin >> a >> b)
    {
        // 求和
        if(a == 0)
        {
            cout << sum[b] << endl;
        }
        else
        {
            cout << sum[b] - sum[a - 1] << endl;
        }
    }

    return 0;
}

// 牛客网DP34.【模版】前缀和
int mainDP34() {
    int n, q;
    while (cin >> n >> q) {
        // 注意使用long long防止溢出
        long long sumArr = 0;
        vector<long long> arr(n);
        vector<long long> sum(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sumArr += arr[i];
            sum[i] = sumArr;
        }

        int l = 0, r = 0;
        for (int i = 0; i < q; i++) {
            cin >> l >> r;

            if (l - 1 == 0) {
                cout << sum[r - 1] << endl;
            } else {
                cout << sum[r - 1] - sum[l - 2] << endl;
            }
        }
    }
}