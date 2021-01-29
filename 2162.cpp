// https://cses.fi/problemset/task/2162

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    ll st = 1, fd_1 = 0;
    while (a.size() > 0)
    {
        cout << a[st % a.size()] << " ";
        if (a[st % a.size()] != 1 && !fd_1)
        {
            a.erase(a.begin() + (st % a.size()));
            st++;
        }
        else
        {
            fd_1 = 1;
            a.erase(a.begin() + (st % a.size()));
        }
    }
}