#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
    }
    void man(vector<vector<string>> &res, vector<string> &path, string s, int left, int right)
    {
        if (right == s.size())
            res.push_back(path);
        if (left > right)
            return;
        if (s[left] == s[right])
        {
            path.push_back(s.substr(left, right));
            man(res, path, s, left, right + 1);
            path.pop_back();
            man(res, path, s, left + 1, right);
            path.pop_back();
        }
        else
        {
            man(res, path, s, left, right + 1);
            path.pop_back();
            man(res, path, s, left + 1, right);
            path.pop_back();
        }
    }
};