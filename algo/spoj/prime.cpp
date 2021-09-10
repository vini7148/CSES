#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    vector<ll> pri;
    pri.push_back(2);

    for (int i = 3; i <= 32000; i += 2)
    {
        bool ispri = true;

        ll cp = sqrt(i) + 1;

        for (int i = 0; i < pri.size(); i++)
        {
            if (pri[i] >= cp)
                break;

            if (i % pri[i] == 0)
            {
                ispri = false;
                break;
            }
        }

        if (ispri)
            pri.push_back(i);
    }

    int t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;

        if (m < 2) 
            m = 2;

        int cap = sqrt(n) + 1;

        set<int> notpri;
        notpri.clear();

        for (int i = 0; i < pri.size(); i++)
        {
            if (pri[i] >= cap)
                break;

            ll st;

            if (pri[i] >= m)
                st = pri[i] * 2;

            else
                st = m + ((pri[i] - m % pri[i]) % pri[i]);

            for (int j = st; j <= n; j += pri[i])
            {
                notpri.insert(j);
            }
        }

        for (int i = m; i <= n; i++)
        {
            if (notpri.count(i) == 0)
                cout << i << "\n";
        }
        cout << "\n";
    }

    return 0;
}
