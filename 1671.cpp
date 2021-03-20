// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
 
#define ll long long 
 
using namespace std;

vector<vector<pair<ll, ll> > > edges(100001);
vector<bool> vi(100001, false);
 
int main()
{
    ll n, m;
    cin >> n >> m;
    
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
 
        edges[x].push_back(make_pair(y, w));
        // edges[y].push_back(make_pair(x, w));
    }
 
    // dij...
    vector<ll> dist(100001, LLONG_MAX);
    vector<ll> prev(100001, -1);
 
    dist[1] = 0;
    prev[1] = 0;
 
    priority_queue<pair<ll, ll> , vector<pair<ll, ll> >, greater<pair<ll, ll> > > Q;
    Q.push(make_pair(dist[1], 1));
 
    while(!Q.empty())
    {
        pair<ll, ll> u = Q.top();
        Q.pop();

        if(vi[u.second])
            continue;

        vi[u.second] = true;
 
        for (ll i = 0; i < edges[u.second].size(); i++)
        {
            if (dist[edges[u.second][i].first] > dist[u.second] + edges[u.second][i].second && !vi[edges[u.second][i].first])
            {
                dist[edges[u.second][i].first] = dist[u.second] + edges[u.second][i].second;
                prev[edges[u.second][i].first] = u.second;
                Q.push(make_pair(dist[edges[u.second][i].first], edges[u.second][i].first));
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n";

    return 0;
}