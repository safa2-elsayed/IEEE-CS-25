#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ;                      
    cin>>n;

    vector<ll>arr(n);
    for(int i = 0; i < n; i++)
      cin>>arr[i];
      
    sort(arr.begin(),arr.end());
       int maximum= 1;
       int l=0;
    
    for(int i=0 ; i<n; i++){
        while(arr[i]-arr[l] >5)
          l++;
    
         maximum=max(maximum,i-l+1);
    }
          cout<<maximum;
    return 0;
}