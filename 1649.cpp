// https://cses.fi/problemset/task/1649

#include <bits/stdc++.h>
 
#define ll int
 
using namespace std;
 
ll min(ll x, ll y)
{
    return (x < y)?x:y;
}
 
ll get_mid(ll start , ll end)
{
    return start + (end - start) / 2;
}
 
ll contutil(vector<ll> a, ll start, ll end, ll *st, ll ind)
{
    if (start == end)
    {
        st[ind] = a[start];
 
        return a[start];
    }
 
    ll mid = get_mid(start, end);
 
    st[ind] = min(contutil(a, start, mid, st, 2 * ind + 1), contutil(a, mid + 1, end, st, 2 * ind + 2));
 
    return st[ind];
}
 
ll *cont(vector<ll> a, ll n)
{
    ll x = (ll)ceil(log2(n));
 
    ll si = 2 * (ll)pow(2, x) - 1;
 
    ll *st = new ll[si];
 
    contutil(a, 0, n - 1, st, 0);
 
    return st;
}
 
ll min_valueutil(ll *st, ll start, ll end, ll qstart, ll qend, ll ind)
{
    if (qstart <= start && end <= qend)
        return st[ind];
 
    if (qstart > end || start > qend)
        return INT_MAX;
 
    ll mid = get_mid(start, end);
 
    return min(min_valueutil(st, start , mid, qstart, qend, 2 * ind + 1), min_valueutil(st, mid + 1, end, qstart, qend, 2 * ind + 2));
}
 
ll min_value(ll *st, ll n, ll qstart, ll qend)
{
    if (qstart > qend)
        return -1;
 
    return min_valueutil(st, 0, n - 1, qstart, qend, 0);
}

void update(ll *st, ll indx, ll start, ll end, ll val)
{
    
}
 
int main()
{
    ll n, q;
    cin >> n >> q;
 
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
 
    // Construct segmented tree
 
    ll *st = cont(a, n);
 
    while (q--)
    {
        ll f, x, y;
        cin >> f >> x >> y;
 
        if (f == 1)
        {
            x--;
            // update tree

            continue;
        }

        x--;
        y--;
 
        cout << min_value(st, n, x, y) << "\n";
    }    
 
    return 0;
}