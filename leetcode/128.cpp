#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int maxLength = 0;

        for (int num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int current = num;
                int length = 1;

                while (numSet.find(current + 1) != numSet.end())
                {
                    current++;
                    length++;
                }

                maxLength = std::max(maxLength, length);
            }
        }

        return maxLength;
    }
};

// class Solution {
// public:
//     unordered_map<int, int> longestEndsWithKey;
//     unordered_map<int, int> longestBeginsWithKey;
//     unordered_set<int> hasOccur;

//     void printMap(const unordered_map<int, int>& m) {
//         printf("[\n");
//         for(pair<int,int> p: longestEndsWithKey) {
//             printf("%d %d\n", p.first, p.second);
//         }
//         printf("]\n");
//     }

//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int, int>::iterator beginIter, endIter;
//         for(int n: nums) {
//             if(hasOccur.find(n) != hasOccur.end()) {
//                 continue;
//             }
//             hasOccur.insert(n);

//             endIter = longestEndsWithKey.find(n - 1);
//             beginIter = longestBeginsWithKey.find(n + 1);

//             int newBegin = (endIter == longestEndsWithKey.end() ? n: n - endIter->second);
//             int newEnd = (beginIter == longestBeginsWithKey.end() ? n: n + beginIter->second);

//             //printMap(longestEndsWithKey);

//             if(endIter != longestEndsWithKey.end()) {
//                 longestEndsWithKey.erase(endIter);
//             }
//             if(beginIter != longestBeginsWithKey.end()) {
//                 longestBeginsWithKey.erase(beginIter);
//             }
//             //printMap(longestEndsWithKey);
//             int length = newEnd - newBegin + 1;
//             //printf("%d %d %d %d\n", n, newBegin, newEnd, length);

//             longestEndsWithKey[newEnd] = length;
//             longestBeginsWithKey[newBegin] = length;
//             //printMap(longestEndsWithKey);
//         }
//         int maxLen = INT_MIN;
//         for(pair<int,int> p: longestEndsWithKey) {
//             maxLen = max(maxLen, p.second);
//         }
//         return maxLen;
//     }
// };
