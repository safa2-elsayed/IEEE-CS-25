#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    ll ans= 0;
    int j = 0;
 
    for (int i = 0; i < n; i++) {
        while (j < n && arr[j] - arr[i] <= d) {
            j++;
        }
        ll countpoints = j - i - 1;
        if (countpoints >= 2) {
            ans += (countpoints * (countpoints - 1)) / 2;
        }
    }
 
    cout << ans << endl;
    return 0;
}