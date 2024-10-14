#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        std::sort(buses.begin(), buses.end());
        std::sort(passengers.begin(), passengers.end());

        int n1 = buses.size();
        int n2 = passengers.size();
        int j = 0; // 乘客的索引
        int ans = 0;

        for (int i = 0; i < n1; i++)
        {
            // 跟踪当前公交车上的乘客数量
            int boarded = 0;

            // 填满当前公交车，确保乘客可以赶上这班车
            while (boarded < capacity && j < n2 && passengers[j] <= buses[i])
            {
                j++;
                boarded++;
            }

            // 如果公交车满了，最后一位乘客不能再晚到
            if (boarded == capacity)
            {
                // 找到最晚的乘车时间，确保该时间不被其他乘客占据
                int last_time = passengers[j - 1] - 1;
                while (std::binary_search(passengers.begin(), passengers.end(), last_time))
                    last_time--;
                ans = last_time;
            }
            // 如果公交车没有满，最晚的时间可能是公交车的发车时间
            else
            {
                int last_time = buses[i];
                while (binary_search(passengers.begin(), passengers.end(), last_time))
                    last_time--;
                ans = ans, last_time;
            }
        }

        return ans;
    }
};