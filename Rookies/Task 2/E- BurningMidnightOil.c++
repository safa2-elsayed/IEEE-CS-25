#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int k;
    cin >> n >> k;

    ll l = 1, r = n, ans = n;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2, total = 0, temp = mid;
        while (temp > 0)
        {
            total += temp;
            temp /= k;
            if (total >= n)
                break;
        }
        if (total >= n)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;

    return 0;
}