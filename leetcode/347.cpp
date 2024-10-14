#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    void heapify(vector<pair<int, int>> &nums, int n, int len)
    {
        int largest = n; // 先假设父节点是最大值
        int left = 2 * n + 1;
        int right = 2 * n + 2;

        // 如果左子节点存在且大于父节点，则更新最大值索引
        if (left < len && nums[left].second > nums[largest].second)
            largest = left;

        // 如果右子节点存在且大于最大值节点，则更新最大值索引
        if (right < len && nums[right].second > nums[largest].second)
            largest = right;

        // 如果最大值不是当前节点，则进行交换，并递归调整
        if (largest != n)
        {
            swap(nums[n], nums[largest]);
            heapify(nums, largest, len);
        }
    }

    void buildHeap(vector<pair<int, int>> &nums)
    {
        int n = nums.size();
        // 从最后一个非叶子节点开始构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(nums, i, n);
        }
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i : nums)
            map[i]++;
        vector<int> res;
        vector<pair<int, int>> now(map.begin(), map.end());
        buildHeap(now);
        int size = now.size();
        for (int i = size - 1; i >= size - k; i--)
        {
            res.push_back(now[0].first);
            swap(now[0], now[i]);
            heapify(now, 0, i);
        }
        return res;
    }
};