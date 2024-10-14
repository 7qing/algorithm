#include "iostream"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> diagonalSort(const std::vector<std::vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    std::vector<std::vector<int>> sortedMat(m, std::vector<int>(n));

    for (int k = 0; k < m; ++k) {
        std::vector<int> diagonal;
        int i = k, j = 0;
        while (i < m && j < n) {
            diagonal.push_back(mat[i++][j++]);
        }
        std::sort(diagonal.begin(), diagonal.end());
        i = k, j = 0;
        int idx = 0;
        while (i < m && j < n) {
            sortedMat[i++][j++] = diagonal[idx++];
        }
    }

    for (int k = 1; k < n; ++k) {
        std::vector<int> diagonal;
        int i = 0, j = k;
        while (i < m && j < n) {
            diagonal.push_back(mat[i++][j++]);
        }
        std::sort(diagonal.begin(), diagonal.end());
        i = 0, j = k;
        int idx = 0;
        while (i < m && j < n) {
            sortedMat[i++][j++] = diagonal[idx++];
        }
    }

    return sortedMat;
}
};