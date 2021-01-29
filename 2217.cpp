// https://cses.fi/problemset/task/2217

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> a2(n);
  for (ll i = 0; i < n; i++)
    cin >> a2[i];
  
  for (int x = 0; x < q; x++)
  {
    // vector<ll> a2 = a;

    ll a, b;
    cin >> a >> b;
    ll tmp = a2[a - 1];
    a2[a - 1] = a2[b - 1];
    a2[b - 1] = tmp;

    unordered_map<ll, ll> ans;

    for (int i = 0; i < n; i++)
    {
      if (!ans[a2[i] - 1])
      {
        ans[a2[i]]++;
      }
      else
      {
        ans.erase(a2[i] - 1);
        ans[a2[i]]++;
      }
    }

    cout << ans.size() - 1<< "\n";
  }
}
