// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

char lay[1000][1000];
bool visited[1000][1000] = { false };

void exp(ll n, ll m, ll i, ll j)
{
    visited[i][j] = true;
    // for (ll x = -1; x < 2; x++)
    // {
    //     for (ll y = -1; y < 2 && x != y; y++)
    //     {
    //         if(0 <= (i + x) && (i + x) < n && 0 <= (j + y) && (j + y) < m)
    //         {
    //             if (lay[i + x][j + y] == '.' && !visited[x + i][y + j])
    //                 exp(n, m, i + x, j + y);
    //         }
    //     }
    // }

    ll x = -1, y = 0;
    if(0 <= (i + x) && (i + x) < n && 0 <= (j + y) && (j + y) < m)
    {
        if (lay[i + x][j + y] == '.' && !visited[x + i][y + j])
            exp(n, m, i + x, j + y);
    }

    x = 1;
    y = 0;
    if(0 <= (i + x) && (i + x) < n && 0 <= (j + y) && (j + y) < m)
    {
        if (lay[i + x][j + y] == '.' && !visited[x + i][y + j])
            exp(n, m, i + x, j + y);
    }

    y = 1;
    x = 0;
    if(0 <= (i + x) && (i + x) < n && 0 <= (j + y) && (j + y) < m)
    {
        if (lay[i + x][j + y] == '.' && !visited[x + i][y + j])
            exp(n, m, i + x, j + y);
    }

    y = -1;
    x = 0;
    if(0 <= (i + x) && (i + x) < n && 0 <= (j + y) && (j + y) < m)
    {
        if (lay[i + x][j + y] == '.' && !visited[x + i][y + j])
            exp(n, m, i + x, j + y);
    }

}

int main()
{
    ll n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> lay[i][j];
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!visited[i][j] && lay[i][j] == '.')
            {
                exp(n, m, i, j);
                ans++;
            }
        }
    }

    cout << ans << "\n";
}