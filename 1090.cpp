// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x; 
    vector<ll> wt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    sort(wt.begin(), wt.end());

    ll co = 1, su = 0, sel = 1, i = 0, j = n - 1;
    su += wt[j];
    while(i < j)
    {
        if (sel == 2)
        {
            co++;
            j--;
            su = wt[j];
            sel = 1;
        }
        else if ((su + wt[i]) > x)
        {
            co++;
            j--;
            su = wt[j];
            sel = 1;
        }
        else
        {
            su += wt[i];
            i++;
            sel++;
        }
        // su += wt[i];
    }

    cout << co << "\n";
}