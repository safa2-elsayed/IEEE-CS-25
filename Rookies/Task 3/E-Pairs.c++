#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , num=0; 
    ll k;
    cin>>n>>k;

    vector<int>arr(n);
    for(int i = 0; i < n; i++)
      cin>>arr[i];
      
    sort(arr.begin(),arr.end());
      int l=0, r=1 ;
      while(r<n){
          if(abs(arr[l]-arr[r])>k){
              l++;
          }
       else if(abs(arr[l]-arr[r])==k){
             num++;
             l++; 
          }else
             r++;
      }
      cout<<num;
    return 0;
}