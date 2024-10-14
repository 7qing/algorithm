#include <unordered_map>
using namespace std;

struct ListNode
{
    int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:
    unordered_map<int, ListNode *> map; // 用于存储 key 和节点的映射
    int size;                           // 缓存的最大容量
    int currsize;                       // 当前缓存的大小
    ListNode *head;                     // 双向链表的头部，表示最近使用的节点
    ListNode *tail;                     // 双向链表的尾部，表示最近最少使用的节点

public:
    LRUCache(int capacity)
    {
        size = capacity;
        currsize = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            ListNode *node = map[key];

            // 如果该节点不是头节点，将其移到头部
            if (node != head)
            {
                // 先断开该节点
                if (node->prev)
                    node->prev->next = node->next;
                if (node->next)
                    node->next->prev = node->prev;

                // 如果该节点是尾节点，更新尾节点指针
                if (node == tail)
                    tail = node->prev;

                // 将该节点移动到头部
                node->next = head;
                if (head)
                    head->prev = node;
                head = node;
                node->prev = nullptr;
            }

            return node->val;
        }

        return -1; // 如果 key 不存在，返回 -1
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            // 如果 key 已经存在，更新它的值，并将该节点移到链表头部
            ListNode *node = map[key];
            node->val = value;

            // 调用 get 方法将该节点移动到链表头部
            get(key);
        }
        else
        {
            // 如果 key 不存在，插入新节点
            ListNode *newNode = new ListNode(key, value);

            // 如果缓存已满，删除尾节点
            if (currsize == size)
            {
                // 删除 map 中对应的 key
                map.erase(tail->key);

                // 删除尾节点
                ListNode *temp = tail;
                if (tail->prev)
                {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                delete temp;

                currsize--;
            }

            // 将新节点插入到链表头部
            newNode->next = head;
            if (head && size != 1)
                head->prev = newNode;
            head = newNode;

            // 如果链表为空，更新尾节点
            if (currsize == 0)
            {
                tail = newNode;
            }

            // 插入 map
            map[key] = newNode;
            currsize++;
        }
    }
};
