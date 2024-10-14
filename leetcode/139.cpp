#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> s1;
        for (string str : wordDict)
            s1.insert(str);
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && s1.find(s.substr(j, i - j)) != s1.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};