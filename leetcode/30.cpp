#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (words.empty() || s.empty())
            return res;

        int wordnum = words.size();        // 单词的数量
        int wordsize = words[0].size();    // 每个单词的长度
        int totalLen = wordsize * wordnum; // 总匹配子串的长度
        if (s.size() < totalLen)
            return res; // 如果字符串太短，直接返回

        unordered_map<string, int> wordMap; // 记录 words 中每个单词的频率
        for (const string &word : words)
            wordMap[word]++;

        // 分不同偏移量（从 0 到 wordsize - 1）开始处理
        for (int offset = 0; offset < wordsize; ++offset)
        {
            unordered_map<string, int> windowMap; // 当前窗口内的单词频率
            int left = offset, right = offset, matchedCount = 0;

            // 开始滑动窗口
            while (right + wordsize <= s.size())
            {
                // 从右侧窗口提取一个单词
                string word = s.substr(right, wordsize);
                right += wordsize;

                // 如果单词在 words 中
                if (wordMap.find(word) != wordMap.end())
                {
                    windowMap[word]++;

                    // 如果窗口内单词的出现次数不超过 wordMap 的要求，匹配数量+1
                    if (windowMap[word] <= wordMap[word])
                    {
                        matchedCount++;
                    }

                    // 如果某个单词的出现次数超出了 wordMap 中的要求，左指针移动缩小窗口
                    while (windowMap[word] > wordMap[word])
                    {
                        string leftWord = s.substr(left, wordsize);
                        windowMap[leftWord]--;
                        if (windowMap[leftWord] < wordMap[leftWord])
                        {
                            matchedCount--;
                        }
                        left += wordsize;
                    }

                    // 如果当前窗口匹配了所有单词，记录结果
                    if (matchedCount == wordnum)
                    {
                        res.push_back(left);
                    }
                }
                else
                {
                    // 如果单词不在 words 中，重置窗口
                    windowMap.clear();
                    matchedCount = 0;
                    left = right;
                }
            }
        }

        return res;
    }
};