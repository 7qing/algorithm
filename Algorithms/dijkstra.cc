
#include <stdio.h>
const int N = 100;
const int INF = 100000; // INF假定为无穷大
int p[N][N], d[N];      // p表示各节点间的距离，不存在路径即为无穷大；d表示从出发节点到各节点的最短路径长度

void dijkstra(int sec, int n) // sec为出发节点，n为图中的节点数
{
    int i, j, min, min_num;
    int vis[N] = {
        0,
    }; // 用于标记是否已作为过中途节点，0表示没有，1表示有
    for (i = 0; i < n; i++) // 初始化
    {
        d[i] = p[sec][i];
    }
    vis[sec] = 1;
    d[sec] = 0; // 出发节点到自己的距离永远为0
    for (i = 1; i < n; i++)
    {
        min = INF;
        for (j = 0; j < n; j++) // 每次循环取出d数组中的未被作为过中途节点且数值最小的
        {
            if (!vis[j] && d[j] < min)
            {
                min = d[j];  // 更新最小值
                min_num = j; // 更新最小值所对应的节点，即记录下标
            }
        }
        vis[min_num] = 1;       // 标记该节点，表示其已被作为中途节点
        for (j = 0; j < n; j++) // 循环，经过min_num节点到达是否有更小距离，如有更小距离则更新d数组
        {
            if (d[j] > min + p[min_num][j])
            {
                d[j] = min + p[min_num][j];
            }
        }
    }
}
int main()
{
    int i, j, n = 5;        // n表示图中的节点个数
    for (i = 0; i < n; i++) // 程序用二维数组p存储各节点间的距离，这里则进行初始化
    {
        for (j = 0; j < n; j++)
        {
            p[i][j] = (i == j ? 0 : INF); // 初始化：i到j路径为无穷大或者i到i本身为0
        }
    }
    p[0][1] = 10;
    p[0][3] = 30;
    p[0][4] = 100;
    p[1][2] = 50;
    p[2][4] = 50;
    p[3][2] = 20;
    p[3][4] = 60;           // p[i][j]表示节点i到节点j的距离
    dijkstra(0, n);         // 求从节点0出发到各节点的最短距离
    for (i = 0; i < n; i++) // 打印从节点0出发到各节点的最短距离
    {
        printf(i == n - 1 ? "%d\n" : "%d ", d[i]);
    }
    return 0;
}