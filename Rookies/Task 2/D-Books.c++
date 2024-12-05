#include<bits/stdc++.h>
using namespace std;
 
int main() {
      long long int n, t;
       cin >> n >> t;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
    long long sum=0;
    int count = 0;
    long long int j=0;
    for(int i=0;i<n;i++)
    {
        sum = sum + arr[i];
        if(sum<=t)
        {
            count++;
        }
        else
        {
            sum = sum - arr[j];
            j++;
        }
    }
    cout<<count<<endl;
 
 
    
    return 0;
}
 