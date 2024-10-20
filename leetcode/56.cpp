#include "iostream"
#include <vector>
#include <cstring>
#include "algorithm"
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        if (n == 0)
            return res; // 边界情况，空区间处理

        // 先按照区间的起始位置进行排序
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        // 初始化第一个区间的起点和终点
        int minstart = intervals[0][0];
        int maxend = intervals[0][1];

        // 遍历所有区间，合并重叠的区间
        for (int i = 1; i < n; i++)
        {
            // 如果当前区间的起始位置小于等于前一个区间的结束位置，则合并
            if (intervals[i][0] <= maxend)
            {
                maxend = max(maxend, intervals[i][1]); // 更新最大结束位置
            }
            else
            {
                // 不重叠的情况下，保存当前合并的区间
                res.push_back({minstart, maxend});
                minstart = intervals[i][0];
                maxend = intervals[i][1];
            }
        }

        // 最后一个合并区间加入结果
        res.push_back({minstart, maxend});

        return res;
    }
};