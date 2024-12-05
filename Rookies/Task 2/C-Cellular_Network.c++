#include <bits/stdc++.h>
using namespace std;


int firstAtLeast(const vector<int> &arr, int value) {
	int l = 0, r = arr.size();
	while (l < r) {
		int mid = (l + r) / 2;
		if (arr[mid] >= value)
		r = mid;
		else 
		l = mid + 1;
	}
	return l;
}

int main() {
	int n, m;
	cin >> n >> m;
   vector<int> cities(n) ;
    vector<int> towers(m) ;
    for(int i=0 ; i<n ;i++)
        cin>>cities[i];
    for(int i=0 ; i<m ; i++)  
        cin>>towers[i];

	int minR = 0;
	for (int i = 0; i < n; i++) {
		int towerRight = firstAtLeast(towers, cities[i]);
		int towerLeft = towerRight - 1;

		int minRForThisCity = 2e9;
		if (towerRight < m) {
			assert(towers[towerRight] >= cities[i]);
			minRForThisCity =
			    min(minRForThisCity, towers[towerRight] - cities[i]);
		}
		if (towerLeft >= 0) {
			assert(towers[towerLeft] <= cities[i]);
			minRForThisCity =
			    min(minRForThisCity, cities[i] - towers[towerLeft]);
		}

		minR = max(minR, minRForThisCity);
	}

	cout << minR << endl;


    return 0;
}