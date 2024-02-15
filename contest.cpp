// ��������
// 1. �ҵ�ͼ�� ��� = 0 �����е�
// 2. ɾ������ ���Ϊ 0 �ĵ��Լ��������ָ��������ı�
// 3. �ٴ�Ѱ�� ���Ϊ0 �ĵ�
// 4. �ظ� 2 �� 3 ��ֱ��ͼ��û�����Ϊ 0 �ĵ� (������ "��" )
// û�����Ϊ 0 �Ľ��֮��������н������ȣ���ô��ʾ�����˻�
#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

// ע�⣺vector<int> a[] Ϊ����-->��ÿ�� a[i] ��Ϊһ�� vector������������������ȫ�ֱ�������
vector<int> arr[N]; // ���ÿ���˽�ͼ����
vector<int> adj[N]; // ��ͼ

void solve(const int &Case)
{
    int n, k;
    cin >> n >> k;

    vector<int> deg(N); // ͳ�Ƹ������ݵ����

    // ʹ��ǰһ��Ҫע�⣺����ϴ�����
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

    // �������⣬��һ���˵����ݵĲ����н�ͼ
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

        //ȡ��������һ�����Ϊ 0 �Ľ��(cur)������ cur ָ��ĵ�(nxt)����� -1
        for (auto nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }

    //�����Ƿ�����˻�
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