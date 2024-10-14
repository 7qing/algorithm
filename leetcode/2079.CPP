#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int tempcap = capacity;
        int sum=0;
        for (int i = 0; i < plants.size(); i++)
        {
            if(tempcap<plants[i])
            {
                sum += 2*i;
                tempcap = capacity;
            }
            tempcap -= plants[i];
            sum +=1;
        }
        return sum;
    }
};