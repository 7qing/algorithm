#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int ans = 0, res = 0;
        int n = distance.size();
        int i = start, j = destination;
        while (i != destination && j != start)
        {
            ans += distance[i];
            res += distance[j];
            i = (i + 1) % n;
            j = (j + 1) % n;
        }
        if (i == destination)
        {
            if (ans <= res)
                return ans;
            while (j != start)
            {
                res += distance[j];
                j = (j + 1) % n;
            }
            return ans <= res ? ans : res;
        }
        else
        {
            if (res <= ans)
                return res;
            while (i != destination)
            {
                ans += distance[i];
                i = (i + 1) % n;
            }
            return ans <= res ? ans : res;
        }
    }
};