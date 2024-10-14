#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        unordered_map<int, int> map,map2;
        long long res = 0;
        int n = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n;i++)
            if (nums1[i] % k == 0)
                map[nums1[i] / k] ++;
        for (int i = 0; i < n2; i++)
                map[nums2[i]]++;
        for (auto pair : map2)
        {
            int a = pair.first, cnt = pair.second;
            for (auto pair2 : map)
            {
                int b = pair2.first, cnt2 = pair2.second;
                if (b%a==0)
                res += 1L * cnt2 * cnt;
            }
        }
        return res;
    }
};