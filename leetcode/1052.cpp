#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum=0;
        for (int i = 0; i < n; ++i) 
            if (grumpy[i] == 0) 
                sum += customers[i];
        int max=0;
        for(int i=0;i<=n-minutes;i++)
        {
            int temp=0;
            for(int j=0;j<minutes;j++)
            {
                if(grumpy[i+j])
                    temp+=customers[i+j];
            }
            if(max<temp)
                max = temp;
        }
        return sum+max;
    }
};