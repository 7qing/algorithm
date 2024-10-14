#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        int ans = 0;;
        vector<bool> map(10000,false);
        for (vector<int> m:nums)
            for (int i = m[0]; i <= m[1];i++)
            {
                if(!map[i])
                {
                    ans++;
                    map[i] = true;
                }
            }
                
        return ans;
    }
};