#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
private:
    vector<int> tree; // 线段树数组
    int n;            // 数组长度

    // 递归构建线段树，节点p表示区间[l, r]
    void buildTree(vector<int> &nums, int p, int l, int r)
    {
        if (l == r)
        {
            // 叶子节点，存储数组元素
            tree[p] = nums[l];
        }
        else
        {
            // 递归构建左子树和右子树
            int mid = l + (r - l) / 2;
            buildTree(nums, 2 * p + 1, l, mid);
            buildTree(nums, 2 * p + 2, mid + 1, r);
            // 当前节点存储子节点的和
            tree[p] = tree[2 * p + 1] + tree[2 * p + 2];
        }
    }

    // 递归查询区间和
    int queryRange(int p, int l, int r, int i, int j)
    {
        if (l >= i && r <= j)
        {
            // 完全包含在查询区间内
            return tree[p];
        }
        if (r < i || l > j)
        {
            // 完全不在查询区间内
            return 0;
        }
        // 部分重叠，查询左右子树
        int mid = l + (r - l) / 2;
        return queryRange(2 * p + 1, l, mid, i, j) + queryRange(2 * p + 2, mid + 1, r, i, j);
    }

    // 递归更新数组中的某个元素
    void updateTree(int p, int l, int r, int index, int val)
    {
        if (l == r)
        {
            // 找到叶子节点，更新值
            tree[p] = val;
        }
        else
        {
            int mid = l + (r - l) / 2;
            if (index <= mid)
            {
                updateTree(2 * p + 1, l, mid, index, val);
            }
            else
            {
                updateTree(2 * p + 2, mid + 1, r, index, val);
            }
            // 更新父节点的值
            tree[p] = tree[2 * p + 1] + tree[2 * p + 2];
        }
    }

public:
    // 构造函数
    SegmentTree(vector<int> &nums)
    {
        n = nums.size();
        tree.resize(4 * n); // 线段树的大小是4n
        buildTree(nums, 0, 0, n - 1);
    }

    // 查询区间[i, j]的和
    int query(int i, int j)
    {
        return queryRange(0, 0, n - 1, i, j);
    }

    // 更新数组中的某个元素
    void update(int index, int val)
    {
        updateTree(0, 0, n - 1, index, val);
    }
};