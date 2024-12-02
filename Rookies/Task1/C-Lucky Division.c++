#include <bits/stdc++.h>
using namespace std;

bool islukey(int n)
{
    while(n>0)
    {
        int x =n%10;
        if(x!=4 && x!=7)
        {
            return false;
        }
        n/=10;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
{   if(islukey(i) && n%i==0){
      cout<<"YES"<<endl;
      return 0;
}
}
     cout<<"NO"<<endl;
    return 0;
}