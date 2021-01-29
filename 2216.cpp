// https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];

  // stack<ll> st;
  // st.push(0);
  // while (st.size() <= n)
  // {
  //   for (int i = 0; i < n; i++)
  //   {
  //     if (st.top() + 1 == a[i])
  //     {
  //       st.push(a[i]);
  //     }
  //   }
  //   ans++;
  // }
  
  unordered_map<ll, ll> ans;

  for (int i = 0; i < n; i++)
  {
    if (!ans[a[i] - 1])
    {
      ans[a[i]]++;
    }
    else
    {
      ans.erase(a[i] - 1);
      ans[a[i]]++;
    }
  }

  cout << ans.size() - 1 << "\n";
  
  return 0;
}
