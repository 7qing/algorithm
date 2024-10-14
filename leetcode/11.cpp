#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1,weight = 0, maxWeight = 0;
        while(left != right){
            if(height[left] > height[right]){
                weight = (right - left) * height[right];
                maxWeight = max(weight,maxWeight);
                right--;
            }else{
                weight = (right - left) * height[left];
                maxWeight = max(weight,maxWeight);
                left++;
            }
        }
    }
};