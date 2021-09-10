#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll> > edges(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    vector<ll> dis(n + 1, INT_MAX);
    vector<ll> pre(n + 1, -1);

    dis[1] = 1;
    pre[1] = 0;

    queue<ll> Q;
    Q.push(1);

    while (!Q.empty())
    {
        ll u = Q.front();
        Q.pop();

        for (int i = 0; i < edges[u].size(); i++)
        {
            if (dis[edges[u][i]] > dis[u] + 1)
            {
                dis[edges[u][i]] = dis[u] + 1;
                pre[edges[u][i]] = u;
                Q.push(edges[u][i]);
            }
        }
    }

    if (dis[n] == INT_MAX)
    {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    cout << dis[n] << "\n";

    stack<ll> st;
    ll ini = n;
 
    while (ini != 0)
    {
        st.push(ini);
        ini = pre[ini];
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    /*
    ll u = n;

    while (pre[u] > 0)
    {
        cout << u << " ";
        u = pre[u];
    }
    */

    cout << "\n";

    return 0;
}
