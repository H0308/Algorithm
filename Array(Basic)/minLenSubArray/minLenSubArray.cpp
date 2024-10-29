//
// Created by 18483 on 2024/10/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
// #include <bits/stdc++.h>
// ����209.������С��������
// �����ⷨ������վ
/*
 * �����ⷨ����˼·��
 * ���ѭ���̶�Ϊ��ʼλ�ã��ڲ�ѭ���̶�Ϊ��ֹλ��
 * ͨ���ڲ�ѭ���Ĳ��Ͻ���һֱ����sum�Լ������鳤��
 * ��sum>=targetʱ�������ڲ�ѭ���������ѭ�����ڲ�ѭ���ٴ����ѭ���±�λ�ü���Ѱ��
 * �����ڲ�ѭ����Ҫ��ͷ��ʼ�������ڲ�ѭ�������ѭ�����ɵ����䲢������Ч���䣬����i=1,j=0�����ɵ�����Ϊ[1,0]
 */
// ˫ָ�롪�����������㷨
/*
 * �������ڵı��ʻ���˫ָ�룬֮���Խл������ڱ��ʾ���ͨ����ֹλ�õĲ����ƶ���
 * ��������ʱ���ϸ�����ʼλ��ֱ���������²��������ټ���������ֹλ��
 * ���ڱ�����ԣ������ⷨ�е�ѭ����Ҫ����ʼλ��Ϊ�������Ե���ѭ�����Ӷ�����
 */
class Solution209
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int start = 0;
        int len = INT_MAX; // ����Ϊ���ֵ����ȷ���Ƚ�ʱһ������ȡ����Сֵ
        int sum = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            // ͨ��end�ƶ�������ʼλ�ú���ֹλ������ĺ�sum
            sum += nums[end];
            // ���sum���ڵ���target��˵���Ѿ��ҵ����������������飬���Ը���sum��start��׼����һ��Ѱ��������
            // �˴���Ҫѭ���ж�sum�Ƿ���start����ʱ��������sum>=target��������ʱ�ٸ���end���������
            // ������൱���Ƴ�����
            while (sum >= target)
            {
                // �ȼ��㵱ǰ��������ʱ���±�
                len = std::min(len, end - start + 1);
                // ����start��sum
                sum -= nums[start];
                start++;
            }
        }

        // ���������ָ���������飬�򷵻�0
        if (len == INT_MAX)
        {
            return 0;
        }

        return len;
    }
};

// ����3. ���ظ��ַ�����Ӵ�
// �������ڽⷨ
class Solution3
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> m;
        int len = 0;
        for (int start = 0, end = 0; end < s.size(); end++)
        {
            // ���봰��
            // ���ϣ��������ַ�������ַ����ھ͸ı������
            m[s[end]]++;

            // ���´��ڡ���Ŀ����Ϊ���Ƴ��ظ���Ԫ��
            while (m[s[end]] > 1)
            {
                m.find(s[start++])->second--;
            }
            len = std::max(len, end - start + 1);
        }

        return len;
    }
};

// ����1004.�������1�ĸ�����
// ���������㷨
/* �������Ҫ˼·����ͨ����¼0�ĸ���������ﵽ��ת0��Ŀ�ģ�������һ����������
 * ������Ҫע��ʹ��һ��������ͳ��0�ĸ�������ͨ��һ���������μ���ֱ��С��k
 * ��ΪС��k��ֹһ�����������k=2ʱ��tmpk������0,1���������С��k�������߼��ϻ��п��ܴ��ڸ���
 * ���ǿ��ǵ�����kֻ��Ҫ����һ�Σ����ܴ���k��3,4...������������ǵ�һ�δ���kֻ��һ�����
 * ����ͨ���������ı�ͳ�Ƶ�ǰ0�ĸ���
 */
class Solution1004
{
public:
    int longestOnes(std::vector<int> &nums, int k)
    {
        int len = 0;
        // int tmpk = k;
        int zeroNum = 0;

        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            // �������μ��ٵķ�ʽ���������Ҳ��׿���
            // if(nums[end] == 0)
            // {
            //     tmpk--;
            // }

            // while(tmpk < k)
            // {

            // }

            // ������
            if (nums[right] == 0)
            {
                zeroNum++;
            }

            // ���´���
            while (zeroNum > k)
            {
                // ��Ҫ��ѭ���ڲ����½��
                // len = max(len, right - left + 1);
                if (nums[left++] == 0)
                {
                    zeroNum--;
                }
            }
            // ע�⣬��Ŀ�ᵽ��෭תk��0�����Կ��ܳ��ַ�ת0,1,2,3...k
            // ����֮����Ƿ�ת0�ĸ���С�ڵ���k
            // �ʴ���k�ر���zeroһֱ�����ܴ���k�����
            // ���ϣ�������ѭ���ⲿ���½��
            len = std::max(len, right - left + 1);
        }

        return len;
    }
};

// ����1658.��x����0����С������
/*
 * ����ʹ�õ������򷴵Ĳ���
 * ��Ϊ�����Ҫ���������Ҫ�����Ҳ࣬���������Ĳ������м�����
 * ���Ա���Ϳ���ת��Ϊ��������һ�����䣨��ʱʣ�����������С�ģ����еĺʹ��ڵ��������sumNums-x��
 * ��Ҫע�Ȿ���������������:
 * 1. ��sumNums-x == 0ʱ����ʱ��С�Ĳ������ĸ���������������
 * 2. ��sumNums-x < 0ʱ��˵���޷�ʹx����0����ȻҲ���޷����sumNums-x == target�����
 */
class Solution1658 {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int target = std::accumulate(nums.begin(), nums.end(), 0) - x;
        // ���У���target�պ�Ϊ0��˵����ʱ��С�Ĳ������ĸ���������������
        if(target == 0)
        {
            return nums.size();
        }
        // ���������¼�����
        int sum = 0;
        // ���������¼���䳤��
        int len = -1;
        for(int start = 0, end = 0; end < nums.size(); end++)
        {
            // ���봰��
            sum += nums[end];

            // ���´���
            while(sum > target && start < end)
            {
                sum -= nums[start++];
            }

            // ���ܴ��������е������޷�ʹx����0����ȻҲ���޷����sumNums-x == target�����
            if(sum == target)
            {
                len = std::max(len, end - start + 1);
            }
        }

        // �������������������ܳ��ȼ�Ϊ����
        return len == -1 ? -1 : nums.size() - len;
    }
};

// //����д��
// class Solution1658 {
// public:
//     int minOperations(std::vector<int>& nums, int x) {
//         int sum = 0;
//         for (int a : nums)
//             sum += a;
//         int target = sum - x;
//         // ϸ������
//         if (target < 0)
//             return -1;
//         int ret = -1;
//         for (int left = 0, right = 0, tmp = 0; right < nums.size(); right++) {
//             tmp += nums[right];      // ����?
//             while (tmp > target)     // �ж�
//                 tmp -= nums[left++]; // ����?
//             if (tmp == target)       // ���½��
//                 ret = std::max(ret, right - left + 1);
//         }
//         // �˴�������һ���������x��sumNums��ȫ��ȵ�ʱ�򣬴�ʱ�������Զ����target����ΪtargetΪ0
//         if (ret == -1)
//             return ret;
//         else
//             return nums.size() - ret;
//     }
// };

// ����904.ˮ������
/*
 * ������Ŀ����������������������漰��һ�����ڵĽ���͸���
 * ���ڽ��룺��ǰԪ�ز�����ʱ�����뵽��ǰ����
 * ���ڸ��£���Ԫ�ظ�����������ʱ�����Ǹ��´���ֱ��������������
 * ���Ⲣû���ᵽÿһ��Ԫ��ֻ����һ�Σ�������Ҫȷ��������ֻ������Ԫ�أ�������Ҫ�õ�����ȥ�ص�����
 * ����ѡ��Ľṹ���������������Ӧ�ľ���set��map��Ҳ���Կ���ʹ��unordered_map����unordered_set
 * �����ڸ��´���ʱ�����ֱ��ɾ�������е�Ԫ�ؿ��ܻ���Ϊÿһ��Ԫ�ز�ֹ����һ�ε�����ǰ���´���
 * ����[3,3,3,1,2,1,1,2,3,3,4]�����ֱ��ʹ��һ��������������ڲ���ʱ3,1,2����ʱsizeΪ3��Ҫ���´���
 * ����ѭ�������߼�ʱ����Ϊû�ж�Ԫ�ؽ��м���������setֱ��ɾ��startָ��ĵ�һ��3������size���»ص�2��ѭ����ǰ����
 * ���Կ��Կ���ʹ��map����unordered_map�����Ԫ�ز�����ֱ�Ӳ��룬����ֻ���¼�����
 * ��󣬸��¼������������ڸ��´����и��£���Ϊ����ȷ��һ�������3��ˮ��
 */
class Solution904_1
{
public:
    int totalFruit(std::vector<int> &fruits)
    {
        int start = 0;
        int len = 0;
        std::unordered_map<int, int> m; // ʹ��unordered_map�����ҵ�ʱ�临�Ӷ�ΪO(1)
        for (int end = 0; end < fruits.size(); end++)
        {
            // ȷ��Ԫ���Ƿ���ڣ������ھ����
            m[fruits[end]]++;
            // �����������������������е�ˮ���������2��ʱ��������
            while (m.size() > 2)
            {
                // ֱ��ָ��Ԫ�صļ�����Ϊ0ʱ��ɾ��������һֱ���ټ�����
                if ((--(m.find(fruits[start])->second)) == 0)
                {
                    m.erase(fruits[start]);
                }
                // ���´���
                start++;
            }

            // ���³���
            len = std::max(len, end - start + 1);
        }

        return len;
    }
};

// �����Ż���
/*
 * ��Ϊ��������Ԫ�����Ϊ10�����Կ��Կ���ֱ���������ϣ������ʱ��Ϳռ临�Ӷ�
 */
class Solution904_2 {
public:
    int totalFruit(std::vector<int>& fruits) {
        int start = 0;
        int len = 0;
        // std::unordered_map<int, int> m; // ʹ��unordered_map�����ҵ�ʱ�临�Ӷ�ΪO(1)
        int m[100001] = {0}; // ע���ʼ������ֹ���ֵ���´���
        // ˮ������
        int kinds = 0;
        for (int end = 0; end < fruits.size(); end++) {
            // ȷ��Ԫ���Ƿ���ڣ������ھ����
            if(m[fruits[end]] == 0)
            {
                kinds++;
            }
            m[fruits[end]]++;
            // �����������������������е�ˮ���������2��ʱ��������
            while (kinds > 2) {
                // ֱ��ָ��Ԫ�صļ�����Ϊ0ʱ��ɾ��������һֱ���ټ�����
                if(m[fruits[start]] > 0)
                {
                    m[fruits[start]]--;
                    if (m[fruits[start]] == 0)
                    {
                        kinds--;
                    }
                }

                // ���´���
                start++;
            }

            // ���³���
            len = std::max(len, end - start + 1);
        }

        return len;
    }
};

// ����438.�ҵ��ַ�����������ĸ��λ��
// ���������㷨������������
// ʹ�ÿ�汾
class Solution438_1 {
public:
    std::unordered_map<char, int> ori, sub;
    bool check() {
        for (auto kv : sub) {
            if (ori[kv.first] != kv.second) {
                return false;
            }
        }

        return true;
    }
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> v;
        for(auto ch : p)
        {
            sub[ch - 'a']++;
        }
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // ���봰��
            ori[s[right] - 'a']++;

            // ���´���
            if(right - left + 1 > p.size())
            {
                ori[s[left] - 'a']--;
                left++;
            }

            // ���½��
            if(check())
            {
                v.push_back(left);
            }
        }

        return v;
    }
};

// ֱ�Ӷ�ַ��
// Ԫ������ʱ�����Կ���ʹ��ֱ�Ӷ�ַ��������ʱ��Ϳռ������
class Solution438_2 {
public:
    // Ԫ�ظ�������ʱ�����Կ���ʹ��ֱ�Ӷ�ַ��������ʱ��Ϳռ������
    int ori[26] = {0}, sub[26] = {0};
    bool check() {
        for(size_t i = 0; i < 26; i++)
        {
            if(ori[i] != sub[i])
            {
                return false;
            }
        }

        return true;
    }

    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> v;
        for(auto ch : p)
        {
            sub[ch - 'a']++;
        }
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // ���봰��
            ori[s[right] - 'a']++;

            // ���´���
            if(right - left + 1 > p.size())
            {
                ori[s[left] - 'a']--;
                left++;
            }

            // ���½��
            if(check())
            {
                v.push_back(left);
            }
        }

        return v;
    }
};

// �Ż��Ƚ��߼��汾
class Solution438_3 {
public:
    // Ԫ�ظ�������ʱ�����Կ���ʹ��ֱ�Ӷ�ַ��������ʱ��Ϳռ������
    int ori[26] = {0}, sub[26] = {0};
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> v;
        // �洢��Ч�ַ�����
        int count = 0;
        for(auto ch : p)
        {
            sub[ch - 'a']++;
        }
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // ���봰��
            ori[s[right] - 'a']++;
            // ά����Ч�ַ�����
            // ���ַ����봰�ں������ǰ�Ƚϵ��ַ�������ori�У�����������sub�У���ô˵��������Ч�ַ���count����
            // ����ȴ�����ori��Ҳ������sub�У�˵������Ч�ַ�
            // ע����ҪС�ڵ��ڶ����ǽ����ڣ���Ϊ���ܴ����ظ��ַ�
            if(ori[s[right] - 'a'] <= sub[s[right] - 'a'])
            {
                count++;
            }

            // ���´���
            if(right - left + 1 > p.size())
            {
                // ������ǰά����Ч�ַ�����
                // ά����Ч�ַ����������������
                // 1. ����ȥ���ַ��ڹ�ϣ��ori�еĸ����ȹ�ϣ��sub�еĶ࣬��ʱ˵���Ƴ�ȥ���Ƕ�����ַ�������Ҫ����count
                // 2. ����ȥ���ַ��ڹ�ϣ��ori�еĸ������ϣ��sub�е���ȣ���ʱ˵����Ч�ַ����Ƴ�����Ҫ����count
                // 3. ����ȥ���ַ��ڹ�ϣ��ori�в����ڣ������ڹ�ϣ��sub�д��ڣ���ʱ������ϵ����С��
                //    ��ǰ����������˵��sub�����ظ����ַ�����ʱori��ֻ������һ������ظ��ַ�����Ҫ���Ƴ���
                //    ������������Ч�ַ����Ƴ�����Ҫ����count������s="abacc" p="abbc"
                if(ori[s[left] - 'a'] <= sub[s[left] - 'a'])
                {
                    count--;
                }

                ori[s[left] - 'a']--;
                left++;
            }

            // ���½���Ż���
            // �����Ч�ַ�������p�ĳ�����ͬ����һ������λ��
            if(count == p.size())
            {
                v.push_back(left);
            }
        }

        return v;
    }
};

// ����30.�������е��ʵ��Ӵ�
/*
 * ��������˼·��������ͬ��������Ҫע����ǣ�����ȽϵĲ����ַ��������ַ���
 * ���Կ���ʹ�����巨����Ϊ��Ŀ�ᵽ��words�е�ÿһ���ַ��ĳ�����ͬ������words����ĳ��Ȳ����Ǻܳ�
 * �Ƚ�ʱȡ��s�г�����words��ÿһ���ַ���������ͬ�����ַ����Ƚϣ�ʣ���˼·�ͺ�����һ��
 */
// ���������㷨��������
class Solution30 {
public:
    std::unordered_map<std::string, int> ori, sub;
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> v;
        for(auto& str : words)
        {
            sub[str]++;
        }
        // ÿ�����ʵĳ���
        int sz = words[0].size();
        // ���ƻ�������ִ�еĴ���
        for(int count = 0; count < sz; count++)
        {
            // ��������
            // right+sz�ܹ�����words���ܳ��ȣ�������Ҫע��������
            for(int left = count, right = count, cnt = 0; right + sz <= s.size(); right += sz)
            {
                // ���봰��
                std::string str = s.substr(right, sz);
                ori[str]++;
                // �ж��Ƿ������Ч�ַ�����
                // ���ж�sub���ж�Ӧ���ַ������ٽ��бȽϣ�����sub��û��ָ����Ԫ�ػ���в��룬�Ӷ�����ʱ��Ϳռ�����
                if(sub.count(str) && ori[str] <= sub[str])
                {
                    cnt++;
                }

                // ���´���
                if(right - left + 1 > sz * words.size())
                {
                    std::string tmp = s.substr(left, sz);
                    // ���¼�����
                    if(sub.count(tmp) &&ori[tmp] <= sub[tmp])
                    {
                        cnt--;
                    }

                    ori[tmp]--;
                    left += sz;
                }

                // ���½��
                if(cnt == words.size())
                {
                    v.push_back(left);
                }
            }
            ori.clear();
        }
        return v;
    }
};


// ����76.��С�����Ӵ�
/*
 * ���Ⱪ��˼·��ö�ٳ����а��������Ӵ��������ַ����ַ������Ƚϳ���ȡ����С���Ӵ�
 * ������Կ���ʹ�û������ڵķ���
 * Ϊʲô�����ݱ����ⷨ��ÿһ��ö�����а������Ӵ�����������漰��һЩ�ظ��Ĳ��裬�����Ѿ���ȫ�������ݵ��Ӵ������ö��
 * �������Ҫ����������е�ö�ٴ������٣����Ծ����ҵ���ӽ����Ž��һ���Ӵ����������������У���һ��ָ���ڱ���s�ַ���ʱ
 * ���ָ������ʼλ�õľ���Խ��ԽԶ����ʱ����ʼλ�õ�ָ��͹���һ�����䣬�����պ������ҵ��Ӵ�������ʱ������Ҫ��С����
 * ȷ�����ҵ���Сһ������䣬��������̾��������㲻�����������ڵĹ���
 * ��ô�ã�
 * 1. ��Ŀ�ᵽ��t�ַ����е��ظ��ַ�Ҳ��Ҫ��ȫƥ�䣬������Ҫʹ�ù�ϣ����ͳ�Ƴ��ֵĴ���
 * 2. �������ڣ���t�ַ����Ĺ�ϣ��m����s�ַ����е��ַ������������ӵ���һ����ϣ��c�н��м�����������´���ʱ�Ƚ�
 * 3. ���´��ڣ�����ϣ��sub���ַ��ĸ�����ori�ж�Ӧ���ַ�������ͬ����ori�еĶ�Ӧ�ַ���������sub���ַ��ĸ�����˵��һ�������Ӵ�����t�е������ַ�����ʱ����Ҫ���´���
 *             ����һ������Ҫ���´��ڡ����´��ڵĹ�������Ҫ��¼��ǰ�Ӵ��ĳ����Ѿ���ʼλ�÷�������ȡ�ַ�����ע��һ��Ҫ�Ƚ��µ�len���Ѿ���¼��len��
 *             ���µ�len��Сʱ�ٸ�����ʼλ�ã�����������ʼλ��һֱ�����£�������len�;�len��ͬ�����
 *             �����߼�����ori�е��ַ�������sub�е��ַ�������ƥ�䣬�������ڴ�ori�������Ƴ�������t�е��ַ�
 * 4. ����ֻ��Ҫ���Ƕ̵��ַ����е��ַ����ɣ�����s�ַ�����˵�������ַ��Ƿ���ڲ���Ҫ���ǣ���Ϊ�������һ��ʱ��Ϳռ����ģ�
 *
 */
// ��������
class Solution76_1 {
public:
    std::unordered_map<char, int> ori, sub;
    // �ж��ַ�����
    bool check()
    {
        for(auto& kv : sub)
        {
            // ��ori�ж�Ӧ���ַ���������sub�ж�Ӧ�ַ��ĸ���ʱ˵����ʱ�������㸲������
            if(ori[kv.first] < kv.second)
            {
                return false;
            }
        }

        return true;
    }
    std::string minWindow(std::string s, std::string t) {
        int len = INT_MAX;
        int start = 0;
        // ͳ��t���ַ����ֵĴ���
        for(auto& ch : t)
        {
            sub[ch]++;
        }

        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // ������
            // ori[s[right]]++;
            // ֻ�к���t���ַ���ʱ��Ų���
            if(sub.find(s[right]) != sub.end())
            {
                ori[s[right]]++;
            }
            // ���´���
            while(check())
            {
                // ���½��
                // start = left;
                // len = min(len, right - left + 1);
                if(right - left + 1 < len)
                {
                    len = right - left + 1;
                    start = left;
                }
                // ori[s[left]]--;
                // ֻ����t�е��ַ���ɾ��
                if(sub.find(s[left]) != sub.end())
                {
                    ori[s[left]]--;
                }
                left++;
            }
        }

        return len == INT_MAX ? std::string() : s.substr(start, len);
    }
};

// �Ż��汾
/*
 * ��ǰ�����ƣ������Ż��汾��Ҫ�Ż��ȽϷ�ʽ������һ��������ͳ���ַ����࣬�˴������ַ�����
 * ͳ���ַ�������߼����ַ�������ͬ��ͳ������ʱֻ��Ҫ��֤���ֵ��ַ���t�е��ַ��Ҷ�Ӧ�ַ����ֵĸ�������t�ж�Ӧ�ַ��ĸ�������һ��������£�����Ͳ���
 * ֮����Ҫȷ�������������Ϊt�п��ܴ����ظ��ַ��������ظ��ַ����뱣֤s��Ҳ����ͬ�������ظ��ַ������ֻͳ�Ƶ�һ�γ��֣����ܱ�֤s�е��ظ��ַ�������t����ͬ
 * �������ͳ���ַ�����ֻ��Ҫ������t�е��ַ��͸���
 */
class Solution76_2 {
public:
    std::unordered_map<char, int> ori, sub;
    std::string minWindow(std::string s, std::string t) {
        int len = INT_MAX;
        int start = 0;
        // ͳ��t���ַ����ֵĴ���
        for(auto& ch : t)
        {
            sub[ch]++;
        }

        // ʹ��countͳ���ַ�����
        for(int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            // ������
            // ori[s[right]]++;
            // ֻ�к���t���ַ���ʱ��Ų���
            if(sub.find(s[right]) != sub.end())
            {
                ori[s[right]]++;
                // ͳ���ַ�����
                if(ori[s[right]] == sub[s[right]])
                {
                    count++;
                }
            }
            // ���´���
            while(count == sub.size())
            {
                // ���½��
                // start = left;
                // len = min(len, right - left + 1);
                if(right - left + 1 < len)
                {
                    len = right - left + 1;
                    start = left;
                }
                // ori[s[left]]--;
                // ֻ����t�е��ַ���ɾ��
                if(sub.find(s[left]) != sub.end())
                {
                    // ���¼�����
                    if(ori[s[left]] == sub[s[left]])
                    {
                        count--;
                    }
                    ori[s[left]]--;
                }
                left++;
            }
        }

        return len == INT_MAX ? std::string() : s.substr(start, len);
    }
};

// �����Ż��汾
/*
 * ������Ϊֻ������ĸ�����Կ��Կ���ʹ��һ��������ʽ�Ĺ�ϣ��
 */
class Solution76_3 {
public:
    // unordered_map<char, int> ori, sub;
    int ori[128] = {0}, sub[128] = {0};
    // �ж��ַ�����
    std::string minWindow(std::string s, std::string t) {
        int len = INT_MAX;
        int start = 0;
        // ͳ��t���ַ����ֵĴ���
        // ע����Ϊ�ں�����Ҫ�Ƚ����࣬������ӳ�俪ʼ֮ǰ��Ҫ���ж�ĳ���ַ��ǲ��ǵ�һ�γ���
        // ����ǵ�һ�γ�������������͸��£�����Ͳ�����
        // ���������
        int kinds = 0;
        for(auto& ch : t)
        {
            // ��һ�γ��ֵ��ַ����������������
            if(sub[ch] == 0)
            {
                kinds++;
            }
            sub[ch]++;
        }

        // ʹ��countͳ���ַ�����
        for(int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            // ������
            // ori[s[right]]++;
            // ֻ�к���t���ַ���ʱ��Ų���
            // if(sub.find(s[right]) != sub.end())
            // {
            //     ori[s[right]]++;
            //     // ͳ���ַ�����
            //     if(ori[s[right]] == sub[s[right]])
            //     {
            //         count++;
            //     }
            // }
            ori[s[right]]++;
            // ͳ���ַ�����
            if(ori[s[right]] == sub[s[right]])
            {
                count++;
            }
            // ���´���
            while(count == kinds)
            {
                // ���½��
                // start = left;
                // len = min(len, right - left + 1);
                if(right - left + 1 < len)
                {
                    len = right - left + 1;
                    start = left;
                }
                // ori[s[left]]--;
                // ֻ����t�е��ַ���ɾ��
                // if(sub.find(s[left]) != sub.end())
                // {
                //     // ���¼�����
                //     if(ori[s[left]] == sub[s[left]])
                //     {
                //         count--;
                //     }
                //     ori[s[left]]--;
                // }
                // ���¼�����
                if(ori[s[left]] == sub[s[left]])
                {
                    count--;
                }
                ori[s[left]]--;
                left++;
            }
        }

        return len == INT_MAX ? std::string() : s.substr(start, len);
    }
};