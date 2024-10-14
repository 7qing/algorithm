#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> map1; // 记录t中每个字符的频率
        unordered_map<char, int> map2; // 记录当前窗口中每个字符的频率

        // 统计t中字符频率
        for (char c : t)
        {
            map1[c]++;
        }

        int start = 0, minStart = 0; // 窗口的开始位置
        int minLen = INT_MAX;        // 最小窗口的长度
        int count = 0;               // 记录匹配到的字符数量

        // 遍历字符串s，扩大窗口
        for (int end = 0; end < s.size(); end++)
        {
            char endChar = s[end];

            // 如果当前字符在t中，更新map2的频率
            if (map1.find(endChar) != map1.end())
            {
                map2[endChar]++;

                if (map2[endChar] <= map1[endChar])
                {
                    count++;
                }
            }

            while (count == t.size())
            {
                if (end - start + 1 < minLen)
                {
                    minLen = end - start + 1;
                    minStart = start;
                }

                char startChar = s[start];
                start++;

                if (map1.find(startChar) != map1.end())
                {
                    map2[startChar]--;
                    if (map2[startChar] < map1[startChar])
                    {
                        count--;
                    }
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};