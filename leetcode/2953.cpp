#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int countCompleteSubstrings(string word, int k)
{
    int ans = 0; // 用于存储符合条件的完全子字符串数量

    // 1. 遍历可能的字符种类数量 i，最大为26（a-z 之间的26个字母）
    for (int i = 1; i <= 26; ++i)
    {
        int l = 0;           // 滑动窗口的左边界
        int m = i * k;       // 当前窗口长度需要的字符总数，每种字符必须出现 k 次
        vector<int> cnt(26); // 用于统计滑动窗口内每个字符的出现频率
        int diff = 0;        // 记录窗口内不同字符的数量

        // 2. 滑动窗口的右边界从0开始遍历整个字符串
        for (int r = 0; r < word.size(); ++r)
        {
            // 当前字符 word[r] 的频率加1，如果它是第一次出现，增加 diff
            if (++cnt[word[r] - 'a'] == 1)
                ++diff;

            // 3. 如果当前字符的频率超过 k 或者相邻字符的 ASCII 差值大于2，则收缩左边界
            while (r > l && (cnt[word[r] - 'a'] > k || abs(word[r] - word[r - 1]) > 2))
            {
                // 逐步减少左边界字符的频率，如果频率降到0，表示该字符已经不在窗口内，减少 diff
                if (--cnt[word[l] - 'a'] == 0)
                    --diff;
                ++l; // 左边界右移
            }

            // 4. 如果当前窗口的大小达到了目标大小 m
            if (r - l + 1 == m)
            {
                // 5. 如果窗口内的不同字符数恰好等于 i，表示找到一个完全子字符串，计数器加1
                if (diff == i)
                {
                    ++ans;
                }

                // 6. 移出左边界字符，调整频率和不同字符计数
                if (--cnt[word[l] - 'a'] == 0)
                    --diff;
                ++l; // 左边界继续右移
            }
        }
    }
    return ans; // 返回符合条件的完全子字符串数量
}
