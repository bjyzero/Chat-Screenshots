// 拓扑排序
// 1. 找到图内 入度 = 0 的所有点
// 2. 删除所有 入度为 0 的点以及从这个点指向其他点的边
// 3. 再次寻找 入度为0 的点
// 4. 重复 2 和 3 ，直到图内没有入度为 0 的点 (产生了 "环" )
// 没有入度为 0 的结点之后，如果还有结点有入度，那么表示产生了环
#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

// 注意：vector<int> a[] 为数组-->即每个 a[i] 内为一个 vector，且这种数组必须放在全局变量里面
vector<int> arr[N]; // 存放每个人截图数据
vector<int> adj[N]; // 建图

void solve(const int &Case)
{
    int n, k;
    cin >> n >> k;

    vector<int> deg(N); // 统计各个数据的入度

    // 使用前一定要注意：清空上次数据
    for (int i = 1; i <= k; ++i)
    {
        arr[i].clear();
        adj[i].clear();
        deg[i] = 0;
    }

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            arr[i].resize(n + 2);
            cin >> arr[i][j];
        }
    }

    if (k == 1)
    {
        cout << "YES\n";
        return;
    }

    // 根据题意，第一个人的数据的不进行建图
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 3; j <= n; ++j)
        {
            deg[arr[i][j]]++;
            adj[arr[i][j - 1]].push_back(arr[i][j]);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        //取出队列中一个入度为 0 的结点(cur)，并将 cur 指向的点(nxt)的入度 -1
        for (auto nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }

    //检验是否出现了环
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        if (deg[i] != 0)
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return;
}

int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve(i);
    }
    return 0;
}