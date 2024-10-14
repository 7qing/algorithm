#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    if (matrix.empty() || matrix[0].empty())
        return res;

    int m = matrix.size();
    int n = matrix[0].size();
    int mstart = 0, mend = m - 1, nstart = 0, nend = n - 1;

    while (mstart <= mend && nstart <= nend)
    {
        for (int i = nstart; i <= nend; i++)
            res.push_back(matrix[mstart][i]);
        mstart++;

        for (int i = mstart; i <= mend; i++)
            res.push_back(matrix[i][nend]);
        nend--;

        if (mstart <= mend)
        {
            for (int i = nend; i >= nstart; i--)
                res.push_back(matrix[mend][i]);
            mend--;
        }

        if (nstart <= nend)
        {
            for (int i = mend; i >= mstart; i--)
                res.push_back(matrix[i][nstart]);
            nstart++;
        }
    }

    return res;
}
