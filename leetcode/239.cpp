#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;   // 双端队列，存储的是数组元素的下标
    vector<int> res; // 用来存储每个窗口的最大值

    for (int i = 0; i < nums.size(); i++)
    {
        // 移除不在窗口范围内的元素（窗口的左边界是 i - k + 1）
        if (!dq.empty() && dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        // 移除队列中所有比当前元素小的元素
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // 将当前元素的下标加入队列
        dq.push_back(i);

        // 当窗口达到大小 k 时，开始记录窗口最大值（队列头部的元素是最大值的下标）
        if (i >= k - 1)
        {
            res.push_back(nums[dq.front()]);
        }
    }

    return res;
}