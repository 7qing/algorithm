#include <iostream>
#include <vector>
using namespace std;

class Trie
{
public:
    struct treeNode
    {
        char ch;
        vector<treeNode *> SonNode;
        bool IsEnd = false;
        treeNode(char ch) : ch(ch) {}
    };

    treeNode *root;
    Trie()
    {
        root = new treeNode(' ');
    }

    class Trie
    {
    public:
        struct treeNode
        {
            char ch;
            vector<treeNode *> SonNode;
            bool IsEnd = false;
            treeNode(char ch) : ch(ch) {}
        };

        treeNode *root;
        Trie()
        {
            root = new treeNode(' ');
        }

        void insert(string word)
        {
            treeNode *tmp = root;
            for (char ch1 : word)
            {
                bool found = false;
                // 查找是否已经有该字符的子节点
                for (treeNode *tmp2 : tmp->SonNode)
                {
                    if (tmp2->ch == ch1)
                    {
                        tmp = tmp2;
                        found = true;
                        break; // 找到该节点，跳出循环
                    }
                }
                // 如果没有找到该字符的子节点，创建新的节点
                if (!found)
                {
                    treeNode *newNode = new treeNode(ch1);
                    tmp->SonNode.push_back(newNode);
                    tmp = newNode;
                }
            }
            // 标记单词的结尾
            tmp->IsEnd = true;
        }

        bool search(string word)
        {
            treeNode *tmp = root;
            for (char ch1 : word)
            {
                bool found = false;
                for (treeNode *tmp2 : tmp->SonNode)
                {
                    if (tmp2->ch == ch1)
                    {
                        tmp = tmp2;
                        found = true;
                        break; // 找到当前字符，继续查找下一个字符
                    }
                }
                // 如果没有找到该字符，返回false
                if (!found)
                    return false;
            }
            // 返回该节点是否为单词的结尾
            return tmp->IsEnd;
        }

        bool startsWith(string prefix)
        {
            treeNode *tmp = root;
            for (char ch1 : prefix)
            {
                bool found = false;
                for (treeNode *tmp2 : tmp->SonNode)
                {
                    if (tmp2->ch == ch1)
                    {
                        tmp = tmp2;
                        found = true;
                        break; // 找到当前字符，继续查找下一个字符
                    }
                }
                // 如果没有找到该字符，返回false
                if (!found)
                    return false;
            }
            // 前缀存在
            return true;
        }
    };
};