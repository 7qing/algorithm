#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int minFlips(string s)
{
    int k = s.size();          // 原始字符串的长度
    int ant = 0, mi = INT_MAX; // ant: 当前窗口内的反转次数，mi: 记录最小的反转次数
    s += s;                    // 将字符串自身拼接一遍，形成长度为 2k 的字符串，模拟循环移位
    int l = s.size();          // 新字符串 s 的长度（即 2k）

    // 使用滑动窗口在长度为 2k 的新字符串上进行遍历
    for (int i = 0, j = 0; i < l; i++)
    {
        // 计算当前窗口 [j, i] 是否满足交替模式
        // 如果 (i-j) 是奇数且 s[i] == s[j]，或者 (i-j) 是偶数且 s[i] != s[j]，则当前字符不符合交替模式，需要反转
        if ((i - j) % 2 && s[i] == s[j] || ((i - j) % 2 == 0 && s[i] != s[j]))
            ant++;

        // 当窗口的长度超过 k 时，开始缩小窗口
        while (i - j + 1 > k)
        {
            // 如果窗口开始处 j 和 j+1 的字符相同，更新 ant（调整为剩下的 k - ant）
            if (s[j] == s[j + 1])
                ant = k - ant;
            j++; // 缩小窗口，移动左边界
        }

        // 当窗口长度至少为 k 时，更新最小反转次数
        if (i >= k - 1)
            mi = min(mi, ant);
    }

    return mi; // 返回最小的反转次数
}
