#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<bool> findAnswer(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<bool> res(n, true);
        unordered_map<int, int> map;
        for (int i : parent)
            map[i]++;
        for (int i = n - 1; i >= 0; i--)
        {
            if (map.find(i) != map.end())
                continue;
            string st;
            int h = 0;
            int j = i;
            while (j != -1)
            {
                st += s[j];
                h++;
                for (int i = 0; i < h; i++)
                    if (st[i] != st[i - 1])
                    {
                        res[j] = false;
                        break;
                    }
                j = parent[j];
            }
        }
        return res;
    }
};