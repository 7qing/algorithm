#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>     // For std::gcd
#include <algorithm> // For std::max

using namespace std;

// 自定义哈希函数，用于有理数对（分子，分母）的哈希
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    if (n <= 2)
        return n; // 如果点的数量少于或等于2，那么直接返回n

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<pair<int, int>, int, pair_hash> map; // 哈希表：存储斜率 (dy/dx)
        int duplicate = 1;                                 // 记录重复点的数量（即坐标完全相同的点）
        int maxPointsOnLine = 0;                           // 记录经过当前点的直线上的最多点数

        for (int j = i + 1; j < n; j++)
        {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0)
            {
                duplicate++;
            }
            else
            {
                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;
                if (dx < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }
                maxPointsOnLine = max(maxPointsOnLine, ++map[{dy, dx}]);
            }
        }

        // 最终结果是经过当前点的最大点数（包括重复点）
        res = max(res, maxPointsOnLine + duplicate);
    }

    return res;
}

int main()
{
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 1}, {5, 2}, {6, 3}};
    cout << "Max points on a line: " << maxPoints(points) << endl;
    return 0;
}
