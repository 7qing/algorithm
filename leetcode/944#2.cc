#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int res = 0;
    int freshCount = 0;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;

    // 统计新鲜橘子的数量并将腐烂的橘子入队
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                freshCount++;
        }
    }

    // 如果没有新鲜橘子，直接返回0
    if (freshCount == 0)
        return 0;

    // 定义四个方向
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // 开始BFS
    while (!q.empty())
    {
        int size = q.size();
        bool rottenOccurred = false;

        for (int i = 0; i < size; i++)
        {
            auto [x, y] = q.front();
            q.pop();

            // 遍历四个方向
            for (auto [dx, dy] : directions)
            {
                int newX = x + dx;
                int newY = y + dy;

                // 检查是否为新鲜橘子并且在界限内
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    freshCount--;
                    q.push({newX, newY});
                    rottenOccurred = true;
                }
            }
        }

        // 如果本轮腐烂了橘子，增加时间
        if (rottenOccurred)
            res++;
    }

    // 如果还有新鲜橘子，返回-1
    return freshCount == 0 ? res : -1;
}
