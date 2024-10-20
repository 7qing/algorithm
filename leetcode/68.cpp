#include "iostream"
#include <vector>
#include <cstring>
#include "algorithm"
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        int n = words.size();
        int index = 0;
        while (index < n)
        {
            // Step 1: 确定当前行能放下的单词范围
            int totalChars = words[index].length(); // 计算当前行的字符总长度
            int last = index + 1;
            while (last < n)
            {
                if (totalChars + 1 + words[last].length() > maxWidth)
                    break;
                totalChars += 1 + words[last].length(); // 加 1 表示空格
                last++;
            }

            // Step 2: 处理当前行
            string line;
            int numWords = last - index;
            // 如果是最后一行，或者只有一个单词，则左对齐
            if (last == n || numWords == 1)
            {
                for (int i = index; i < last; i++)
                {
                    line += words[i];
                    if (i != last - 1)
                        line += ' ';
                }
                // 将剩余的部分用空格填充
                while (line.length() < maxWidth)
                {
                    line += ' ';
                }
            }
            // 否则均匀分配空格
            else
            {
                int spaces = (maxWidth - totalChars + numWords - 1) / (numWords - 1);      // 平均每个间隔的空格数
                int extraSpaces = (maxWidth - totalChars + numWords - 1) % (numWords - 1); // 多出的空格数

                for (int i = index; i < last; i++)
                {
                    line += words[i];
                    if (i != last - 1)
                    {
                        // 每个间隔的空格数，额外的空格先放到左边
                        int spaceToInsert = spaces + (i - index < extraSpaces ? 1 : 0);
                        line += string(spaceToInsert, ' ');
                    }
                }
            }

            result.push_back(line);
            index = last; // 更新当前处理位置
        }

        return result;
    }
};