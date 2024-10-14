#include "iostream"
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map; 
        int ans = 0;
        int start = 0; 

        for (int end = 0; end < s.size(); end++) {
            char currentChar = s[end];
            if (map.find(currentChar) != map.end() && map[currentChar] >= start) {
                start = map[currentChar] + 1;
            }
            map[currentChar] = end;
            ans = max(ans, end - start + 1);
        }
        return ans;
    }

};