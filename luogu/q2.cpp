#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string.h>

using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        long long res;
        int n = b.size();
        vector<long long> dp1(n, LONG_LONG_MIN);
        vector<long long> dp2(n, LONG_LONG_MIN);
        vector<long long> dp3(n, LONG_LONG_MIN);
        vector<long long> dp4(n, LONG_LONG_MIN);

        dp1[0] = (long long)a[0] * b[0];
        for (int i = 1; i < n; i++)
            dp1[i] = max(dp1[i - 1], (long long)(a[0]) * b[i]);

        for (int i = 1; i < n; i++)
            dp2[i] = max(dp2[i - 1], dp1[i - 1] + (long long)(a[1]) * b[i]);

        for (int i = 2; i < n; i++)
            dp3[i] = max(dp3[i - 1], dp2[i - 1] + (long long)(a[2]) * b[i]);

        for (int i = 3; i < n; i++)
            dp4[i] = max(dp4[i - 1], dp3[i - 1] + (long long)(a[3]) * b[i]);

        return dp4[n - 1];
    }
};