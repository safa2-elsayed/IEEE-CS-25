#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
      ll  n ,l ,r, Npairs=0;
      cin>>n>>l>>r;
      
      vector<ll>arr(n);
      for(int i=0 ; i<n ; i++)
          cin>>arr[i];
      
      sort(arr.begin(), arr.end()); 
      
      for(int i=0 ; i<n ; i++){
          
      int  left=lower_bound(arr.begin()+i+1, arr.end(), l- arr[i])-arr.begin();
      int   right=upper_bound(arr.begin()+i+1, arr.end(), r- arr[i])-arr.begin() ; 
        
        Npairs+=(right-left);
           
     }
       cout<<Npairs<<endl;
    }
    return 0;
}