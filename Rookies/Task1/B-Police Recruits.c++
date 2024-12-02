#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int countremainingcrimes=0;
    int hiredofficiers=0;
    for (int i = 0; i < n; i++){
        cin >> a[i];

        if(a[i]==-1){
            if(hiredofficiers==0){
             countremainingcrimes++;
            }
            else{
            hiredofficiers--;
            
            }
        }
        if (a[i]!=-1){
        hiredofficiers+=a[i];
        }
    }
    cout<<countremainingcrimes<<endl;


    return 0;
}