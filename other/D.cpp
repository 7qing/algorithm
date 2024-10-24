#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

int find_max_citizens(int n, int k, const vector<vector<int>> &data)
{
   
    vector<int> citizens(n,0);

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            citizens[i + j + 1] = data[i][j];
        }
    }

    int max_citizens = 0;
    int window_sum = 0;

    // 初始化窗口的和
    for (int i = 0; i < k; ++i)
    {
        window_sum += citizens[i];
    }
    max_citizens = window_sum;

    // 滑动窗口
    for (int i = k; i < citizens.size(); ++i)
    {
        window_sum += citizens[i] - citizens[i - k];
        max_citizens = max(max_citizens, window_sum);
    }

    return max_citizens;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> data(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            int num;
            cin >> num;
            data[i].push_back(num);
        }
    }

    // 输出结果
    cout << find_max_citizens(n, k, data) << endl;
    return 0;
}
