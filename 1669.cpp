// https://cses.fi/problemset/task/1669/
 
#include <bits/stdc++.h>
 
#define ll long long 
 
using namespace std;

vector<vector<ll> > edges(100001);
vector<bool> vi(100001, false);
 
vector<ll> ans;
 
bool iscyc(ll u, ll par)
{
    vi[u] = true;
 
    ans.push_back(u);
 
    for (ll i = 0; i < edges[u].size(); i++)
    {
        if (!vi[edges[u][i]])
        {
            if (iscyc(edges[u][i], u))
                return true;
        }
 
        else if (edges[u][i] != par)
        {
            ans.push_back(edges[u][i]);
 
            return true;
        }
    }
 
    ans.pop_back();
 
    return false;
}
 
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
 
    bool res = false;
 
    for (ll i = 1; i <= n; i++)
    {
        if (!vi[i])
        {
            if (iscyc(i, -1))
            {
                res = res || true;
                break;
            }
        }
    }
 
    if (!res)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    ll st = 0;
 
    while (st < ans.size() && ans[st] != ans[ans.size() - 1])
        st++;
 
    cout << ans.size() - st << "\n";
    for (ll i = st; i < ans.size(); i++)
        cout << ans[i] << " ";
 
    cout << "\n";
}