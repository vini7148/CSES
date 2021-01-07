// https://cses.fi/problemset/task/1712

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll mod = 1e9 + 7;

ll po1(ll a, ll b)
{
  return !b?1:po1(a * a % mod, b / 2) * (b&1?a:1) % mod;
}

ll po2(ll a, ll b)
{
  return !b?1:po2(a * a % (mod - 1), b / 2) * (b&1?a:1) % (mod - 1);
}

int main()
{
  ll n;
  cin >> n;
  while (n--)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << po1(a, po2(b, c)) << "\n";
  }
}
