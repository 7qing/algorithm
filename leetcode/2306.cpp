#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_set<string> groups[26];

        for (const string &s : ideas)
        {
            groups[s[0] - 'a'].insert(s.substr(1));
        }

        long long res = 0;

        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                int mutualSuffixes = 0;
                for (const string &suffix : groups[i])
                {
                    if (groups[j].count(suffix))
                    {
                        mutualSuffixes++;
                    }
                }

                res += 2LL * (groups[i].size() - mutualSuffixes) * (groups[j].size() - mutualSuffixes);
            }
        }

        return res;
    }
};