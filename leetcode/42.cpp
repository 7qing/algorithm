#include "iostream"
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        int max=0;
        for(int i=0;i<n;i++)
            if(height[max]<height[i])
                max=i;
        int max1=0,max2=0;
        for(int i=0;i<=max;i++)
        {
            if(max1<=height[i])
                max1=height[i];
            else
                ans += max1-height[i];
        }
        for(int j=n-1;j>=max;j--)
            if(max2<height[j])
                max2=height[j];
            else
                ans += max2-height[j];
        return ans;
    }
};