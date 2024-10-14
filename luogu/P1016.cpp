#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{
private:
    // 使用 pair<int, int> 代替 station 结构体，pair 的 first 表示距离，second 表示油价
    typedef pair<int, int> station;

    // 自定义比较函数：按油价从高到低排列
    struct CompareGasPrice
    {
        bool operator()(const station &a, const station &b)
        {
            return a.second > b.second; // 比较油价，油价低的优先
        }
    };

    vector<station> havestation;                                   // 加油站列表
    priority_queue<station, vector<station>, CompareGasPrice> que; // 优先队列
    int V;                                                         // 油箱最大容量
    int currV;                                                     // 当前油量
    int distance;                                                  // 总距离
    int gasdistance;                                               // 每单位油能跑的距离
    int stsize;                                                    // 加油站数量
    int gasprice;

public:
    solution();  // 构造函数
    int solve(); // 求解逻辑
};

solution::solution()
{
    // 输入：距离、油箱容量、单位油程、基础油价、加油站数量
    cin >> distance >> V >> gasdistance >> gasprice >> stsize;
    stsize++;
    // 初始化加油站
    havestation.resize(stsize);
    havestation[0] = make_pair(0, gasprice); // 初始位置的油价
    for (int i = 1; i < stsize; i++)
    {
        int x, y;
        cin >> x >> y;
        havestation[i] = make_pair(x, y); // 每个加油站的距离和油价
    }
}

// 求解逻辑
int solution::solve()
{
    int currPos = 0;   // 当前所在位置
    currV = 0;         // 初始化油量为 0（出发时油箱是空的）
    int totalCost = 0; // 总花费
    int idx = 0;       // 遍历加油站的索引

    // 模拟行驶过程
    while (currPos < distance)
    {
        // 把所有在当前油量范围内可达的加油站加入优先队列
        while (idx < stsize && havestation[idx].first <= currPos + currV * gasdistance)
        {
            que.push(havestation[idx]);
            idx++;
        }

        // 如果没有可以到达的加油站，且还没到达终点，说明无法到达终点
        if (que.empty())
        {
            return -1;
        }

        // 从队列中取出油价最低的加油站
        station bestStation = que.top();
        que.pop();

        // 计算需要加多少油才能到达该加油站或终点
        int requiredFuel = (bestStation.first - currPos) / gasdistance;

        // 如果当前油量不足以到达下一个加油站，则在当前位置加油至足够
        if (currV < requiredFuel)
        {
            int fuelNeeded = requiredFuel - currV;        // 还需加的油量
            totalCost += fuelNeeded * bestStation.second; // 更新总花费
            currV += fuelNeeded;                          // 加油
        }

        // 更新当前位置，并减去到达该加油站所需的油量
        currPos = bestStation.first;
        currV -= requiredFuel;
    }

    return totalCost;
}

int main()
{
    solution sol;
    int res = 0;
    res = sol.solve();
    if (res == -1)
        cout << "No Solution";
    else
        cout << res;
    system("pause");
    return 0;
}
