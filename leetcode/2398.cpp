#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = runningCosts.size();
        int ans = 0;
        long long cost;
        int left = 0;
        int right = n-1;
        deque<int> q;
        for (int i = 0, j = 0; i < n;i++) {
            cost += runningCosts[i];
            while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            while (j <= i && (i - j + 1) * cost + chargeTimes[q.front()] > budget)
            {
                if (!q.empty() && q.front() == j)
                {
                    q.pop_front();
                }
                cost -= runningCosts[j];
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};