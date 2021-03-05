// https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

vector<vector<ll> > edges(100001);
vector<bool> vi(100001, false);

int main()
{
    ll n, m;
    cin >> n >> m;
    
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // dij...
    vector<ll> dist(100001, INT_MAX);
    vector<ll> prev(100001, -1);

    dist[1] = 1;
    prev[1] = 0;

    queue<ll> Q;
    Q.push(1);

    while(!Q.empty())
    {
        ll u = Q.front();
        Q.pop();

        for (ll i = 0; i < edges[u].size(); i++)
        {
            if (dist[edges[u][i]] > dist[u] + 1)
            {
                dist[edges[u][i]] = dist[u] + 1;
                prev[edges[u][i]] = u;
                Q.push(edges[u][i]);
            }
        }
    }

    if (dist[n] == INT_MAX)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dist[n] << "\n";
    
    stack<ll> st;
    ll ini = n;

    while (ini != 0)
    {
        st.push(ini);
        ini = prev[ini];
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\n";
}
