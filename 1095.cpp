// https://cses.fi/problemset/task/1095

#include <bits/stdc++.h>

#define ll long long 
#define mod 1000000007

using namespace std;

ll po(ll a, ll b)
{
  return !b?1:po(a*a % mod, b / 2) * (b&1?a:1) % mod;
}

int main()
{
  ll n;
  cin >> n;
  while(n--)
  {
    ll a, b, ans = 1;
    cin >> a >> b;

    /*while(b--)
    {
      ans *= a;
      ans %= mod;
    }*/

    // ans = pow(a, b);
    // ans %= mod;

    ans = po(a, b);

    cout << ans << "\n";
  }
}
