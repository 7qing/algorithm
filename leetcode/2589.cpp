#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        // 按任务的结束时间排序
        sort(tasks.begin(), tasks.end(), [](const vector<int>& task1, const vector<int>& task2) {
            return task1[1] < task2[1]; // 按任务的结束时间排序
        });

        vector<bool> used(2001, false); // 标记时间点是否已被使用
        int totalTime = 0; // 完成所有任务所需的最小时间

        for (const auto& task : tasks) {
            int start = task[0];
            int end = task[1];
            int duration = task[2];

            int count = 0;
            // 统计在任务时间段内已被使用的时间点数量
            for (int t = start; t <= end; ++t) {
                if (used[t]) {
                    count++;
                }
            }

            // 还需要使用的时间点数量
            int needed = duration - count;
            // 从任务结束时间往前，尽量利用未被使用的时间点
            for (int t = end; t >= start && needed > 0; --t) {
                if (!used[t]) {
                    used[t] = true;
                    totalTime++;
                    needed--;
                }
            }
        }

        return totalTime;
    }
};