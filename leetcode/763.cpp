class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> st(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            st[s[i] - 'a'] = i;
        }
        vector<int> result;
        int maxPos = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            maxPos = max(maxPos, st[s[i] - 'a']);

            if (i == maxPos)
            {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};