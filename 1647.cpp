// // https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>

#define ll int

using namespace std;

constexpr ll inf = INT_MAX;

ll n;
vector<ll> tree;

ll merge(ll x, ll y)
{
    return min(x, y);
}

void point_update(ll ind, ll a_n, ll start, ll end, ll pos = 1)
{
    if (start == end)
    {
        tree[pos] = a_n;
        return ;
    }

    ll mid = (start + end) / 2;

    if (mid >= ind)
        point_update(ind, a_n, start, mid, 2 * pos);

    else
        point_update(ind, a_n, mid + 1, end, 2 * pos + 1);

    tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
}

ll range_query(ll qstart, ll qend, ll start, ll end, ll pos = 1)
{
    if (start > qend || end < qstart || qstart > qend)
        return inf;

    else if (qstart <= start && qend >= end)
        return tree[pos];

    ll mid = (start + end) / 2;

    ll L = range_query(qstart, qend, start, mid, 2 * pos);
    ll R = range_query(qstart, qend, mid + 1, end, 2 * pos + 1);

    return merge(L, R);
}

int main()
{
    ll q;
    cin >> n >> q;

    // tree.resize(4 * n);
    tree = vector<ll> (4 * n, inf);

    // vector<ll> a(n);
    for (ll i = 1; i <= n; i++)
    {
        // cin >> a[i];

        ll tmp;
        cin >> tmp;

        point_update(i, tmp, 1, n);
    }


    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        cout << range_query(x, y, 1, n) << "\n";
    }    

    return 0;
}