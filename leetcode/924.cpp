#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, unordered_set<int>& infected) {
        visited[node] = true;
        infected.insert(node);
        for (int neighbor = 0; neighbor < graph[node].size(); ++neighbor) {
            if (graph[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(graph, neighbor, visited, infected);
    }
    }
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        sort(initial.begin(), initial.end());

        vector<bool> visited(n, false);

        int maxSaved = 0;
        int resultNode = initial[0]; 

        for (int initialNode : initial) {
            if (!visited[initialNode]) {
                unordered_set<int> infected;
                dfs(graph, initialNode, visited, infected);
                
                int initialInfectedCount = 0;
                for (int node : initial) {
                    if (infected.count(node)) {
                        initialInfectedCount++;
                    }
                }
                
                if (initialInfectedCount > maxSaved) {
                    maxSaved = initialInfectedCount;
                    resultNode = initialNode;
                }
            }
        }
        
        return resultNode;
        
    }
};