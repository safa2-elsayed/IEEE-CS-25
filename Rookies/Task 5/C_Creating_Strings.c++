#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<string> uniquePermutations;
void permutations(string s, int l, int r) {
    if (l == r) {
        uniquePermutations.insert(s); 
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]); 
        permutations(s, l + 1, r); 
        swap(s[l], s[i]); 
    }
}
int main(){
    string s;
    cin>>s;

    permutations(s, 0 , s.size()-1);

    cout << uniquePermutations.size() << endl;
    for (const auto& str : uniquePermutations) {
        cout << str << endl;
    }
    return 0;
}