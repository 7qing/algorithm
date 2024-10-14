#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> Va;
        vector<pair<int,int>> Vb;
        Va.resize(grid.size() * grid[0].size());
        Vb.resize(grid.size() * grid[0].size());
        int min;
        for (int i = 0; i < grid.size();i++)
            for (int j = 0; j < grid[0].size();j++)
                    if(grid[i][j]==1)
                        Va.push_back(pair(i, j));
        while(1){
            vector<vector<int>>& grid2
            if(Va==Vb)
                break;
            Vb = Va;
            for (int i = 0; i <grid.size();i++)
                for (int j = 0; j < grid[0].size();j++)
                {
                    grid2[]
                    if(grid[i][j]==2)
                    {
                        if(i>0&&grid[i - 1][j]==1)
                            grid[i - 1][j] == 2;
                        
                    }
                }
        }
    }
};