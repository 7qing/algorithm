#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair

using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> path;
        vector<bool> s(2*n-1,false);
        vector<bool> c(2*n-1, false);
        vector<bool> m(n, false);
        man(res, path, s, c, m, 0, n);
        return res;
    }
    void man(vector<vector<string>> &res, vector<string> &path, vector<bool> s, vector<bool> c, vector<bool> m, int start, int n)
    {
        if(start == n)
        {
            res.push_back(path);
            return;
        }
        string a(n,'.');
        for (int i = 0; i < n;i++)
        {
            if(s[start+i]==true||c[n-1+start-i]==true||m[i]==true)
                continue;
            s[start + i] = true;
            c[n - 1 + start - i] = true;
            m[i] = true;
            a[i] = 'Q';
            path.push_back(a);
            man(res, path, s, c, m, start + 1, n);
            path.pop_back();
            a[i] = '.';
            s[start + i] = false;
            c[n - 1 + start - i] = false;
            m[i] = false;
        }
    }
};