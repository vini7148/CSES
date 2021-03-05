// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

vector<vector<ll> > edges(100001);
vector<bool> vi(100001, false);
vector<ll> isln(100001, 0);
vector<vector<ll> > li;
vector<ll> tmp;

void exp(ll x)
{
    for (int j = 0; j < edges[x].size(); j++)
    {                                                                           
        if(!vi[edges[x][j]])
        {
            vi[edges[x][j]] = true;
            tmp.push_back(edges[x][j]);
            exp(edges[x][j]);
        }
    }
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

    ll pre = 1;



    for (ll i = 1; i <= n; i++)
    {
        if (!vi[i])
        {
            tmp.clear();

            vi[i] = true;
            isln[i] = pre;

            tmp.push_back(i);
            
            exp(i);

            li.push_back(tmp);

            pre++;
        }

    }

    cout << pre - 2 << "\n";

    for (int i = 0; i < pre - 2; i++)
    {
        cout << li[i][0] << " " << li[i + 1][0] << "\n";
    }

}
