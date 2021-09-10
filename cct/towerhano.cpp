#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<pair<ll, ll> > ans;

void tower(ll n, ll a, ll c, ll b)
{
    if (n == 1)
    {
        ans.push_back(make_pair(a, c));

        return ;
    }

    tower(n - 1, a, b, c);

    ans.push_back(make_pair(a, c));

    tower(n - 1, b, c, a);
}

int main()
{
    ll n;
    cin >> n;

    tower(n, 1, 3, 2);

    cout << ans.size() << "\n";

    for (auto x:ans)
    {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}