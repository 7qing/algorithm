#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> people;
        people.resize(num_people);
        int n=0;
        while(candies>0)
        {
            candies = candies-n > 0 ? candies-n : 0;
            people[n%num_people] += candies-n > 0 ? n+1 : candies;
            n++;
        }
        return people;
    }
};