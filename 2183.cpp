// https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, su = 0;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        if (a[i] > su + 1)
        {
            cout << su + 1 << "\n";
            return 0;
        }

        su += a[i];
    }

    cout << su + 1 << "\n";
    return 0;
}

// for (ll i = 0; i < n; i++)
    // {
    //     ll tmp;
    //     cin >> tmp;
    //     su += tmp;
    //     a.push_back(tmp);
    // }

    // bool pre[n + 1][su + 1];
    // for (ll i = 0; i <= n; i++)
    //     pre[i][0] = true;

    // for (ll i = 1; i <= su; i++)
    //     pre[0][i] = false;

    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= su; j++)
    //     {
    //         if (j < a[i - 1])
    //         {
    //             pre[i][j] = pre[i - 1][j];
    //         }
    //         else
    //         {
    //             pre[i][j] = pre[i - 1][j] || pre[i - 1][j - a[i - 1]];
    //         }
    //     }
    // }
    

    // for (ll i = 1; i <= su; i++)
    // {
    //     if (!pre[n][i])
    //     {
    //         cout << i << "\n";
    //         return 0;
    //     }
    // }

    // cout << su + 1 <<"\n";
    // return 0;







// ll min_sum(vector<ll> a)
// {

//     // vector<ll> li;
//     set<ll> s;
//     ll n = (1 << (a.size() + 1));

//     // cout << n << "\n";

//     for (ll i = 0; i < n; i++)
//     {
//         ll tmp = 0;

//         for (ll j = 0; j < a.size(); j++)
//             if (i & (1 << j))
//                 tmp += a[j];

//         // li.push_back(tmp);
//         // if (s.find(tmp) == s.end())
//         s.insert(tmp);
//     }

//     cout << "Debug\n";
//     for (auto x : s)
//     {
//         cout << x << "\n";
//     }
//     cout << "Debug\n";

//     // sort(li.begin(), li.end());

//     // for (ll i = 0; i < li.size(); i++)
//     //     cout << li[i] << " ";

//     // cout << "\n";

//     // ll ans = 0;

//     // for (ll i = 0; i < li.size(); i++)
//     // {
//     //     if (li[i] < ans)
//     //     {
//     //         // do nothing
//     //     }
//     //     else if (li[i] == ans)
//     //     {
//     //         ans++;
//     //     }
//     //     else 
//     //     {
//     //         return ans;
//     //     }
//     // }

//     ll sum = 1;
//     for (ll i = 0; i < a.size(); i++)
//         sum += a[i];

//     ll ans = 1;

//     for(; ans <= sum + 1; ans++)
//     {
//         if (s.find(ans) == s.end())
//         {
//             break;
//         }
//     }

//     return ans;
// }

// bool isSubsetSum(ll set[], ll n, ll sum)
// {
//     bool subset[n + 1][sum + 1];

//     for (ll i = 0; i <= n; i++)
//         subset[i][0] = true;
 
//     for (ll i = 1; i <= sum; i++)
//         subset[0][i] = false;

//     for (ll i = 1; i <= n; i++)
//     {
//         for (ll j = 1; j <= sum; j++)
//         {
//             if (j < set[i - 1])
//                 subset[i][j] = subset[i - 1][j];
    
//             if (j >= set[i - 1])
//                 subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
//         }
//     }
 
//     return subset[n][sum];
// }

// int main()
// {
//     ll n, su = 0;
//     cin >> n;
//     vector<ll> a(n);
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         su += a[i];
//     }

//     bool subset[a.size() + 1][su + 2];

//     for (ll i = 0; i <= n; i++)
//         subset[i][0] = true;
 
//     for (ll i = 1; i <= su; i++)
//         subset[0][i] = false;

//     for (ll i = 1; i <= n; i++)
//     {
//         for (ll j = 1; j <= su; j++)
//         {
//             if (j < a[i - 1])
//                 subset[i][j] = subset[i - 1][j];
    
//             if (j >= a[i - 1])
//                 subset[i][j] = subset[i - 1][j] || subset[i - 1][j - a[i - 1]];
//         }
//     }

//     for (int i = 1; i <= su + 1; i++)
//     {
//         if (!subset[a.size()][i])
//         {
//             cout << i <<"\n";
//             return 0;
//         }
//     }
    
//     cout << min_sum(a) << "\n";
// }