#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> max;
        max.resize(grid[0].size());
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++) {
                int temp=grid[j][i];
                int s=0;
                if(temp<0){
                    temp=-grid[j][i];
                    s++;
                }
                do{
                    temp /=10;
                    s++;
                }while(temp!=0);
                if(s>max[i])
                    max[i]=s;
            }  
        }
        return max;
    }
};

// class Solution {
// public:
//     vector<int> findColumnWidth(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<int> ans(n);
//         for(int i = 0;i < n;i++){
//             for(int j = 0;j < m;j++){
//                 ans[i] = max(ans[i], (int) to_string(grid[j][i]).size());
//             }
//         }
//         return ans;
//     }
// };