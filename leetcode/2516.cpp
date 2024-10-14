#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int takeCharacters(string s, int k)
{
    int n = s.size();
    if (k == 0)
        return 0; // 如果 k 为 0，直接返回 0

    // 统计字符串中每种字符的数量
    vector<int> count(3, 0);
    for (char c : s)
    {
        count[c - 'a']++;
    }

    // 如果某种字符数量小于 k，则无法满足要求，直接返回 -1
    if (count[0] < k || count[1] < k || count[2] < k)
    {
        return -1;
    }

    // 找到一个最长的子串，满足这个子串内的每个字符最多有 n-k 个
    int maxLength = 0;              // 窗口的最大长度
    vector<int> currentCount(3, 0); // 窗口内 'a', 'b', 'c' 的计数
    int left = 0;

    for (int right = 0; right < n; ++right)
    {
        currentCount[s[right] - 'a']++;

        // 保持窗口内的每个字符的数量最多为 n-k
        while (currentCount[0] > count[0] - k ||
               currentCount[1] > count[1] - k ||
               currentCount[2] > count[2] - k)
        {
            currentCount[s[left] - 'a']--;
            left++;
        }

        // 更新最大子串长度
        maxLength = max(maxLength, right - left + 1);
    }

    // 最少需要移除的字符数是总长度减去最大子串长度
    return n - maxLength;
}
