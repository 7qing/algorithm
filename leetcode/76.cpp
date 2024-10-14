#include "iostream"
#include <vector>
#include <cstring>
#include <unordered_map>
#include <queue>
#include "algorithm"
using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    for(char x:t)
    {
        map2[x]++;
    }
    int start = 0;
    int last = 0;
    for (int end = 0; end < s.size(); end++)
    {
        char currentChar = s[end];
        if (map2.find(currentChar) != map2.end() && map1.find(currentChar) != map1.end() && map1[currentChar] >= start)
        {
            start = map[currentChar] + 1;
        }
        map[currentChar] = end;
    }
    substr()
}
