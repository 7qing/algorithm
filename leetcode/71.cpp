#include "iostream"
#include <vector>
#include <cstring>
#include "algorithm"
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> components;
        string res;
        stringstream ss(path);
        string token;

        // Split the path by '/' and process each part
        while (getline(ss, token, '/'))
        {
            if (token == "." || token == "")
            {
                // Ignore '.' or empty parts (caused by consecutive '/')
                continue;
            }
            else if (token == "..")
            {
                // '..' means go back to the parent directory if possible
                if (!components.empty())
                {
                    components.pop_back();
                }
            }
            else
            {
                // Valid directory or file name
                components.push_back(token);
            }
        }

        // Construct the simplified path
        for (const string &part : components)
        {
            res += "/" + part;
        }

        // If res is empty, it means we are at the root directory
        return res.empty() ? "/" : res;
    }
};
