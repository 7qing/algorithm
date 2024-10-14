#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int evalRPN(vector<string> &tokens)
{
    stack<int> num;
    int res;
    int n = tokens.size();
    for (int i = 0; i < n; i++)
    {
        if (tokens[i][0] == '+')
        {
            int tmp1 = num.top();
            num.pop();
            int tmp2 = num.top();
            num.pop();
            num.push(tmp1 + tmp2);
        }
        else if (tokens[i][0] == '-')
        {
            int tmp1 = num.top();
            num.pop();
            int tmp2 = num.top();
            num.pop();
            num.push(tmp1 - tmp2);
        }
        else if (tokens[i][0] == '*')
        {
            int tmp1 = num.top();
            num.pop();
            int tmp2 = num.top();
            num.pop();
            num.push(tmp1 * tmp2);
        }
        else if (tokens[i][0] == '/')
        {
            int tmp1 = num.top();
            num.pop();
            int tmp2 = num.top();
            num.pop();
            num.push(tmp1 / tmp2);
        }
        else
        {
            num.push(stoi(tokens[i]));
        }
    }
    return num.top();
}