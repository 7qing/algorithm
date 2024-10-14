#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
    int countSpecialNumbers(int n)
    {
        std::vector<int> digits;
        int tmp = n;

        // 将数字 n 的每一位拆分并存储到 digits 向量中
        while (tmp != 0)
        {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }

        int numDigits = digits.size(); // n 的位数
        int ans = 0;

        // 1. 计算位数比 n 少的所有特殊数字数量
        for (int i = 1; i < numDigits; ++i)
        {
            int count = 9; // 最高位有 9 种选择 (1-9)
            for (int j = 1; j < i; ++j)
            {
                count *= 10 - j; // 剩下的位数分别有 9, 8, ..., 可选数字
            }
            ans += count;
        }

        // 2. 逐位扫描 n 的数字，计算不超过 n 的特殊数字
        std::vector<bool> used(10, false); // 标记每个数字是否已经使用过
        for (int i = numDigits - 1; i >= 0; --i)
        {
            int curDigit = digits[i];

            // 尝试为当前位置选择一个较小的数字
            for (int j = (i == numDigits - 1 ? 1 : 0); j < curDigit; ++j)
            {
                if (!used[j])
                {
                    int count = 1;
                    for (int k = i - 1; k >= 0; --k)
                    {
                        count *= 10 - (numDigits - k - 1); // 计算剩余位数的排列数
                    }
                    ans += count;
                }
            }

            // 如果当前数位已使用，则退出
            if (used[curDigit])
            {
                break;
            }

            used[curDigit] = true; // 标记当前数位为已使用
        }

        // 3. 判断 n 自身是否是一个特殊整数
        bool isSpecial = true;
        std::fill(used.begin(), used.end(), false); // 重置标记数组
        for (int i = 0; i < numDigits; ++i)
        {
            if (used[digits[i]])
            {
                isSpecial = false;
                break;
            }
            used[digits[i]] = true;
        }

        if (isSpecial)
        {
            ans += 1; // 如果 n 自身是特殊整数，加1
        }

        return ans;
    }
};