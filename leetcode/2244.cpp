#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int times=0;
        int j=1;
        sort(tasks.begin(),tasks.end());
        for (int i = 1; i < tasks.size(); i++)
        {
            if(tasks[i]==tasks[i-1])
                j++;
            else{
                if(j==1)
                    return -1;
                else 
                    times += j/3 +(j%3+1)/2;
                j=1;
            }
        }
        if(j==1)
            return -1;
        else 
            times += j/3 +(j%3+1)/2;
        return times;
    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> taskCount;
        for (int task : tasks) {
            taskCount[task]++;
        }

        int times = 0;

        for (auto& [task, count] : taskCount) {
            if (count == 1) {
                return -1;
            }
            times += count / 3;
            if (count % 3 != 0) {
                times++;
            }
        }
        return times;
    }
};
