#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ;                      
    cin>>n;

    vector<int>arr(n);
    for(int i = 0; i < n; i++)
      cin>>arr[i];

    int N_EatenByAlice=0 , N_EatenByBOb=0 ;
    int AliceTime=0 , BobTime=0;
    int i=0 , j=n-1;
   while(i<=j){
   
   if(AliceTime<=BobTime){
       AliceTime+=arr[i++];
       N_EatenByAlice++;
   }else
      {
          BobTime+=arr[j--];
          N_EatenByBOb++;
      }
   }

   cout<<N_EatenByAlice<<" "<<N_EatenByBOb<<endl;
    return 0;
}