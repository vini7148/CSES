#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, m, k;

    cin >> n >> m >> k;

    vector<ll> apt(n);
    vector<ll> pepe(m);

    for (int i = 0; i < m; i++)
        cin >> pepe[i];

    for (int i = 0; i < n; i++)
        cin >> apt[i];

    sort(apt.begin(), apt.end());
    sort(pepe.begin(), pepe.end());

    ll ans = 0;
    ll aptst = 0, pepest = 0;

    while (aptst < n || pepest < m)
    {
        if (apt[aptst] <= pepe[pepest] + k && pepe[pepest] - k <= apt[aptst])
        {
            ans++;
            aptst++;
            pepest++;
        }

        else if (apt[aptst] < pepe[pepest] - k)
        {
            aptst++;
        }

        else
        {
            pepest++;
        }
    }

    cout << ans << "\n";

    return 0;
}

