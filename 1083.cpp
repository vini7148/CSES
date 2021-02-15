// https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll su = 0;
    for (int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        su += temp;
    }

    cout << ((n * (n + 1)) / 2) - su << "\n";
}