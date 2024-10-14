#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair

using namespace std;

// 哈希映射的实现
template<typename K, typename V>
class HashMap {
private:
    vector<list<pair<K, V>>> buckets;  // 存储桶
    size_t capacity;                   // 哈希表容量

    // 哈希函数
    size_t hashFunction(const K& key) const {
        // 这里简单地将 key 转换为 size_t 类型作为哈希值
        return static_cast<size_t>(key);
    }

public:
    // 构造函数
    HashMap(size_t capacity = 10) : capacity(capacity) {
        buckets.resize(capacity);
    }

    // 插入或更新键值对
    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key) % capacity;
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value;  // 更新值
                return;
            }
        }
        buckets[index].emplace_back(key, value);
    }

    // 查找键对应的值
    bool find(const K& key, V& value) const {
        size_t index = hashFunction(key) % capacity;
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    // 删除键值对
    void erase(const K& key) {
        size_t index = hashFunction(key) % capacity;
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

// 示例用法
int main() {
    HashMap<int, string> map;

    // 插入键值对
    map.insert(1, "apple");
    map.insert(2, "banana");

    // 查找键值
    string value;
    if (map.find(1, value)) {
        cout << "Value for key 1: " << value << endl;
    } else {
        cout << "Key 1 not found." << endl;
    }

    // 删除键值对
    map.erase(2);

    return 0;
}
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

    }
};