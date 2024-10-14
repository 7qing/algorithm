#include <set>
#include <tuple>
#include <vector>
using namespace std;

class BookMyShow
{
public:
    vector<set<tuple<int, int>>> res; // 每行的座位区间，使用红黑树管理
    vector<int> ret;                  // 每一行剩余的可用座位数

    BookMyShow(int n, int m)
    {
        res = vector<set<tuple<int, int>>>(n);
        for (int i = 0; i < n; ++i)
        {
            // 初始时，每行有一个未预订的区间，从 0 到 m-1
            res[i].insert(make_tuple(0, m - 1));
        }
        ret = vector<int>(n, m); // 初始化每行有 m 个座位
    }

    vector<int> gather(int k, int maxRow)
    {
        vector<int> ans;
        for (int i = 0; i <= maxRow; i++)
        {
            if (ret[i] < k)
                continue; // 提前剪枝：如果当前行剩余座位不足，跳过

            // 查找满足条件的区间
            for (auto it = res[i].begin(); it != res[i].end(); ++it)
            {
                int startPos = get<0>(*it);
                int endPos = get<1>(*it);

                if (endPos - startPos + 1 >= k)
                {                        // 如果这个区间足够大
                    ans = {i, startPos}; // 返回结果：行号和起始位置
                    res[i].erase(it);    // 删除当前区间
                    if (endPos > startPos + k - 1)
                    {
                        // 如果区间剩余座位未用完，插入新区间
                        res[i].insert(make_tuple(startPos + k, endPos));
                    }
                    ret[i] -= k; // 更新剩余可用座位数
                    return ans;
                }
            }
        }
        return {}; // 如果找不到满足条件的座位，返回空数组
    }

    bool scatter(int k, int maxRow)
    {
        int cur = k;                                 // 需要预订的总座位数
        vector<tuple<int, int, int>> bookedSegments; // 记录已预订的段，便于回滚

        for (int i = 0; i <= maxRow; i++)
        {
            if (ret[i] == 0)
                continue; // 如果这一行没有可用座位，则跳过

            auto it = res[i].begin();
            while (it != res[i].end() && cur > 0)
            {
                int startPos = get<0>(*it);
                int endPos = get<1>(*it);
                int availableSeats = endPos - startPos + 1;

                if (availableSeats >= cur)
                {
                    // 当前区间足够容纳剩余的座位
                    bookedSegments.emplace_back(i, startPos, cur); // 记录预订信息
                    res[i].erase(it);                              // 删除当前区间
                    if (availableSeats > cur)
                    {
                        // 如果区间还有剩余未预订的座位，插入新的未预订区间
                        res[i].insert(make_tuple(startPos + cur, endPos));
                    }
                    ret[i] -= cur; // 更新该行的剩余座位数
                    cur = 0;       // 完成预订
                    break;
                }
                else
                {
                    // 当前区间不够预订所有剩余座位
                    bookedSegments.emplace_back(i, startPos, availableSeats); // 记录预订信息
                    res[i].erase(it);                                         // 删除当前区间
                    cur -= availableSeats;                                    // 更新剩余待预订的座位数
                    ret[i] -= availableSeats;                                 // 更新剩余座位
                    it = res[i].begin();                                      // 更新迭代器位置
                }
            }

            if (cur == 0)
                return true; // 全部预订成功
        }

        // 如果未能预订完所有座位，则回滚之前的更改
        if (cur > 0)
        {
            for (const auto &seg : bookedSegments)
            {
                int row = get<0>(seg);
                int start = get<1>(seg);
                int count = get<2>(seg);

                // 回滚每个区间的预订状态
                res[row].insert(make_tuple(start, start + count - 1));
                ret[row] += count; // 恢复这一行的剩余座位数
            }
        }

        return false; // 预订失败
    }
};
