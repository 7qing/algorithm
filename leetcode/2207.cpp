#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        long long count1 = 0, count2 = 0;
        long long result = 0;

        for (char ch : text)
        {
            if (ch == pattern[1])
            {
                result += count1;
                count2++;
            }
            if (ch == pattern[0])
            {
                count1++;
            }
        }

        result += max(count1, count2 + count1);

        return result;
    }
};