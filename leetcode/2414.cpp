#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int ans = 0;
        int cur=0;
        char a1 = s[0];
        int n = s.size();
        if(n==1)
            return 1;
        char a2 = s[1];
        for (int i = 1; i < n;i++)
        {
            cur = a2 == a1 + 1 ? cur + 1 : 0;
            ans = max(cur, ans);
            a1 = a2;
            a2 = s[i+1];
        }
        return ans;
    }
};