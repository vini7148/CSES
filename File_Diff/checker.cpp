#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ifstream orig("orig.txt"), ne("new.txt");

    ll i = 1, err = 0;

    while (!orig.eof())
    {
        ll a, b;
        
        orig >> a;
        ne >> b;

        if (a != b)
        {
            cout << i << ": " << a << "\t" << b << "\t: Diff = " << a - b << "\n";
            err++;
        }

        i++;
    }

    cout << "\nTotal number of Errors: " << err << "\n";

    orig.close();
    ne.close();
    
    return 0;
}