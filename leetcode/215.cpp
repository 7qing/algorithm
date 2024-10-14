#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    void heapify(vector<int> &nums, int n, int len)
    {
        int largest = n; // 先假设父节点是最大值
        int left = 2 * n + 1;
        int right = 2 * n + 2;

        // 如果左子节点存在且大于父节点，则更新最大值索引
        if (left < len && nums[left] > nums[largest])
            largest = left;

        // 如果右子节点存在且大于最大值节点，则更新最大值索引
        if (right < len && nums[right] > nums[largest])
            largest = right;

        // 如果最大值不是当前节点，则进行交换，并递归调整
        if (largest != n)
        {
            swap(nums[n], nums[largest]);
            heapify(nums, largest, len);
        }
    }

    void buildHeap(vector<int> &nums)
    {
        int n = nums.size();
        // 从最后一个非叶子节点开始构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(nums, i, n);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        // 首先构建最大堆
        buildHeap(nums);

        int size = nums.size();
        // 进行 k 次堆调整，将前 k 个最大的元素移到数组末尾
        for (int i = size - 1; i >= size - k; i--)
        {
            swap(nums[0], nums[i]); // 将堆顶（最大值）移到数组末尾
            heapify(nums, 0, i);    // 重新调整堆，排除末尾已经排序的元素
        }

        // 返回第 k 大的元素
        return nums[size - k];
    }
};