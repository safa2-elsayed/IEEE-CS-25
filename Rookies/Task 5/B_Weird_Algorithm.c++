#include <bits/stdc++.h>
#define ll long long
using namespace std;

void collatz(ll n){
    cout<< n;
    if(n==1) return ;
    if(n%2==0){
        cout<<" ";
        collatz(n/2);
    }else{
        cout<<" ";
        collatz(n*3+1);
    }
}
int main(){
   
   ll  n;
   cin>>n;
   collatz(n);
    return 0;
}