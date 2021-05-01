// https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll sum_fen(ll tree[], ll ind)
{
    ll ans = 0;

    ind ++;

    while (ind > 0)
    {
        ans += tree[ind];

        ind -= ind & (-ind);
    }

    return ans;
}

void update(ll tree[], ll n, ll ind, ll val)
{
    ind ++;

    while (ind <= n)
    {
        tree[ind] += val;

        ind += ind & (-ind);
    }
}

ll *cont(vector<ll> a, ll n)
{
    ll *tree = new ll[n + 1];

    for (ll i = 0; i <= n; i++)
        tree[i] = 0;

    for (ll i = 0; i < n; i++)
    {
        // ll tmp;
        // cin >> tmp;

        update(tree, n, i, a[i]);
    }

    return tree;
}

struct FenwickTreeOneBasedIndexing
{
    vector<ll> bit;
    ll n;

    FenwickTreeOneBasedIndexing(ll n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<ll> a): FenwickTreeOneBasedIndexing(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll idx)
    {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll sum(ll l, ll r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll *tree = cont(a, n);

    // FenwickTreeOneBasedIndexing tree(a);

    while (q--)
    {
        ll f, x, y;

        cin >> f >> x >> y;

        if (f == 1)
        {
            // update command 
            update(tree, n, x - 1, y - a[x - 1]);

            // tree.add(x - 1, y - a[x - 1]);
        }
        else
        {
            // cout << sum_fen(tree, y - 1) << "\t" << sum_fen(tree, x - 2) << "\n";
            cout << sum_fen(tree, y - 1) - sum_fen(tree, x - 2) << "\n";

            // cout << tree.sum(x + 1, y + 1) << "\n";
        }
    }

    return 0;
}