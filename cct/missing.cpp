#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, su = 0;
    cin >> n;

    ll _su = n * (n + 1);
    _su /= 2;

    n--;

    while (n--)
    {
        ll tmp;
        cin >> tmp;

        su += tmp;
    }

    cout << _su - su << "\n";

    return 0;
}