#include <vector>
#include <string>
#include <unordered_set>
#include <climits>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isWord = false;
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    // 插入单词
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    vector<int> search(const string &target, int start, int end)
    {
        TrieNode *node = root;
        vector<int> validEnds; // 存储所有可能前缀的结束位置
        for (int i = start; i < target.size(); i++)
        {
            if (node->children.find(target[i]) == node->children.end())
            {
                break; // 如果字符无法匹配，退出查找
            }
            node = node->children[target[i]];
            if (node->isWord)
            {
                validEnds.push_back(i + 1); // 前缀结束位置是 i + 1
            }
        }
        return validEnds;
    }
};

int minValidStrings(vector<string> &words, string target)
{
    Trie trie;
    for (const string &word : words)
        trie.insert(word); // 将所有单词插入Trie树

    vector<int> dp(target.size() + 1, INT_MAX);
    dp[0] = 0; // 空字符串，无需连接

    // 遍历 target 的每个字符
    for (int i = 1; i <= target.size(); i++)
    {
        // 尝试从 i 向前寻找子串
        for (int j = 0; j < i; j++)
        {
            // 直接用索引匹配，而不是 substr
            if (trie.search(target, j, i - j))
            {
                if (dp[j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[j] + 1); // 更新 dp[i]
                }
            }
        }
    }

    return dp[target.size()] == INT_MAX ? -1 : dp[target.size()];
}
