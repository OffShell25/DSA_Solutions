#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long t;

    cin >> n >> t;

    vector<long long> k(n);

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    long long low = 0;
    long long high = 1e18;

    long long ans = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long total_products = 0;
        for (int i = 0; i < n; i++)
        {
            total_products += mid / k[i];
            if (total_products >= t)
            {
                break;
            }
        }
        if (total_products >= t)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}