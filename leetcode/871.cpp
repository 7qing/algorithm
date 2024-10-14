
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        priority_queue<int> pq;

        int currentFuel = startFuel;
        int refuelCount = 0;
        int prevPosition = 0;
        int i = 0;

        while (currentFuel < target)
        {

            while (i < stations.size() && stations[i][0] <= currentFuel)
            {
                pq.push(stations[i][1]); // 把这个加油站的燃料量存入最大堆
                i++;
            }

            if (pq.empty())
                return -1;

            currentFuel += pq.top();
            pq.pop();
            refuelCount++;
        }

        return refuelCount;
    }
};