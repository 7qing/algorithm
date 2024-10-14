#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // 初始化基本情况
        for (int i = 1; i <= k; ++i)
        {
            dp[i][0] = 0; // 0层楼时，0次尝试
            dp[i][1] = 1; // 1层楼时，1次尝试
        }
        for (int j = 1; j <= n; ++j)
        {
            dp[1][j] = j; // 1个鸡蛋时，必须线性尝试
        }

        // 填表
        for (int i = 2; i <= k; ++i)
        {
            for (int j = 2; j <= n; ++j)
            {
                int low = 1, high = j;
                while (low + 1 < high)
                {
                    int mid = (low + high) / 2;
                    int breakEgg = dp[i - 1][mid - 1]; // 蛋碎了，去楼下继续搜索
                    int notBreakEgg = dp[i][j - mid];  // 蛋没碎，去楼上继续搜索

                    if (breakEgg > notBreakEgg)
                    {
                        high = mid; // 蛋碎的情况更糟，尝试更低楼层
                    }
                    else
                    {
                        low = mid; // 蛋没碎的情况更糟，尝试更高楼层
                    }
                }
                dp[i][j] = 1 + min(max(dp[i - 1][low - 1], dp[i][j - low]),
                                   max(dp[i - 1][high - 1], dp[i][j - high]));
            }
        }

        return dp[k][n];
    }
};