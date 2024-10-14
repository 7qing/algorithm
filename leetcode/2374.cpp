#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int edgeScore(std::vector<int> &edges)
    {
        int bestNode = 0;
        int n = edges.size();       // 存储具有最大边缘分数的节点
        long long maxScore = n - 1; // 当前最大的边缘分数
        vector<long> edgeScores(n, 0);
        for (int i = 0; i < n; ++i)
        {
            long to = edges[i];
            edgeScores[edges[i]] += i;
            // 临时保存当前节点的边缘分数
            if (edgeScores[to] > edgeScores[bestNode] || edgeScores[to] == edgeScores[bestNode] && to < bestNode)
            {
                res = to;
            }
        }
        return bestNode;
    }
};