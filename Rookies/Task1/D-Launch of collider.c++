#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string symbols;
    cin >> symbols;

    vector<int> positions(n);
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
    int minTime = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        if (symbols[i] == 'R' && symbols[i + 1] == 'L')
        {
            int collision_Time = (positions[i + 1] - positions[i]) / 2;
            minTime = min(minTime, collision_Time);
        }
    }

    if (minTime == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
        cout << minTime << endl;

    return 0;
}