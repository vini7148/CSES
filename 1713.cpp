// https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
  ll n = 1e6 + 10;
  vector<ll> cd(n);

  for (int i = 1; i < n; i++)
    for (int j = i; j < n; j+= i)
      cd[j]++;

  ll t;
  cin >> t;
  while (t--)
  {
    ll x;
    cin >> x;
    cout << cd[x] << "\n";
  }
}
