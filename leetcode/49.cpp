#include "iostream"
#include <vector>
#include <cstring>
#include <unordered_map>
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, std::vector<std::string>> HashMap;
        
        for (const std::string& str : strs) {

            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            HashMap[sortedStr].push_back(str);
        }
        
        for (const auto& pair : HashMap) {
            result.push_back(pair.second);
        }
        
        return result;
        
    }
};