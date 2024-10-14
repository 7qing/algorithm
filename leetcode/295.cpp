#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.empty() || num <= maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);

        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if ((maxheap.size() + minheap.size()) % 2)
            return maxheap.top();
        else
            return (((double)maxheap.top()) + ((double)minheap.top())) / 2;
    }
};