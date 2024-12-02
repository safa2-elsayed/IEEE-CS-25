#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int result;

    int max = 0, min = INT_MAX;
    int maxindex, minindex = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            maxindex = i;
        }
        if (a[i] <= min)
        {
            min = a[i];
            minindex = i;
        }
    }

    if (minindex > maxindex)
    {
        result = maxindex + n - 1 - minindex;
    }
    else
        result = maxindex + n - 1 - minindex - 1;

        cout<<result<<endl;

    return 0;
}
