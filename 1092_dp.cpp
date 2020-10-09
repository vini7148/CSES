#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll tot = (n * (n + 1)) / 2;

    if (tot % 2 == 0)
    {
        ll W = tot / 2;

        vector<ll> list(n);

        for (ll i = 0; i < n; i++)
        {
            list[i] = i + 1;
        }

        ll k[n + 1][W + 1];

        for (ll i = 0; i <= n; i++)
        {
            for (ll w = 0; w <= W; w++)
            {
                if (i == 0 || w == 0)
                {
                    k[i][w] = 0;
                }
                else if(list[i - 1] <= w)
                {
                    k[i][w] = max(list[i - 1] + k[i - 1][w - list[i - 1]], k[i - 1][w]);
                }
                else
                {
                    k[i][w] = k[i - 1][w];
                }               
            }
        }

        ll res = k[n][W];

        if(res == tot / 2)
        {
            cout << "YES\n";
            
            vector<ll> v1;

            ll w = W; 
            for (ll i = n; i > 0 && res > 0; i--)
            {
                if (res == k[i - 1][w])  
                    continue;         
                else
                {
                    v1.push_back(list[i - 1]);
              
                    res = res - list[i - 1]; 
                    w = w - list[i - 1]; 
                }
            }

            cout << v1.size() << "\n";
            for (ll i = v1.size() - 1; i > -1; i--)
            {
                cout << v1[i] << " ";
            }

            cout << "\n" << n - v1.size() << "\n";
            for (ll i = 0; i < n; i++)
            {
                if (find(v1.begin(), v1.end(), list[i]) == v1.end())
                    cout << list[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
        
    }
    else
    {
        cout << "NO\n";
    }
}