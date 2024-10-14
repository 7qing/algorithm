class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        int ans = 0;
        for (int left = 0, right = n - 1; left < right;)
        {
            int cnt = values[left] + values[right] + left - right;
            ans = max(ans, cnt);
            if (values[left + 1] + values[right] + left + 1 - right < values[left] + values[right - 1] + left + 1 - right)
                right--;
            else
                left++;
        }
        return ans;
    }
};