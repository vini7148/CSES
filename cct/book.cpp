#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll su = 0, ma = INT_MIN;
    while (n--)
    {
        ll tmp;
        cin >> tmp;
        ma = max(ma, tmp);
        su += tmp;
    }

    cout << ((ma > (su - ma))? 2 * ma: su) << "\n";
    return 0;
}
